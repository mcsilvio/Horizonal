#include "CSDL_helper.h"
#include <SDL/SDL_image.h>

using namespace std;
using namespace SDL_helper;

namespace SDL_helper{
SDL_Surface * load_image( string filename, bool transparent, Uint8 red, Uint8 green, Uint8 blue )
{
  //The image that's loaded
  SDL_Surface* loadedImage = NULL;

  //The optimized image that will be used
  SDL_Surface* optimizedImage = NULL;

  //Load the image
  loadedImage = IMG_Load( filename.c_str() );

  //If the image loaded
  if( loadedImage != NULL )
  {
    //Create an optimized image
    optimizedImage = SDL_DisplayFormat( loadedImage );

    if( optimizedImage != NULL )
    {
      if( transparent )
      {
	Uint32 colorkey = SDL_MapRGB( optimizedImage->format, red, green, blue );
        SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
      }
    }

    SDL_FreeSurface( loadedImage );
  }

  //Return the optimized image
  return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
  //Temporary rectangle to hold the offsets
  SDL_Rect offset;

  //Get the offsets
  offset.x = x;
  offset.y = y;

  //Blit the surface
  SDL_BlitSurface( source, NULL, destination, &offset );
}



}
