/*
 * CKnight.h
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#ifndef CKNIGHT_H_
#define CKNIGHT_H_

class SDL_Surface;
class SDL_Rect;

	enum KnightRenderState
	{
		MOVING_RIGHT, MOVING_LEFT, STOPPED
	};

class CKnight
{

public:
	//functions
	void move_left();
	void move_right();
	void stop();
	bool init();
	void render(SDL_Surface * screen);
	void cleanup();

private:
	SDL_Surface * m_skin;
	SDL_Rect * m_sprite_clips;
	int m_position;
	int m_frame;
	long m_animation_timer;
	bool m_facing_right;
	KnightRenderState m_render_state;
};
#endif /* CKNIGHT_H_ */
