#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED
#include "CommonFunc.h"
#include "baseObject.h"
#define GRAVITY_SPEED 0.01
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 4

class MainObject : public baseObject{
public:
    MainObject();
    ~MainObject();
    enum FlyType{
        FLY_RIGHT = 0,
        FLY_LEFT = 1
    };
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clips();
    void DoPlayer(bool check,Mix_Chunk* jumpsound,Mix_Chunk* highhighjumpsound);
    //void DoPlayer(Platform* plat_objects);
    int getWidth(){return width_frame_;}
    int getHeight(){return height_frame_;}
    float getY_val(){return y_val_;};
    void addY_val(float y) {y_val_=y;}
    bool on_ground = false;
    bool high_jump;
    bool highhigh_jump;
    //bool checkJump(Platform* plat_objects);
    float x_val_;
    float y_val_;
    float x_pos_;
    float y_pos_;
private:
    int width_frame_;
    int height_frame_;
    SDL_Rect frame_clip_[FrameNum];
    Input input_type_;
    int frame_;
    int status_;
};


#endif // MAINOBJECT_H_INCLUDED

