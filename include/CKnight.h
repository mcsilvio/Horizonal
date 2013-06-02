/*
 * CKnight.h
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#ifndef CKNIGHT_H_
#define CKNIGHT_H_

class SDL_Surface;

class CKnight
{
public:
	//functions
	void move_left();
	void move_right();
	bool init();
	void render(SDL_Surface * screen);
	void cleanup();

private:
	SDL_Surface * m_skin;
	int m_position;
};

#endif /* CKNIGHT_H_ */
