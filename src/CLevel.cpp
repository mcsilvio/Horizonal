/*
 * CLevel.cpp
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#include "CLevel.h"
#include "CSDL_helper.h"
#include "constants.h"
#include <SDL/SDL.h>
#include <string>

using namespace std;
using namespace constants;
using namespace SDL_helper;

namespace constants
{
	const int TILE_WIDTH = 60;
	const int TILE_HEIGHT = 100;
	const int LEVEL_LENGTH = 20;
}

bool CLevel::init()
{
	this->m_skin = load_image("media/cave.png", true, 0x00, 0x00, 0x00);
	return this->m_skin != 0;
}

void CLevel::render(SDL_Surface * screen)
{
	int i;
	for (i = 0; i < LEVEL_LENGTH; i++)
	{
		//printf("!!!%d!!!\n", SCREEN_WIDTH);
		apply_surface(TILE_WIDTH * i, 0, this->m_skin, screen, NULL);
	}
}

void CLevel::cleanup()
{
	SDL_FreeSurface(this->m_skin);
}
