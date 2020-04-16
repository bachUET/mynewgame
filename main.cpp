#include "CommonFunc.h"
#include "baseObject.h"
#include "MainObject.h"
#include "Score.h"
BaseObject g_background;

bool start = false;
bool is_quit = false;

bool InitData(){
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0)
        return false;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");

    g_window = SDL_CreateWindow("Swing Copter",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if (g_window == NULL)
        success = false;
    else {
        g_screen = SDL_CreateRenderer(g_window,-1,SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            success = false;
        else {
            SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags= IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
    }
    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        return false;
    g_sound_fly = Mix_LoadWAV("sound//tap.wav");
    g_sound_die = Mix_LoadWAV("sound//hit.wav");
    g_sound_over = Mix_LoadWAV("sound//die.wav");
    g_music = Mix_LoadMUS("sound//music.mp3");
    return success;
}

bool loadBackground(){
    bool ret = g_background.LoadImg("image/background.png",g_screen);
    if (ret == false)
        return false;

    return true;
}

void close(){
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();
}
void LoadMenu(){
    BaseObject Menu;
    Menu.LoadImg("image//intro.png",g_screen);
    while (!start){
        Menu.Animate(g_screen,468,726,10);
        while (SDL_PollEvent(&g_event)!=0){
            if (g_event.type == SDL_KEYDOWN)
               start = true;
            if (g_event.type == SDL_QUIT){
                is_quit = true;
                start = true;
                break;
            }
        }
        SDL_RenderPresent(g_screen);
    }

}

int main(int argc, char* argv[]){
    if (InitData() == false)
        return -1;
    LoadMenu();
    if (loadBackground() == false)
        return -1;

    MainObject p_player;
    p_player.LoadImg("image//right.png", g_screen);
    p_player.set_clips();
    p_player.Show(g_screen);
    bool is_quit = false;

    Score p_score;
    p_score.SetRect(420,10);


    while(!is_quit){
        while(SDL_PollEvent(&g_event) != 0){
            if (g_event.type == SDL_QUIT)
                is_quit = true;
            p_player.HandleInputAction(g_event,g_screen);
        }
        SDL_SetRenderDrawColor(g_screen,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);
        g_background.Render(g_screen,NULL);

        p_player.Show(g_screen);
        p_player.DoPlayer();
        // Xuất hình ảnh nhân vật lên màn hình

        p_score.Show(g_screen,score);

        SDL_RenderPresent(g_screen);
    }
    close();
    return 0;
}
