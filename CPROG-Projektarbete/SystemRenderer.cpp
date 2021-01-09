#include "SystemRenderer.h"
#include <stdexcept>
#include <string>
#include "cleanup.h"

namespace engine {

	SystemRenderer::SystemRenderer() : SCREEN_H(960), SCREEN_W(1600) {
		// Check for errors at initialization of SDL
		int init_code = SDL_Init(SDL_INIT_EVERYTHING);
		if ( init_code == -1 ) {
			throw std::runtime_error(std::string("Initfel: ") + SDL_GetError());
		}

		this->sdl_win = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 960, 0);
		if ( this->sdl_win == nullptr ) {
			throw std::runtime_error(std::string("Cannot create window: ") + SDL_GetError());
		}

		this->sdl_ren = SDL_CreateRenderer(this->sdl_win, -1, 0);
		if (this->sdl_ren == nullptr) {
			throw std::runtime_error(std::string("Cannot create renderer: ") + SDL_GetError());
		}

		int music_code = Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
		if (music_code == -1){
			throw std::runtime_error(std::string("Cannot initialize audio: ") + SDL_GetError());
		}
		music = nullptr;
	}

	/// <summary>
	/// Destructor, destroys SDL resources and quits SDL.
	/// </summary>
	SystemRenderer::~SystemRenderer() {
		
		// Destroy window, renderer and music
		cleanup(this->sdl_ren, this->sdl_win, this->music);
		Mix_Quit();
		SDL_Quit();
	}

	/// <summary>
	/// Retrieves the renderer.
	/// </summary>
	/// <returns>Pointer to the renderer</returns>
	SDL_Renderer* SystemRenderer::get_ren() const {
		return this->sdl_ren;
	}

	/// <summary>
	/// Loads and plays music at selected path. If a song is already loaded it is first unloaded.
	/// </summary>
	/// <param name="music_path">Path for the music to be played. Char array.</param>
	void SystemRenderer::play_music(const char music_path[])
	{
		if (music != nullptr) {
			cleanup(this->music);
		}
		music = Mix_LoadWAV(music_path);
		Mix_PlayChannel(0, music, -1);
	}

	/// <summary>
	/// Pauses the music
	/// </summary>
	void SystemRenderer::pause_music()
	{
		if (Mix_Playing(0)) {
			Mix_Pause(0);
		}
	}

	/// <summary>
	/// Resumes the music
	/// </summary>
	void SystemRenderer::resume_music()
	{
		if (Mix_Paused(0)) {
			Mix_Resume(0);
		}
	}

	SystemRenderer sys_ren;
}
