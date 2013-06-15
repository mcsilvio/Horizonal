/*
 * CGame_engine.cpp
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#include "CGame_engine.h"
#include "CKnight.h"
#include "CLevel.h"


#include "constants.h"
using namespace constants;



namespace constants{
//screen attributes
const int SCREEN_WIDTH = TILE_WIDTH * LEVEL_LENGTH;
const int SCREEN_HEIGHT = TILE_HEIGHT;
const int SCREEN_BPP = 32;

//speed attributes
const int TICKS_PER_SECOND = 50;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 10;


extern bool g_game_running;
}


CGame_engine::CGame_engine()
{
	m_game_data.knight = new CKnight();
	m_game_data.cave = new CLevel();

}

CGame_engine::~CGame_engine()
{
	delete m_game_data.knight;
	delete m_game_data.cave;
}

bool CGame_engine::init_game( )
{
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	//Set up the screen
	this->m_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_NOFRAME);

	//If there was an error in setting up the screen
	if (this->m_screen == NULL)
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption("Horizonal", NULL);

	//If everything initialized fine
	return true;
}

void CGame_engine::cleanup_game()
{
	//Free the surfaces
	m_game_data.knight->cleanup();
	m_game_data.cave->cleanup();

	//Quit SDL
	SDL_Quit();
}

bool CGame_engine::load_game()
{
	//initialize the objects
	if (  m_game_data.cave->init() == false ||
			m_game_data.knight->init() == false )
	{
		return false;
	}

	//If everything loaded fine
	return true;
}

void CGame_engine::handle_events()
{
	//continuous keys
	Uint8* keystate = SDL_GetKeyState(NULL);

	    //continuous-response keys
	    if(keystate[SDLK_LEFT])
	    {
			m_game_data.knight->move_left();
	    }
	    else if(keystate[SDLK_RIGHT])
	    {
			m_game_data.knight->move_right();
	    }
	    else
	    {
	    	m_game_data.knight->stop();
	    }



	//single press keys
		while (SDL_PollEvent(&m_event))
		{
			//If the user has Xed out the window
			switch (m_event.type)
			{
			case SDL_QUIT:
				g_game_running = false;
				break;
			case SDL_KEYDOWN:
				SDLKey keyPressed = m_event.key.keysym.sym;
				switch (keyPressed)
				{
				case SDLK_q:
					g_game_running = false;
					break;
				default:
					break;
				}
				break;
			}

		}
}

void CGame_engine::update()
{


}

void CGame_engine::render()
{
	SDL_FillRect(this->m_screen, &this->m_screen->clip_rect, SDL_MapRGB(this->m_screen->format, 0x00, 0x00, 0x00));

	m_game_data.knight->render(this->m_screen);

	m_game_data.cave->render(this->m_screen);

	//Update Screen
	SDL_Flip(this->m_screen);
}


