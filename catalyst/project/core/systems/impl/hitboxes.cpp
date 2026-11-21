#include <stdafx.hpp>

namespace systems {

    hitboxes::set hitboxes::query( std::uintptr_t game_scene_node ) const
    {
        set result{};

        const auto model_handle = g::memory.read<std::uintptr_t>( game_scene_node + g::offsets.runtime.hitbox.model_handle );
        if ( !model_handle )
        {
            return result;
        }

        const auto cmodel = g::memory.read<std::uintptr_t>( model_handle );
        if ( !cmodel )
        {
            return result;
        }

        const auto render_meshes = g::memory.read<std::uintptr_t>( g::memory.read<std::uintptr_t>( cmodel + g::offsets.runtime.hitbox.model_render_meshes ) );
        if ( !render_meshes )
        {
            return result;
        }

        const auto hitbox_data = g::memory.read<std::uintptr_t>( render_meshes + g::offsets.runtime.hitbox.render_mesh_hitbox_data );
        if ( !hitbox_data )
        {
            return result;
        }

        const auto count = g::memory.read<int>( hitbox_data + g::offsets.runtime.hitbox.hitbox_count );
        if ( count <= 0 || count > 20 )
        {
            return result;
        }

        const auto array_ptr = g::memory.read<std::uintptr_t>( hitbox_data + g::offsets.runtime.hitbox.hitbox_array );
        if ( !array_ptr )
        {
            return result;
        }

        const auto remap_count = g::memory.read<int>( cmodel + g::offsets.runtime.hitbox.remap_count );
        const auto remap_table = g::memory.read<std::uintptr_t>( cmodel + g::offsets.runtime.hitbox.remap_table );
        const auto mesh_a = g::memory.read<std::uintptr_t>( cmodel + g::offsets.runtime.hitbox.mesh_a );
        const auto mesh_b = g::memory.read<std::uintptr_t>( cmodel + g::offsets.runtime.hitbox.mesh_b );
        const auto has_remap = remap_table && mesh_a && mesh_b && remap_count > 0;

        std::array<std::int16_t, 512> remap_buf{};
        const auto remap_to_read = has_remap? std::min( remap_count, static_cast< int >( remap_buf.size( ) ) ): 0;

        if ( remap_to_read > 0 )
        {
            g::memory.read( remap_table, remap_buf.data( ), static_cast< std::size_t >( remap_to_read ) * sizeof( std::int16_t ) );
        }

        std::uint16_t ofs_a{}, ofs_b{};

        if ( has_remap )
        {
            ofs_a = g::memory.read<std::uint16_t>( mesh_a );
            ofs_b = g::memory.read<std::uint16_t>( mesh_b );
        }

        constexpr auto k_hitbox_stride{ offsets::hitbox_stride };

        std::array<std::byte, 20 * k_hitbox_stride> buffer{};
        if ( !g::memory.read( array_ptr, buffer.data( ), static_cast< std::size_t >( count ) * k_hitbox_stride ) )
        {
            return result;
        }

        for ( auto i = 0; i < count; ++i )
        {
            const auto offset = i * k_hitbox_stride;
            auto bone{ -1 };

            if ( has_remap )
            {
                const auto hb_idx = *reinterpret_cast< const std::uint16_t* >( buffer.data( ) + offset + g::offsets.runtime.hitbox.bone_index );
                const auto slot = static_cast< std::size_t >( hb_idx + ofs_a + ofs_b );

                if ( slot < static_cast< std::size_t >( remap_to_read ) )
                {
                    bone = remap_buf[ slot ];
                }
            }

            if ( bone < 0 )
            {
                continue;
            }

            const auto radius = *reinterpret_cast< const float* >( buffer.data( ) + offset + g::offsets.runtime.hitbox.radius );
            if ( radius < 0.0f || radius > 100.0f )
            {
                continue;
            }

            auto& hb = result.entries[ result.count++ ];
            hb.index = i;
            hb.bone = bone;
            hb.mins = *reinterpret_cast< const math::vector3* >( buffer.data( ) + offset + g::offsets.runtime.hitbox.mins );
            hb.maxs = *reinterpret_cast< const math::vector3* >( buffer.data( ) + offset + g::offsets.runtime.hitbox.maxs );
            hb.radius = radius;
        }

        return result;
    }

	int hitboxes::hitgroup_from_hitbox( int hitbox ) const
	{
		switch ( hitbox )
		{
		case 0:
		case 1:  return 1;
		case 2:
		case 3:  return 3;
		case 4:
		case 5:  return 2;
		case 6:  return 3;
		case 7:
		case 9:
		case 11: return 4;
		case 8:
		case 10:
		case 12: return 5;
		case 13:
		case 15:
		case 17: return 6;
		case 14:
		case 16:
		case 18: return 7;
		default: return 2;
		}
	}

} // namespace systems