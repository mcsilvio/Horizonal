#ifndef SDL_HELPER
#define SDL_HELPER

#include <string>
#include <SDL/SDL.h>
using namespace std;

using namespace std;

namespace SDL_helper
{
extern SDL_Surface * load_image(string filename, bool transparent, Uint8 red,
		Uint8 green, Uint8 blue);
extern void apply_surface(int x, int y, SDL_Surface* source,
		SDL_Surface* destination);

}

#endif
