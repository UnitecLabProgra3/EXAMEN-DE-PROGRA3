/*This source code copyrighted by Lazy Foo' Productions (4-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include <vector>
#include "Personaje.h"
#include "Enemygo.h"
#include "Fantasmita.h"
#include "bomba.h"
#include "Mina.h"
#include "Cocodrilo.h"
#include "SDL_mixer.h"
//using namespace std;

//Screen attributes
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *up = NULL;
SDL_Surface *down = NULL;
SDL_Surface *left = NULL;
SDL_Surface *right = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

SDL_Surface *load_image( std::string filename )
{
    return IMG_Load( filename.c_str() );
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Press an Arrow Key", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "Menu/Menu.png" );

    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 72 );

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( up );
    SDL_FreeSurface( down );
    SDL_FreeSurface( left );
    SDL_FreeSurface( right );

    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    Personaje *personaje=new Personaje(0 ,0);
    SDL_Surface* meta=load_image("meta.png");
    SDL_Surface* victoria=load_image("victoria.png");
    SDL_Surface* game_over=load_image("Endless Run/game over.png");
    SDL_Surface* Fondo=load_image("fondo.png");
    SDL_Surface* instrucciones=load_image("Menu/instrucciones.png");
    SDL_Surface* botonPlay=load_image("Menu/botonPlay.png");
    SDL_Surface* botonSalir=load_image("Menu/botonSalir.png");
    SDL_Surface* botonIntrucciones=load_image("Menu/botonIntrucciones.png");
    SDL_Surface* seleccionPlay=load_image("Menu/seleccionPlay.png");
    SDL_Surface* seleccionSalir=load_image("Menu/seleccionSalir.png");
    SDL_Surface* Menu=load_image("Menu/Menu.png");
    SDL_Surface* selecionIntrucciones=load_image("Menu/selecionIntrucciones.png");
    std::vector<Enemygo*>enemigos;
    enemigos.push_back(new Fantasmita(personaje));
    enemigos.push_back(new bomba(personaje));
    enemigos.push_back(new Cocodrilo(personaje));
    enemigos.push_back(new Mina(personaje));
    bool jugar=false;
    bool gano=false;
    bool perdio=false;
    int duracion_animacion=2;
    int cuadro_actual=0;
    int iteracion=0;
    int menu=0;
    int seleccion=0;
    bool moviendose=false;
    int tiempo=0;

    //Render the text
    up = TTF_RenderText_Solid( font, "Arriba", textColor );
    down = TTF_RenderText_Solid( font, "Abajo", textColor );
    left = TTF_RenderText_Solid( font, "Izquierda", textColor );
    right = TTF_RenderText_Solid( font, "Derecha", textColor );

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    Uint8 *keystates = SDL_GetKeyState( NULL );

        if (menu==0||menu==1||menu==3&&jugar==false&&seleccion==0&&perdio==false&&gano==false)
        apply_surface( 0, 0, Menu, screen );
        if (menu==0&&jugar==false&&seleccion==0){
        apply_surface( 370, 300, seleccionPlay, screen );
        apply_surface( 10, 300, botonIntrucciones, screen );
        apply_surface( 650, 300, botonSalir, screen );
        }
        if (menu==2&&jugar==false&&seleccion==0){
          apply_surface( 370, 300, botonPlay, screen );
        apply_surface( 10, 300, selecionIntrucciones, screen );
        apply_surface( 650, 300, botonSalir, screen );
        }
         if (menu==1&&jugar==false&&seleccion==0){
           apply_surface( 370, 300, botonPlay, screen );
        apply_surface( 10, 300, botonIntrucciones, screen );
        apply_surface( 650, 300, seleccionSalir, screen );
        }
        if( keystates[ SDLK_SPACE ] )
        {
            menu++;
        }
        if (menu==3)
            menu=0;

        if( keystates[ SDLK_RETURN ] )
        {

        if (menu==0&&jugar==false){
            jugar=true;
        }
        if (menu==2&&jugar==false){
         seleccion=1;
         menu=10;
        }
         if (menu==1&&jugar==false){
          exit(0);
        }
        if (seleccion==1&&jugar==false)
          apply_surface( 0, 0, instrucciones, screen );
        }
         if( keystates[ SDLK_ESCAPE ] ){
            if (seleccion==1){
            seleccion=0;
            menu=0;
            }
         }

        if (jugar==true&&perdio==false&&gano==false){
        apply_surface( 0, 0, Fondo, screen );
        apply_surface(590,400,meta,screen);

        if(moviendose)
            apply_surface(personaje->x,personaje->y,personaje->sprites[cuadro_actual],screen);
        else
            apply_surface(personaje->x,personaje->y,personaje->sprites[0],screen);

        for (int i=0 ;i<enemigos.size();i++){
        enemigos[i]->sprites[0]=enemigos[i]->sprites[cuadro_actual];
        enemigos[i]->Dibujar(screen);
                }

        for (int i=0 ;i<enemigos.size();i++){
              enemigos[i]->logica();
        }
        }
        //Get the keystates
        if (perdio==true){
            apply_surface( 0, 0, game_over, screen );
            for (int i=0 ;i<enemigos.size();i++){
              enemigos[i]->reset();
        }

        }
        if (perdio==true){

            //Pointer to the main screen surface
            Mix_Chunk *sound = NULL;		//Pointer to our sound, in memory
            int channel;				//Channel on which our sound is played

            int audio_rate = 22050;			//Frequency of audio playback
            Uint16 audio_format = AUDIO_S16SYS; 	//Format of the audio we're playing
            int audio_channels = 2;			//2 channels = stereo
            int audio_buffers = 4096;		//Size of the audio buffers in memory

            //Initialize BOTH SDL video and SDL audio
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
                printf("Unable to initialize SDL: %s\n", SDL_GetError());
                return 1;
            }

            //Initialize SDL_mixer with our chosen audio settings
            if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
                printf("Unable to initialize audio: %s\n", Mix_GetError());
                exit(1);
            }

            //Load our WAV file from disk
            sound = Mix_LoadWAV("marioshrink.wav");
            if(sound == NULL) {
                printf("Unable to load WAV file: %s\n", Mix_GetError());
            }
            //Set the video mode to anything, just need a window

            //Play our sound file, and capture the channel on which it is played
            channel = Mix_PlayChannel(-1, sound, 0);
            if(channel == -1) {
                printf("Unable to play WAV file: %s\n", Mix_GetError());
            }

            //Wait until the sound has stopped playing
            while(Mix_Playing(channel) != 0);

            //Release the memory allocated to our sound
            Mix_FreeChunk(sound);

            //Need to make sure that SDL_mixer and SDL have a chance to clean up
            Mix_CloseAudio();

            tiempo++;

        }
        if (gano==true){
           apply_surface( 100,80, victoria, screen );
           for (int i=0 ;i<enemigos.size();i++){
              enemigos[i]->reset();
        }
        ;
        }
        if (gano==true){
            //Pointer to the main screen surface
            Mix_Chunk *sound = NULL;		//Pointer to our sound, in memory
            int channel;				//Channel on which our sound is played

            int audio_rate = 22050;			//Frequency of audio playback
            Uint16 audio_format = AUDIO_S16SYS; 	//Format of the audio we're playing
            int audio_channels = 2;			//2 channels = stereo
            int audio_buffers = 4096;		//Size of the audio buffers in memory

            //Initialize BOTH SDL video and SDL audio
            if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
                printf("Unable to initialize SDL: %s\n", SDL_GetError());
                return 1;
            }

            //Initialize SDL_mixer with our chosen audio settings
            if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
                printf("Unable to initialize audio: %s\n", Mix_GetError());
                exit(1);
            }

            //Load our WAV file from disk
            sound = Mix_LoadWAV("gnatattack_levelcomplete.wav");
            if(sound == NULL) {
                printf("Unable to load WAV file: %s\n", Mix_GetError());
            }

            //Set the video mode to anything, just need a window

            //Play our sound file, and capture the channel on which it is played
            channel = Mix_PlayChannel(-1, sound, 0);
            if(channel == -1) {
                printf("Unable to play WAV file: %s\n", Mix_GetError());
            }

            //Wait until the sound has stopped playing
            while(Mix_Playing(channel) != 0);

            //Release the memory allocated to our sound
            Mix_FreeChunk(sound);

            //Need to make sure that SDL_mixer and SDL have a chance to clean up
            Mix_CloseAudio();

            tiempo++;
        }

        moviendose=false;

        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {
            apply_surface( ( SCREEN_WIDTH - up->w ) / 2, ( SCREEN_HEIGHT / 2 - up->h ) / 2, up, screen );
            personaje->y--;
            personaje->y--;
            moviendose=true;
        }

        //If down is pressed
        if( keystates[ SDLK_DOWN ] )
        {
            apply_surface( ( SCREEN_WIDTH - down->w ) / 2, ( SCREEN_HEIGHT / 2 - down->h ) / 2 + ( SCREEN_HEIGHT / 2 ), down, screen );
            personaje->y++;
            personaje->y++;
            moviendose=true;
        }

        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
            apply_surface( ( SCREEN_WIDTH / 2 - left->w ) / 2, ( SCREEN_HEIGHT - left->h ) / 2, left, screen );
            personaje->x--;
            personaje->x--;
            moviendose=true;
        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
            apply_surface( ( SCREEN_WIDTH / 2 - right->w ) / 2 + ( SCREEN_WIDTH / 2 ), ( SCREEN_HEIGHT - right->h ) / 2, right, screen );
            personaje->x++;
            personaje->x++;
            moviendose=true;
        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        if (tiempo==2){
            if (perdio==true){
            perdio=false;
            menu=0;
            jugar=false;
            tiempo=0;
            }
            if (gano==true){
            jugar=false;
            menu=0;
            gano=false;
            tiempo=0;
            }
        }
        iteracion++;
        if(iteracion==duracion_animacion)
        {
            cuadro_actual++;
            if(cuadro_actual==3)
            {
                cuadro_actual=0;
            }
            iteracion=0;
        }

        if(personaje->x>=590&&personaje->x<=800&&personaje->y>=400&&personaje->y<=600){
            gano =true;
            personaje->x=0;
           personaje->y=0;
        }



       }



    //Clean up
    clean_up();
    return 0;

}

