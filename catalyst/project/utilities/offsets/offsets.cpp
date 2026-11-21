#include <stdafx.hpp>

bool offsets::initialize( )
{
	// client.dll offsets (module-relative RVAs).
	csgo_input = g::modules.client + 0x2569E30;
	entity_list = g::modules.client + 0x2709010;
	local_player_controller = g::modules.client + 0x252B0C8;
	global_vars = g::modules.client + 0x2221AB8;
	view_matrix = g::modules.client + 0x2559640;

	if ( !g::modules.client || !csgo_input || !entity_list ||
		!local_player_controller || !global_vars || !view_matrix )
	{
		return false;
	}

	return true;
}