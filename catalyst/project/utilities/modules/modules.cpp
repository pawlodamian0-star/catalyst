#include <stdafx.hpp>

bool modules::initialize( )
{
	this->client = g::memory.get_module( "client.dll" );
	this->engine2 = g::memory.get_module( "engine2.dll" );
	this->tier0 = g::memory.get_module( "tier0.dll" );
	this->schemasystem = g::memory.get_module( "schemasystem.dll" );
	this->vphysics2 = g::memory.get_module( "vphysics2.dll" );

	if ( !this->client || !this->engine2 || !this->tier0 ||
		!this->schemasystem || !this->vphysics2 )
	{
		return false;
	}

	g::console.print( "modules initialized." );
	return true;
}
