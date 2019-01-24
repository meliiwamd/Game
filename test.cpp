#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL_ttf.h>

using namespace std;
int velocity = 0;

bool jump=false;

bool rectmovedown=false;
bool quit = false;
bool changeplatforms=false;
bool plarformdown=false;

bool gameover=false;
const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL ); 

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

SDL_Texture* mTexture;

SDL_Texture* mTexture2;

SDL_Event e;

bool up=true;



int rand_hight()
{
	int y_position = (rand()%(350))+100;
	return y_position;
}
void touching()
{
	bool touch = 0;
	if (owlRect.y <= platform2Rect.y)
	{
		touch = 1;
	}
	if(platform2Rect.y-owlRect.y-90<=velocity*(-1) && touch)
	{
		rectmovedown=true;
		velocity=0;
		owlRect.y = platform2Rect.y - 90;
	}
}

void jumping()
{
	
	if( e.type == SDL_KEYDOWN)
    {
        
        // switch( e.key.keysym.sym )
        // {
        //     case SDLK_SPACE: velocity++  ; 
        //     cout << 1 <<endl;
        //     break;

            
       // }
    	if( currentKeyStates[ SDL_SCANCODE_SPACE ] )
    	{
    		velocity ++;
    		cout << 1 << endl;
    	}
    }else if(velocity!=0) jump=true;
}
	
	int hight = 5;
	void move(){
	if(up){
		velocity-=1;
		owlRect.y-=velocity;
		if(velocity==0) up=false;
	}else{
		velocity-=1;
		owlRect.y-=velocity;
		if(!up && velocity != 0 && owlRect.y > 640 ) {
			cout << "game over";
			gameover=true;
		}
		touching();
	}
	}

void game_over()
{
		SDL_Texture* gameover_texture = NULL;

		SDL_Surface* gameoversurface =  IMG_Load( "images.bmp");

		gameover_texture = SDL_CreateTextureFromSurface( gRenderer, gameoversurface);

		SDL_Rect gameoverrect={0,0,480,640};

		SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
		SDL_RenderClear(gRenderer);
		SDL_RenderCopy( gRenderer, gameover_texture, NULL, &gameoverrect);
		SDL_RenderPresent( gRenderer );
	
}

void plarform_down()
{
	platformRect.y += 10;
	if(platformRect.y>640) 
		plarformdown=false;
}

void platform2down(){
	platform2Rect.y+=2;
	owlRect.y+=2;
	if(platform2Rect.y>=500) {
		platform2Rect.y=500;
		owlRect.y = platform2Rect.y - 90;
		changeplatforms=true;
	}

}

void switchplatforms(){
	platformRect=platform2Rect;
	owlRect.y = platformRect.y - 900;
	platform2Rect.x = 120;
	platform2Rect.y = rand_hight();
	platform2Rect.w = 240;
	platform2Rect.h = 50;
	changeplatforms=false;
	jump=false;
	rectmovedown=false;
}


void candy()
{

}
//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 640;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

void close();



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
		owlRect.y = platformRect.y-90;
		owlRect.w = 80;
		owlRect.h = 100;

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

	// TTF_CloseFont( gFont );
	// gFont = NULL;
	// TTF_Quit();


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
			

			//Event handler
			
			
			//main while 
			while( !quit )
			{

				int power = 0;

				if( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					if (e.type == SDL_KEYDOWN){
						switch(e.key.keysym.sym){
							{
							 case SDLK_UP:
							if(!jump){
					
								velocity +=2;
							}
							break;
							case SDLK_SPACE: jump=true;
							plarformdown=true;
							}
							
						 }

					}
					//else if (velocity && !jump) jump=true;
				}
				//else if(velocity && !jump)
				//		jump=true;
				







				if(!gameover){
					if(jump){
						if(!rectmovedown){
							move();
							
						}
						else{
							platform2down();
							if(changeplatforms)
								switchplatforms();
						}
				}
				cout << owlRect.y << endl;
				

				if(plarformdown) plarform_down(); 
				
				SDL_SetRenderDrawColor(gRenderer,255,255,255,255);
				
				SDL_RenderClear(gRenderer);
				
				SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

				SDL_RenderCopy( gRenderer, plattexture,NULL , &platformRect );
			
				SDL_RenderCopy( gRenderer, plattexture,NULL , &platform2Rect );

				SDL_RenderCopy(gRenderer , owl_texture , NULL ,&owlRect);

				SDL_RenderCopy( gRenderer, wallb_texture, NULL , &wallb_rect);

				SDL_RenderCopy( gRenderer, wallt_texture, NULL, &wallt_rect);

				SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, 50 }; 

				SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 255 );

				SDL_RenderFillRect( gRenderer, &fillRect );

				// SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, 0.0 , center, flip );
				
				// SDL_RenderCopyEx( gRenderer, mTexture2, clip, &renderQuad2, 0.0 , center, flip );



				
				//Update screen
				SDL_RenderPresent( gRenderer );
				SDL_Delay(50);
				}
				else{
					game_over();
				}
				
			}
		}
	

	//Free resources and close SDL
	close();

	return 0;
}