/*
 * CLevel.h
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#ifndef CLEVEL_H_
#define CLEVEL_H_

class SDL_Surface;



class CLevel
{
public:
	int get_size();
	bool init();
	void render(SDL_Surface * screen);
	void cleanup();


private:
	SDL_Surface * m_skin;
};

#endif /* CLEVEL_H_ */
