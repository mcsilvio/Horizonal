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

namespace constants
{
	const int KNIGHT_SPRITE_WIDTH = 64;
	const int KNIGHT_SPRITE_HEIGHT = 64;
	const int SHEET_HEIGHT = KNIGHT_SPRITE_HEIGHT * 4;

	const int MOVEMENT_SPEED = 4;

	const int SPRITE_MARGIN_TOP = 26;
}


bool CKnight::init()
{
	m_position = 0;

	m_sprite_clips = new SDL_Rect[8];

	//walking right images
	m_sprite_clips[0].x = 0;
	m_sprite_clips[0].y = 0;
	m_sprite_clips[0].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[0].h = KNIGHT_SPRITE_HEIGHT;

	m_sprite_clips[1].x = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[1].y = 0;
	m_sprite_clips[1].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[1].h = KNIGHT_SPRITE_HEIGHT;

	m_sprite_clips[2].x = KNIGHT_SPRITE_WIDTH * 2;
	m_sprite_clips[2].y = 0;
	m_sprite_clips[2].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[2].h = KNIGHT_SPRITE_HEIGHT;

	m_sprite_clips[3].x = KNIGHT_SPRITE_WIDTH * 3;
	m_sprite_clips[3].y = 0;
	m_sprite_clips[3].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[3].h = KNIGHT_SPRITE_HEIGHT;

	//walking left right images
	m_sprite_clips[4].x = KNIGHT_SPRITE_WIDTH * 3;
	m_sprite_clips[4].y = SHEET_HEIGHT;
	m_sprite_clips[4].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[4].h = KNIGHT_SPRITE_HEIGHT;

	m_sprite_clips[5].x = KNIGHT_SPRITE_WIDTH * 2;
	m_sprite_clips[5].y = SHEET_HEIGHT;
	m_sprite_clips[5].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[5].h = KNIGHT_SPRITE_HEIGHT;

	m_sprite_clips[6].x = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[6].y = SHEET_HEIGHT;
	m_sprite_clips[6].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[6].h = KNIGHT_SPRITE_HEIGHT;

	m_sprite_clips[7].x = 0;
	m_sprite_clips[7].y = SHEET_HEIGHT;
	m_sprite_clips[7].w = KNIGHT_SPRITE_WIDTH;
	m_sprite_clips[7].h = KNIGHT_SPRITE_HEIGHT;

	m_facing_right = true;

	this->m_skin = load_image("media/knightSheetFull.png", true, 0x00, 0x00, 0x00);
	return this->m_skin != 0;
}

void CKnight::stop()
{
	m_render_state = STOPPED;
}

void CKnight::move_left()
{
	if(m_render_state != MOVING_LEFT)
	{
		m_render_state = MOVING_LEFT;
		m_animation_timer = SDL_GetTicks();
		m_facing_right = false;
	}

	m_position -= MOVEMENT_SPEED;
	if (m_position < 0)
	{
		m_position += MOVEMENT_SPEED;
	}
}

void CKnight::move_right()
{
	if(m_render_state != MOVING_RIGHT)
	{
		m_render_state = MOVING_RIGHT;
		m_animation_timer = SDL_GetTicks();
		m_facing_right = true;
	}

	m_position += MOVEMENT_SPEED;
	if (m_position > SCREEN_WIDTH - TILE_WIDTH)
	{
		m_position -= MOVEMENT_SPEED;
	}
}

void CKnight::render(SDL_Surface * screen)
{
	int offset;
	if(m_facing_right)
	{
		offset = 0;
	}
	else
	{
		offset = 4;
	}

	m_frame = (SDL_GetTicks() - m_animation_timer) / 150 % 4 + offset;

	if(m_render_state == STOPPED)
	{
		m_frame = offset;
	}

	apply_surface(m_position, SPRITE_MARGIN_TOP, this->m_skin, screen, &m_sprite_clips[m_frame]);
}

void CKnight::cleanup()
{
	SDL_FreeSurface (this->m_skin);
	delete m_sprite_clips;
}
