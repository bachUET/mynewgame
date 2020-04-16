#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"
class BaseObject{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x,const int&y){
        rect_.x = x;
        rect_.y = y;
    }
    SDL_Rect GetRect() const{ //Const để đảm bảo tính chặt chẽ, lấy ra chứ không thay đổi gì
        return rect_;
    }
    SDL_Texture* GetObject() const{
        return p_object_;
    }

    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();
    void Animate(SDL_Renderer* des,int width_,int height_,int number_);
protected:
    SDL_Texture* p_object_;
    SDL_Rect rect_;
    SDL_Rect object_clip_[20];
    int num = 0;
};

#endif // BASE_OBJECT_H_

