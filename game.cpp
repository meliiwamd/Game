<<<<<<< HEAD
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
=======

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
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
<<<<<<< HEAD

const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

bool init();

=======
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
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
bool loadMedia();

void close();

<<<<<<< HEAD
SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

SDL_Texture* gTexture = NULL;

SDL_Texture* plattexture = NULL;

SDL_Texture* owl_texture = NULL;

SDL_Texture* wallb_texture = NULL;

SDL_Texture* wallt_texture = NULL ;

SDL_Texture* loadTexture(std::string path);
=======
SDL_Texture* loadTexture( std::string path );

SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;

//DL_Surface* gplatform = NULL;

SDL_Texture* plattexture = NULL;
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d

SDL_Rect platformRect;

SDL_Rect platform2Rect;

SDL_Rect wallb_rect;

SDL_Rect wallt_rect;

<<<<<<< HEAD
SDL_Rect owlRect;

bool init()
{
	bool success = true;

		gWindow = SDL_CreateWindow( "Owl Can't Sleep", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );

=======
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

				
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
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
<<<<<<< HEAD
		owlRect.w = 100;
		owlRect.h = 150;
=======
		owlRect.w = 80;
		owlRect.h = 120;
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d

		wallt_rect.x = 0;
		wallt_rect.y = 610;
		wallt_rect.w = 480;
		wallt_rect.h = 30;

		wallb_rect.x = 0;
<<<<<<< HEAD
		wallb_rect.y = 0;
=======
		wallb_rect.y = 50;
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
		wallb_rect.w = 480;
		wallb_rect.h = 30;


				

	return success;
}

bool loadMedia()
{
<<<<<<< HEAD
	bool success = true;
	gTexture = loadTexture( "sky.bmp" );
=======
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture( "sky.bmp" );
	

>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
	return success;
}

void close()
{
<<<<<<< HEAD
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
=======
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

>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
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
<<<<<<< HEAD

=======
	//Start up SDL and create window
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
<<<<<<< HEAD
	{
		loadMedia();
		bool quit = false;
=======

	{
		loadMedia();
		
			//Main loop flag
			bool quit = false;
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d

			//Event handler
			SDL_Event e;

			//main while 
<<<<<<< HEAD
		while( !quit )
		{		
=======
			while( !quit )
			{

				
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//SDL_RenderClear( gRenderer );
<<<<<<< HEAD
				down();
=======

>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
				
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				SDL_RenderCopy( gRenderer, plattexture,NULL , &platformRect );
			
				SDL_RenderCopy( gRenderer, plattexture,NULL , &platform2Rect );

				SDL_RenderCopy(gRenderer , owl_texture , NULL ,&owlRect);

				SDL_RenderCopy( gRenderer, wallb_texture, NULL , &wallb_rect);

				SDL_RenderCopy( gRenderer, wallt_texture, NULL, &wallt_rect);

<<<<<<< HEAD
=======
				SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, 50 }; 
				SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 ); 
				SDL_RenderFillRect( gRenderer, &fillRect );


>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d

				//  //Render red filled quad 
				// SDL_Rect fillRect = { 120, 500, 240, 50}; 
				// SDL_SetRenderDrawColor( gRenderer, 100, 240,50 , 255 ); 
				// SDL_RenderFillRect( gRenderer, &fillRect );
				

<<<<<<< HEAD

=======
>>>>>>> 947ce518003dc5506db45d0d8e3ac7d9deb6237d
				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	

	//Free resources and close SDL
	close();

	return 0;
}