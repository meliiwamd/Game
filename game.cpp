#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
// void plarform_down()
// {
// 	if(owlRect.y != platformRect.y-110)
// 	{
// 		while(platformRect.y <= 640)
// 			platformRect.y -=10;
// 	}

// }

// int rand_hight()
// {
// 	int y_position = (rand()%(400))+50;
// 	return y_position;
// }

// void jumping()
// {
// 	int velocity = 0;
// 	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
//     {
        
//         switch( e.key.keysym.sym )
//         {
//             case SDLK_SPACE: velocity++  ; break;
            
//         }
//     }
	
// 	int hight = 5;
	
// 	platfor_down();
// 	while(owlRect.y <= hight*v)
// 	{
// 		owlRect.y +=5;
// 	}
// 	touching();
// 	if(owlRect.y == hight*v )
// 	{
// 		while(owlRect.y >= platform2Rect.y)
// 		{
// 			owlRect.y -=5;
// 		}
// 	}




// }

// void touching()
// {
// 	bool touch = 0;
// 	if (owlRect.y == platform2Rect.y)
// 	{
// 		touch == 1;
// 	}
// 	if(owlRect.y == platform2Rect.y && touch)
// 	{
// 		owlRect.y = platform2Rect - 110;
// 	}
// }


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

//DL_Surface* gplatform = NULL;

SDL_Texture* plattexture = NULL;

SDL_Rect platformRect;

SDL_Rect platform2Rect;

SDL_Rect wallb_rect;

SDL_Rect wallt_rect;

SDL_Texture* owl_texture = NULL;

SDL_Texture* wallb_texture = NULL;

SDL_Texture* wallt_texture = NULL;

SDL_Rect owlRect;
bool init()
{
	//Initialization flag
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
		owlRect.w = 80;
		owlRect.h = 120;

		wallt_rect.x = 0;
		wallt_rect.y = 610;
		wallt_rect.w = 480;
		wallt_rect.h = 30;

		wallb_rect.x = 0;
		wallb_rect.y = 50;
		wallb_rect.w = 480;
		wallb_rect.h = 30;


				

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

int main( int argc, char* args[] )
{

	srand(time(0));
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
			
				SDL_RenderCopy( gRenderer, plattexture,NULL , &platform2Rect );

				SDL_RenderCopy(gRenderer , owl_texture , NULL ,&owlRect);

				SDL_RenderCopy( gRenderer, wallb_texture, NULL , &wallb_rect);

				SDL_RenderCopy( gRenderer, wallt_texture, NULL, &wallt_rect);

				SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, 50 }; 
				SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 ); 
				SDL_RenderFillRect( gRenderer, &fillRect );



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