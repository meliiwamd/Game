/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include<iostream>
#include <SDL2/SDL_image.h>

using namespace std;

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

int jumping()
{
	int V = 0;
	//if (y_position2)
}

int rand_hight()
{
	int y_position = (rand()%(300))+20;
	return y_position;
}


int dwonward(float y_position)
{
	// if()
	// {
	// 	while(y_position <= SCREEN_HEIGHT)
	// 		y_position += 20;
	// }
}

int godown(float y_position)
{
	y_position += 0.000001;
}



const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;


bool init();

bool loadMedia();

void close();

SDL_Surface* loadSurface( std::string path );

SDL_Window* gWindow = NULL;
	
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* gStretchedSurface = NULL;

SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

SDL_Surface* gCurrentSurface = NULL;

SDL_Surface* gplatformsurface = NULL;

SDL_Surface* gplatform2surface = NULL;

SDL_Surface* gowlsurface = NULL;

SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization flag
	bool success = true;
	
	{
		//Create window
		gWindow = SDL_CreateWindow( "Owl Can't Sleep", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		
	}
	int imgFlags = IMG_INIT_PNG;
	
	gplatformsurface = loadSurface ("platform.bmp");
	gplatform2surface = loadSurface ("platform.bmp");		
	gowlsurface = loadSurface ("owl.bmp");
	
	

	
	
	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gStretchedSurface = loadSurface( "sky.bmp" );
	

	return success;
}

void close()
{
	//Free loaded image
	SDL_FreeSurface( gStretchedSurface );
	gStretchedSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path )
{
	//The final optimized image
	
	SDL_Surface* optimizedSurface = NULL;
	
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load("owl.png") ;//SDL_LoadBMP( path.c_str() );
	
	
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL );
		
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	

	return optimizedSurface;
}

//gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = jumping();

int main( int argc, char* args[] )
{

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			int R = rand_hight();
			//While application is running
			while( !quit )
			{

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}


				//Apply the image stretched
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled( gStretchedSurface, NULL, gScreenSurface, &stretchRect );

				//aplly the image of platform
				SDL_Rect platformRect;
				platformRect.x = 140;
				platformRect.y = 200;
				platformRect.w = 200;
				platformRect.h = 20;
				SDL_BlitScaled( gplatformsurface, NULL, gScreenSurface, &platformRect );

				//aplly the image of platform
				SDL_Rect platform2Rect;
				platform2Rect.x = 140;
				platform2Rect.y = 540;
				platform2Rect.w = 200;
				platform2Rect.h = 20;
				SDL_BlitScaled( gplatform2surface, NULL, gScreenSurface, &platform2Rect );

				//apply the owl picture
				SDL_Rect owlRect;
				owlRect.x = 200;
				owlRect.y = 480;
				owlRect.w = 80;
				owlRect.h = 150;
				SDL_BlitScaled( gowlsurface, NULL, gScreenSurface, &owlRect );				


			
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}