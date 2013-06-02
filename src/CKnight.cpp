/*
 * CKnight.cpp
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#include "CKnight.h"
#include "CSDL_helper.h"
#include "constants.h"
#include <string>
#include <SDL/SDL.h>

using namespace std;
using namespace SDL_helper;
using namespace constants;

bool CKnight::init()
{
	m_position = 0;
	this->m_skin = load_image("media/knight.png", true, 0x00, 0x00, 0x00);
	return this->m_skin != 0;
}

void CKnight::move_left()
{
	if (--m_position < 0)
	{
		m_position++;
	}
}

void CKnight::move_right()
{
	if (++m_position > LEVEL_LENGTH - 1)
	{
		m_position--;
	}
}

void CKnight::render(SDL_Surface * screen)
{
	apply_surface(TILE_WIDTH * m_position, 0, this->m_skin, screen);
}

void CKnight::cleanup()
{
	SDL_FreeSurface (this->m_skin);
}
