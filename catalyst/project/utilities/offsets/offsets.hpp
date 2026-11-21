#pragma once

class offsets
{
public:
	bool initialize( );

	// Backward-compatible aliases used by the existing project code.
	std::uintptr_t csgo_input{ 0 }, entity_list{ 0 }, local_player_controller{ 0 };
	std::uintptr_t global_vars{ 0 }, view_matrix{ 0 };

	// Module-relative global offsets.
	struct client_t {
		std::uintptr_t csgo_input{}, entity_list{}, game_entity_system{}, game_entity_system_highest_entity_index{};
		std::uintptr_t game_rules{}, global_vars{}, glow_manager{}, local_player_controller{}, local_player_pawn{};
		std::uintptr_t planted_c4{}, prediction{}, view_angles{}, view_matrix{}, view_render{}, weapon_c4{};
	} client;
	struct engine2_t {
		std::uintptr_t build_number{}, network_game_client{}, network_game_client_client_tick_count{};
		std::uintptr_t network_game_client_delta_tick{}, network_game_client_is_background_map{};
		std::uintptr_t network_game_client_local_player{}, network_game_client_max_clients{};
		std::uintptr_t network_game_client_server_tick_count{}, network_game_client_sign_on_state{};
		std::uintptr_t window_height{}, window_width{};
	} engine2;
	struct inputsystem_t { std::uintptr_t input_system{}; } inputsystem;
	struct matchmaking_t { std::uintptr_t game_types{}; } matchmaking;
	struct soundsystem_t { std::uintptr_t sound_system{}; } soundsystem;

	// client.dll input button offsets.
	struct buttons_t {
		std::uintptr_t attack{}, attack2{}, back{}, duck{}, forward{}, jump{}, left{}, lookatweapon{};
		std::uintptr_t reload{}, right{}, showscores{}, sprint{}, turnleft{}, turnright{}, use{}, zoom{};
	} buttons;

	// Frequently used client schema field offsets (object-relative, not module RVAs).
	struct schema_t {
		struct base_entity_t {
			std::uintptr_t game_scene_node{0x330}, health{0x34C}, max_health{0x348}, life_state{0x354};
			std::uintptr_t team_num{0x3E7}, flags{0x3F4}, velocity{0x430}, simulation_time{0x3B8};
			std::uintptr_t owner_entity{0x520}, collision{0x340}, effects{0x52C}, ground_entity{0x530};
		} base_entity;
		struct game_scene_node_t {
			std::uintptr_t abs_rotation{0xD4}, rotation{0xB8}, parent{0x38}, child{0x40}, next_sibling{0x48};
			std::uintptr_t owner{0x30}, node_to_world{0x10}, abs_origin{0xC8}, origin{0x80};
		} game_scene_node;
		struct skeleton_instance_t { std::uintptr_t model_state{0x140}, hitbox_set{0x3FC}; } skeleton_instance;
		struct base_player_pawn_t {
			std::uintptr_t view_angle{0x13A8}, view_angle_previous{0x13B4}, camera_services{0x1328};
			std::uintptr_t weapon_services{0x12F0}, item_services{0x12F8}, movement_services{0x1330};
		} base_player_pawn;
		struct cs_player_pawn_t {
			std::uintptr_t armor{0x1F00}, eye_angles{0x3630}, scoped{0x1ED0}, defusing{0x1ED2};
			std::uintptr_t shots_fired{0x1EE8}, spotted_state{0x1EB8}, spotted{0x1EC0};
			std::uintptr_t id_entity_index{0x370C}, weapon_services{0x1570}, glow_services{0x1588};
		} cs_player_pawn;
		struct player_controller_t {
			std::uintptr_t pawn{0x6BC}, tick_base{0x6B8}, player_name{0x6FC}, steam_id{0x788};
			std::uintptr_t local_controller{0x790}, connected{0x6F4};
		} player_controller;
		struct cs_player_controller_t {
			std::uintptr_t player_pawn{0x92C}, observer_pawn{0x930}, sanitized_name{0x878};
			std::uintptr_t pawn_health{0x938}, pawn_armor{0x93C}, pawn_alive{0x934};
			std::uintptr_t ping{0x838}, competitive_rank{0x8A0}, money_services{0x818};
		} cs_player_controller;
		struct weapon_services_t { std::uintptr_t active_weapon{0x60}, last_weapon{0x64}, my_weapons{0x48}, ammo{0x68}; } weapon_services;
		struct observer_services_t { std::uintptr_t observer_target{0x4C}, observer_mode{0x48}, last_mode{0x50}; } observer_services;
		struct camera_services_t { std::uintptr_t punch_angle{0x48}, punch_tick{0x54}, demo_view_angles{0x208}; } camera_services;
		struct spotted_state_t { std::uintptr_t spotted{0x8}, spotted_by_mask{0xC}; } spotted_state;
		struct planted_c4_t {
			std::uintptr_t ticking{0x1288}, blow_time{0x12B8}, defuse_countdown{0x12D8};
			std::uintptr_t being_defused{0x12C4}, bomb_defused{0x12DC}, defuser{0x12E0}, bomb_site{0x128C};
		} planted_c4;
		struct cs_game_rules_t {
			std::uintptr_t freeze_period{0x40}, warmup_period{0x41}, bomb_planted{0x8C7}, bomb_dropped{0x9A8};
			std::uintptr_t round_start_time{0x70}, round_time{0x68}, total_rounds_played{0x88};
		} game_rules;
	} schema;

	// Interface offsets, grouped by owning module.
	struct interfaces_t {
		struct animationsystem_t { std::uintptr_t utils{0x83F6D8}, system{0x8375F8}; } animationsystem;
		struct client_t {
			std::uintptr_t bug_bug_service{0x2225110}, tools_info{0x22250E0}, empty_world_service{0x2208E20};
			std::uintptr_t game_client_exports{0x2221D88}, legacy_game_ui{0x2231AC0}, source2_client{0x254D9F0};
			std::uintptr_t source2_client_config{0x24AA330}, source2_client_prediction{0x2553C40}, source2_client_ui{0x2230220};
		} client;
		struct engine2_t {
			std::uintptr_t benchmark{0x6B89D0}, bug_bug{0x6B8AD0}, bug{0x970360}, client_server_loop{0x9B1D80};
			std::uintptr_t shared_handle_system{0x9B1370}, game_ui{0x6B6430}, service_manager{0x9B1620};
			std::uintptr_t event_system_client{0x9B1910}, event_system_server{0x9B1A40};
			std::uintptr_t resource_service_client{0x6B8B10}, resource_service_server{0x6B8B70};
			std::uintptr_t game_ui_service{0x9707B0}, host_state_manager{0x6B8FB0}, inet_support{0x6B1980};
			std::uintptr_t input_service{0x970A90}, key_value_cache{0x6B9060}, map_list_service{0x9AF900};
			std::uintptr_t network_client{0x9AFA90}, network_p2p{0x9AFDD0}, network_server{0x9AFF80};
			std::uintptr_t network_service{0x6B8CE0}, render_service{0x9B01F0}, screenshot_service{0x9B04C0};
			std::uintptr_t simple_engine_loop{0x6B90C0}, sound_service{0x9B0670}, engine_to_client{0x6B5D40};
			std::uintptr_t engine_to_client_string_table{0x6B5DA0}, engine_to_server{0x6B5E18};
			std::uintptr_t engine_to_server_string_table{0x6B5E40}, split_screen{0x6B8D20}, stats{0x9B0BB0};
			std::uintptr_t tool_service{0x6B8E20}, game_ui_funcs{0x6B64C0}, vprof{0x6B8E60};
		} engine2;
		struct filesystem_t { std::uintptr_t async_filesystem{0x214610}, filesystem{0x2143D0}; } filesystem;
		struct host_t {
			std::uintptr_t debug_draw{0x13FF70}, model_info{0x13FFB0}, game_system{0x13FFF0}, host_utils{0x14F900};
			std::uintptr_t prediction_diff{0x140100}, save_restore{0x140230}, shared_memory{0x140260}, source2_host{0x1402D0};
		} host;
		struct inputsystem_t { std::uintptr_t input_stack{0x44E90}, input_system{0x46BC0}; } inputsystem;
		struct matchmaking_t { std::uintptr_t game_types{0x1AEFC0}, match_framework{0x1B7080}; } matchmaking;
		struct materialsystem2_t {
			std::uintptr_t font_manager{0x1638E0}, material_utils{0x14BD30}, post_processing{0x14BC60};
			std::uintptr_t text_layout{0x14BCC0}, material_system{0x163530};
		} materialsystem2;
		struct networksystem_t {
			std::uintptr_t flattened_serializers{0x272A30}, network_messages{0x29EE00};
			std::uintptr_t network_system{0x28C450}, serialized_entities{0x28C530};
		} networksystem;
		struct panorama_t { std::uintptr_t ui_engine{0x5895F0}; } panorama;
		struct panoramaclient_t { std::uintptr_t ui_client{0x270710}; } panoramaclient;
		struct particles_t { std::uintptr_t manager{0x65AEE0}; } particles;
		struct pulse_t { std::uintptr_t system{0x238120}; } pulse;
		struct rendersystem_t { std::uintptr_t device_manager{0x4342F0}, render_utils{0x434BD0}, device_backdoor{0x434390}; } rendersystem;
		struct resourcesystem_t { std::uintptr_t resource_system{0x89230}; } resourcesystem;
		struct scenesystem_t { std::uintptr_t pipelines{0x675A00}, scene_system{0x91FB20}, scene_utils{0x676760}; } scenesystem;
		struct schemasystem_t { std::uintptr_t schema_system{0x76710}; } schemasystem;
		struct server_t {
			std::uintptr_t empty_world{0x1DF2E10}, subclass_utils{0x1DA2B40}, nav_game_test{0x1E3A808};
			std::uintptr_t tools_info{0x1E19738}, game_clients{0x1E18C60}, game_director{0x1F7F820};
			std::uintptr_t game_entities{0x1E18EE0}, source2_server{0x1E18D20}, server_config{0x20FB328};
			std::uintptr_t custom_nav{0x1D904A8};
		} server;
		struct soundsystem_t { std::uintptr_t bug_bug{0x532C90}, op_system{0x532B70}, op_system_edit{0x532A80}, sound_system{0x532470}, vmix_edit{0x5941BBF}; } soundsystem;
		struct tier0_t { std::uintptr_t test_script{0x3A1960}, cvar{0x3AC670}, process_utils{0x3A1820}, string_tokens{0x3D3300}; } tier0;
		struct vphysics2_t { std::uintptr_t physics{0x460E60}; } vphysics2;
		struct vscript_t { std::uintptr_t manager{0x13E430}; } vscript;
		struct worldrenderer_t { std::uintptr_t manager{0x236D40}; } worldrenderer;
	} interfaces;
};
