#include <stdafx.hpp>

bool offsets::initialize( )
{
	const auto client_base = g::modules.client;
	if ( !client_base )
	{
		return false;
	}

	// Confirmed client.dll RVAs already present in the repository's offset update.
	this->client.csgo_input = client_base + 0x2569E30;
	this->client.entity_list = client_base + 0x2709010;
	this->client.local_player_controller = client_base + 0x252B0C8;
	this->client.global_vars = client_base + 0x2221AB8;
	this->client.view_matrix = client_base + 0x2559640;

	// All other module globals, button globals, schema fields, and interface
	// entries remain zero until their values are checked against the target build.
	return this->client.csgo_input &&
		this->client.entity_list &&
		this->client.local_player_controller &&
		this->client.global_vars &&
		this->client.view_matrix;
}
