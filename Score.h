#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#include "CommonFunc.h"
#include "baseObject.h"

const int score_width = 24;
const int score_height = 36;
class Score:public BaseObject{
    public:
        Score();
        ~Score();
        SDL_Rect score_clip_[10];
        void Show(SDL_Renderer* des,int score_);
    private:
};
#endif // SCORE_H_INCLUDED
