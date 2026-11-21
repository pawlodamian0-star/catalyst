#pragma once

class offsets
{
public:
	bool initialize( );

	// Absolute addresses resolved from module-relative RVAs in initialize().
	// The five values below are the only game-build RVAs currently confirmed
	// by the existing project change.
	struct client_t {
		std::uintptr_t csgo_input{}, entity_list{}, local_player_controller{};
		std::uintptr_t global_vars{}, view_matrix{};
		// Unconfirmed RVAs are intentionally left zero until sourced.
		std::uintptr_t game_entity_system{}, game_entity_system_highest_entity_index{};
		std::uintptr_t game_rules{}, glow_manager{}, local_player_pawn{};
		std::uintptr_t planted_c4{}, prediction{}, view_angles{}, view_render{}, weapon_c4{};
	} client;

	struct engine2_t {
		std::uintptr_t build_number{}, network_game_client{};
		std::uintptr_t network_game_client_client_tick_count{}, network_game_client_delta_tick{};
		std::uintptr_t network_game_client_is_background_map{}, network_game_client_local_player{};
		std::uintptr_t network_game_client_max_clients{}, network_game_client_server_tick_count{};
		std::uintptr_t network_game_client_sign_on_state{}, window_height{}, window_width{};
	} engine2;

	struct inputsystem_t { std::uintptr_t input_system{}; } inputsystem;
	struct matchmaking_t { std::uintptr_t game_types{}; } matchmaking;
	struct soundsystem_t { std::uintptr_t sound_system{}; } soundsystem;

	// Button globals are kept zero until verified for the target game build.
	struct buttons_t {
		std::uintptr_t attack{}, attack2{}, back{}, duck{}, forward{}, jump{}, left{}, lookatweapon{};
		std::uintptr_t reload{}, right{}, showscores{}, sprint{}, turnleft{}, turnright{}, use{}, zoom{};
	} buttons;

	// Runtime object/layout offsets copied from existing reads in this codebase.
	// These are structure offsets, not module RVAs.
	struct runtime_t {
		struct global_vars_t { std::uintptr_t current_time{0x30}, map_name{0x188}; } global_vars;
		struct entity_list_t {
			std::uintptr_t chunk_table{0x10}, chunk_pointer_stride{8}, entry_stride{112};
			std::uintptr_t handle_index_mask{0x1ff}, handle_chunk_mask{0x7fff}, chunk_shift{9};
		} entity_list;
		struct entity_identity_t { std::uintptr_t identity{0x10}, class_info{0x8}, name_container{0x8}, schema_name{0x8}; } entity_identity;
		struct schema_system_t {
			std::uintptr_t field_count{0x24}, fields{0x30}, field_stride{0x20}, field_offset{0x10};
			std::uintptr_t scope_count{0x190}, scope_data{0x198}, scope_name{0x8};
			std::uintptr_t scope_buckets{0x5c0}, bucket_stride{24}, bucket_first_uncommitted{16};
			std::uintptr_t element_key{0}, element_next{8}, element_data{16};
		} schema_system;
		struct hitbox_t {
			std::uintptr_t model_handle{0x200}, model_render_meshes{0x78}, render_mesh_hitbox_data{0x168};
			std::uintptr_t hitbox_count{0x28}, hitbox_array{0x30}, remap_count{0x220}, remap_table{0x228};
			std::uintptr_t mesh_a{0x240}, mesh_b{0x2f0}, stride{0x70}, bone_index{0x48};
			std::uintptr_t radius{0x30}, mins{0x18}, maxs{0x24};
		} hitbox;
		struct view_t { std::uintptr_t camera{0x10}, origin{0}, angles{0xc}, fov{0x18}; } view;
		std::uintptr_t subclass_vdata{0x8}, model_state_bone_cache{0x80};
	} runtime;
};
