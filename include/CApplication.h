/*
 * Application.h
 *
 *  Created on: May 30, 2013
 *      Author: mcsilvio
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SDL/SDL.h>
#include "CGame_engine.h"



class CApplication
{
public:
	//functions
	int start();

private:
	//fields
	CGame_engine m_game_engine;
};

#endif /* APPLICATION_H_ */
