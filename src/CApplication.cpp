/*
 * Application.cpp
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#include "CApplication.h"

#include "constants.h"
using namespace constants;

namespace constants
{
bool g_game_running = true;
}

int loops = 0;
int CApplication::start()
{
	g_game_running = true;

	//Initialize
	if (m_game_engine.init_game() == false)
	{
		printf("bad init_game\n");
		return 1;
	}

	//Load the files
	if (m_game_engine.load_game() == false)
	{
		printf("bad load files\n");
		return 1;
	}

	Uint32 next_game_tick = SDL_GetTicks();
	//While the user hasn't quit
	while (g_game_running)
	{
		//printf("1\n");
		loops = 0;
		while (SDL_GetTicks() > next_game_tick && loops < constants::MAX_FRAMESKIP)
		{
			//printf("2\n");
			m_game_engine.handle_events();
			m_game_engine.update();

			next_game_tick += SKIP_TICKS;
			loops++;
		}

		m_game_engine.render();
	}

	//Free the surface and quit SDL
	m_game_engine.cleanup_game();

	return 0;
}

int main(int argc, char* args[])
{
	CApplication game;
	return game.start();
}

