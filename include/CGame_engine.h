/*
 * CGame_engine.h
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#ifndef CGAME_ENGINE_H_
#define CGAME_ENGINE_H_

#include <SDL/SDL.h>



class CLevel;
class CKnight;

struct SGame_data
{
	CLevel * cave;
	CKnight * knight;
};

class CGame_engine
{
public:

	CGame_engine();
	virtual ~CGame_engine();

	bool init_game();
	bool load_game();
	void handle_events();
	void update();
	void render();
	void cleanup_game();

private:
	SDL_Event m_event;
	SDL_Surface * m_screen;
	SGame_data m_game_data;

};

#endif /* CGAME_ENGINE_H_ */
