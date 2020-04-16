#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED
#include "CommonFunc.h"
#include "baseObject.h"

class MainObject : public BaseObject {
    public:
        MainObject();
        ~MainObject();
        enum FlyType{
            FLY_RIGHT = 0,
            FLY_LEFT = 1,
        };
        bool LoadImg(std::string path, SDL_Renderer* screen);
        void Show(SDL_Renderer* des);
        void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
        void set_clips();
        void DoPlayer();
        int getWidth(){
            return width_frame_;
        }
        int getHeight(){
            return height_frame_;
        }
        float getY_val(){
            return y_val_;
        };
        void addY_val(float y) {
            y_val_=y;
        }
    private:
        float x_val_;
        float y_val_;
        float x_pos_;
        float y_pos_;

        int width_frame_;
        int height_frame_;
        SDL_Rect frame_clip_[FrameNum];
        Input input_type_;
        int frame_;
        int status_;
};


#endif // MAINOBJECT_H_INCLUDED

