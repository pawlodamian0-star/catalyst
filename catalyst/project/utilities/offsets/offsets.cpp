#include <stdafx.hpp>

bool offsets::initialize( )
{
	// Module-relative globals are stored as absolute addresses.
	const auto client_base = g::modules.client;
	const auto engine_base = g::modules.engine2;
	const auto input_base = g::modules.inputsystem;
	const auto matchmaking_base = g::modules.matchmaking;
	const auto sound_base = g::modules.soundsystem;

	if ( !client_base || !engine_base )
	{
		return false;
	}

	this->client.csgo_input = client_base + 0x2569E30;
	this->client.entity_list = client_base + 0x2709010;
	this->client.game_entity_system = client_base + 0x2709010;
	this->client.game_entity_system_highest_entity_index = 0x2120;
	this->client.game_rules = client_base + 0x25537E8;
	this->client.global_vars = client_base + 0x2221AB8;
	this->client.glow_manager = client_base + 0x2550500;
	this->client.local_player_controller = client_base + 0x252B0C8;
	this->client.local_player_pawn = client_base + 0x2553D38;
	this->client.planted_c4 = client_base + 0x24B9B90;
	this->client.prediction = client_base + 0x2553C40;
	this->client.view_angles = client_base + 0x256A4B8;
	this->client.view_matrix = client_base + 0x2559640;
	this->client.view_render = client_base + 0x255A008;
	this->client.weapon_c4 = client_base + 0x24B83B0;

	this->engine2.build_number = engine_base + 0x6B2D18;
	this->engine2.network_game_client = engine_base + 0x9AFB30;
	this->engine2.network_game_client_client_tick_count = 0x398;
	this->engine2.network_game_client_delta_tick = 0x24C;
	this->engine2.network_game_client_is_background_map = 0x2C143F;
	this->engine2.network_game_client_local_player = 0xF8;
	this->engine2.network_game_client_max_clients = 0x240;
	this->engine2.network_game_client_server_tick_count = 0x24C;
	this->engine2.network_game_client_sign_on_state = 0x230;
	this->engine2.window_height = engine_base + 0x9B4294;
	this->engine2.window_width = engine_base + 0x9B4290;

	this->inputsystem.input_system = input_base ? input_base + 0x46BC0 : 0;
	this->matchmaking.game_types = matchmaking_base ? matchmaking_base + 0x1AEFC0 : 0;
	this->soundsystem.sound_system = sound_base ? sound_base + 0x532470 : 0;

	this->buttons.attack = client_base + 0x2225900;
	this->buttons.attack2 = client_base + 0x2225990;
	this->buttons.back = client_base + 0x2225BD0;
	this->buttons.duck = client_base + 0x2225EA0;
	this->buttons.forward = client_base + 0x2225B40;
	this->buttons.jump = client_base + 0x2225E10;
	this->buttons.left = client_base + 0x2225C60;
	this->buttons.lookatweapon = client_base + 0x2569D50;
	this->buttons.reload = client_base + 0x2225870;
	this->buttons.right = client_base + 0x2225CF0;
	this->buttons.showscores = client_base + 0x2569C30;
	this->buttons.sprint = client_base + 0x22257E0;
	this->buttons.turnleft = client_base + 0x2225A20;
	this->buttons.turnright = client_base + 0x2225AB0;
	this->buttons.use = client_base + 0x2225D80;
	this->buttons.zoom = client_base + 0x2569CC0;

	// Keep the original flat members synchronized for existing call sites.
	this->csgo_input = this->client.csgo_input;
	this->entity_list = this->client.entity_list;
	this->local_player_controller = this->client.local_player_controller;
	this->global_vars = this->client.global_vars;
	this->view_matrix = this->client.view_matrix;

	// Interface table entries remain module-relative RVAs; add the owning module
	// base at the call site when resolving an interface entry.
	return this->client.csgo_input && this->client.entity_list &&
		this->client.local_player_controller && this->client.global_vars &&
		this->client.view_matrix;
}
