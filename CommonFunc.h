#ifndef COMMONFUNCTION_H_INCLUDED
#define COMMONFUNCTION_H_INCLUDED

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <string>


const int SCREEN_WIDTH = 451;
const int SCREEN_HEIGHT = 652;
const int SCREEN_BPP = 32;
const int MAX_HEIGHT = 250;
const int JUMP_SPEED = 17;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int FrameNum = 10;
const int FRAME_PER_SECOND = 65;

static SDL_Window *g_windows = NULL;
static SDL_Renderer *g_screen = NULL;
static SDL_Event g_event;

static int score = 0;
static int score_ = 0;
static Mix_Chunk* g_sound_jump;
static Mix_Chunk* g_sound_fake;
static Mix_Chunk* g_sound_die;
static Mix_Chunk* g_sound_feder;
static Mix_Music* g_music;

typedef struct Input{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};
#endif // COMMONFUNCTION_H_INCLUDED
