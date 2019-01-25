#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int rand_hight()
{
	int y_position = (rand()%(400))+20;
	return y_position;
}

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Texture* gTexture = NULL;

SDL_Texture* plattexture = NULL;

SDL_Texture* owl_texture = NULL;

SDL_Texture* wallb_texture = NULL;

SDL_Texture* wallt_texture = NULL ;

SDL_Texture* loadTexture(std::string path);

SDL_Rect platformRect;

SDL_Rect platform2Rect;

SDL_Rect wallb_rect;

SDL_Rect wallt_rect;

SDL_Rect owlRect;

bool init()
{
	bool success = true;

		gWindow = SDL_CreateWindow( "Owl Can't Sleep", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

		int imgFlags = IMG_INIT_PNG;

		SDL_Surface* gplatform =  IMG_Load( "platform.bmp");
		plattexture = SDL_CreateTextureFromSurface( gRenderer, gplatform );

		SDL_Surface* owl_platform =  IMG_Load( "owl.png");
		owl_texture = SDL_CreateTextureFromSurface( gRenderer, owl_platform );

		SDL_Surface* wall_bottom =  IMG_Load( "negartigh.png");
		wallb_texture = SDL_CreateTextureFromSurface( gRenderer, wall_bottom );

		SDL_Surface* wall_top = IMG_Load( "melikatiq.png");
		wallt_texture = SDL_CreateTextureFromSurface( gRenderer, wall_top );

		// SDL_Surface* owltexture =  IMG_Load( "owl.png");
		// owltexture = SDL_CreateTextureFromSurface( gRenderer, owltexture );
		// SDL_FreeSurface( gplatform );

		
		platformRect.x = 120;
		platformRect.y = 500;
		platformRect.w = 240;
		platformRect.h = 50;
		
		platform2Rect.x = 120;
		platform2Rect.y = rand_hight();
		platform2Rect.w = 240;
		platform2Rect.h = 50;

		owlRect.x = 190;
		owlRect.y = 390;
		owlRect.w = 100;
		owlRect.h = 150;

		wallt_rect.x = 0;
		wallt_rect.y = 610;
		wallt_rect.w = 480;
		wallt_rect.h = 30;

		wallb_rect.x = 0;
		wallb_rect.y = 0;
		wallb_rect.w = 480;
		wallb_rect.h = 30;


				

	return success;
}

bool loadMedia()
{
	bool success = true;
	gTexture = loadTexture( "sky.bmp" );
	return success;
}

void close()
{
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	SDL_DestroyRenderer( gRenderer );
	gRenderer = NULL;
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();
}
void down(int y_position)
{
	while(y_position==640)
	do{
	y_position-- ;
	}
}
SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		
	SDL_FreeSurface( loadedSurface );
	

	return newTexture;
}

int main( int argc, char* args[] )
{

	srand(time(0));

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		loadMedia();
		bool quit = false;

			//Event handler
			SDL_Event e;

			//main while 
		while( !quit )
		{		
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//SDL_RenderClear( gRenderer );
				down();
				
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				SDL_RenderCopy( gRenderer, plattexture,NULL , &platformRect );
			
				SDL_RenderCopy( gRenderer, plattexture,NULL , &platform2Rect );

				SDL_RenderCopy(gRenderer , owl_texture , NULL ,&owlRect);

				SDL_RenderCopy( gRenderer, wallb_texture, NULL , &wallb_rect);

				SDL_RenderCopy( gRenderer, wallt_texture, NULL, &wallt_rect);


				//  //Render red filled quad 
				// SDL_Rect fillRect = { 120, 500, 240, 50}; 
				// SDL_SetRenderDrawColor( gRenderer, 100, 240,50 , 255 ); 
				// SDL_RenderFillRect( gRenderer, &fillRect );
				


				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	

	//Free resources and close SDL
	close();

	return 0;
}