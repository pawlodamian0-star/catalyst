#pragma once

class modules
{
public:
	bool initialize( );

	std::uintptr_t client{ 0 };
	std::uintptr_t engine2{ 0 };
	std::uintptr_t tier0{ 0 };
	std::uintptr_t schemasystem{ 0 };
	std::uintptr_t vphysics2{ 0 };
	std::uintptr_t inputsystem{ 0 };
	std::uintptr_t matchmaking{ 0 };
	std::uintptr_t soundsystem{ 0 };
	std::uintptr_t animationsystem{ 0 };
	std::uintptr_t filesystem_stdio{ 0 };
	std::uintptr_t host{ 0 };
	std::uintptr_t imemanager{ 0 };
	std::uintptr_t localize{ 0 };
	std::uintptr_t materialsystem2{ 0 };
	std::uintptr_t meshsystem{ 0 };
	std::uintptr_t navsystem{ 0 };
	std::uintptr_t networksystem{ 0 };
	std::uintptr_t panorama{ 0 };
	std::uintptr_t panorama_text_pango{ 0 };
	std::uintptr_t panoramauiclient{ 0 };
	std::uintptr_t particles{ 0 };
	std::uintptr_t pulse_system{ 0 };
	std::uintptr_t rendersystemdx11{ 0 };
	std::uintptr_t resourcesystem{ 0 };
	std::uintptr_t scenefilecache{ 0 };
	std::uintptr_t scenesystem{ 0 };
	std::uintptr_t server{ 0 };
	std::uintptr_t steamaudio{ 0 };
	std::uintptr_t v8system{ 0 };
	std::uintptr_t vscript{ 0 };
	std::uintptr_t worldrenderer{ 0 };
};
