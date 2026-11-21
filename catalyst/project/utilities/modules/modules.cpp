#include <stdafx.hpp>

bool modules::initialize( )
{
	this->client = g::memory.get_module( "client.dll" );
	if ( !this->client )
	{
		return false;
	}

	this->engine2 = g::memory.get_module( "engine2.dll" );
	if ( !this->engine2 )
	{
		return false;
	}

	this->tier0 = g::memory.get_module( "tier0.dll" );
	if ( !this->tier0 )
	{
		return false;
	}

	this->schemasystem = g::memory.get_module( "schemasystem.dll" );
	if ( !this->schemasystem )
	{
		return false;
	}

	this->vphysics2 = g::memory.get_module( "vphysics2.dll" );
	if ( !this->vphysics2 )
	{
		return false;
	}


	// Additional modules used by the supplied interface offset table.
	this->inputsystem = g::memory.get_module( "inputsystem.dll" );
	this->matchmaking = g::memory.get_module( "matchmaking.dll" );
	this->soundsystem = g::memory.get_module( "soundsystem.dll" );
	this->animationsystem = g::memory.get_module( "animationsystem.dll" );
	this->filesystem_stdio = g::memory.get_module( "filesystem_stdio.dll" );
	this->host = g::memory.get_module( "host.dll" );
	this->imemanager = g::memory.get_module( "imemanager.dll" );
	this->localize = g::memory.get_module( "localize.dll" );
	this->materialsystem2 = g::memory.get_module( "materialsystem2.dll" );
	this->meshsystem = g::memory.get_module( "meshsystem.dll" );
	this->navsystem = g::memory.get_module( "navsystem.dll" );
	this->networksystem = g::memory.get_module( "networksystem.dll" );
	this->panorama = g::memory.get_module( "panorama.dll" );
	this->panorama_text_pango = g::memory.get_module( "panorama_text_pango.dll" );
	this->panoramauiclient = g::memory.get_module( "panoramauiclient.dll" );
	this->particles = g::memory.get_module( "particles.dll" );
	this->pulse_system = g::memory.get_module( "pulse_system.dll" );
	this->rendersystemdx11 = g::memory.get_module( "rendersystemdx11.dll" );
	this->resourcesystem = g::memory.get_module( "resourcesystem.dll" );
	this->scenefilecache = g::memory.get_module( "scenefilecache.dll" );
	this->scenesystem = g::memory.get_module( "scenesystem.dll" );
	this->server = g::memory.get_module( "server.dll" );
	this->steamaudio = g::memory.get_module( "steamaudio.dll" );
	this->v8system = g::memory.get_module( "v8system.dll" );
	this->vscript = g::memory.get_module( "vscript.dll" );
	this->worldrenderer = g::memory.get_module( "worldrenderer.dll" );

	g::console.print( "modules initialized." );

	return true;
}