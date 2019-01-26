#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <SDL2/SDL_ttf.h>



//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

void close();

SDL_Texture* loadTexture( std::string path );

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;

SDL_Surface* gplatform = NULL;

SDL_Texture* plattexture = NULL;

SDL_Rect platformRect;

bool init()
{
	//Initialization flag
	bool success = true;

	
	

		
		gWindow = SDL_CreateWindow( "Owl Can't Sleep", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		
			
		gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

				
		int imgFlags = IMG_INIT_PNG;

		gplatform = IMG_Load( "platform.bmp");

		plattexture = SDL_CreateTextureFromSurface( gRenderer, gplatform );
		
		SDL_FreeSurface( gplatform );

		
		platformRect.x = 120;
		platformRect.y = 500;
		platformRect.w = 240;
		platformRect.h = 50;
		



				

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture( "sky.bmp" );
	

	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture( gTexture );
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
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

TTF init ();
gFont = TTF_OpenFont("lazy.ttf",20);
gSurface = TTF_RenderText_Solid(gFont,"score :",gColor);
SDL_Surface* mtexture = SDL_CreateTextureFromSurface(gRenderer , gSurface);
SDL_FreeSurface(gSurface);
SDL_Rect renderQuad3 = {5, 5 , 20 ,20};
SDL_RenderCopyEx(gRenderer,mtexture,NULL, &renderQuad3, 0.0 , NULL ,SDL_FLIP_NONE);
SDL_DestroyTexture(mtexture);
TTF_CloseFont(gFont);
TTF_Quit;

int main( int argc, char* args[] )
{

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else

	{
		loadMedia();
		
			//Main loop flag
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

				
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
				SDL_RenderCopy( gRenderer, plattexture,NULL , &platformRect );

				 //Render red filled quad 
				SDL_Rect fillRect = { 120, 500, 240, 50}; 
				SDL_SetRenderDrawColor( gRenderer, 100, 240,50 , 255 ); 
				SDL_RenderFillRect( gRenderer, &fillRect );
				

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	

	//Free resources and close SDL
	close();

	return 0;
}