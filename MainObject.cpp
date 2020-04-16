#include "MainObject.h"

static bool temp = false;
static bool press = false;

MainObject::MainObject(){
    frame_= 0;
    // Tọa Độ X
    x_pos_= 200;
    y_pos_= 555;
    // Vận tốc
    x_val_=0;
    y_val_=0;
    // Chiều rộng của nhân vật
    width_frame_ = 0;
    // Chiều cao của nhân vật
    height_frame_ = 0;
    // Trạng thái
    status_ = FLY_RIGHT;
    //input_type_.left_=0;
    //input_type_.right_=0;
}
MainObject::~MainObject(){

}

// Lấy dữ liệu hình ảnh từ file vào chương trình
bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseObject::LoadImg(path,screen);
    if (ret == true){
        width_frame_ = rect_.w / FrameNum;
        height_frame_ = rect_.h;
    }
    return ret;
}
// Tạo hiệu ứng Animation
void MainObject::set_clips(){
    if (width_frame_ > 0 && height_frame_ > 0){
        for (int i = 0; i < FrameNum; i++){
            frame_clip_[i].x = i*width_frame_;
            frame_clip_[i].y = 0;
            frame_clip_[i].w = width_frame_;
            frame_clip_[i].h = height_frame_;
        }
    }
}
// Xuất hình ảnh nhân vật lên màn hình
void MainObject::Show(SDL_Renderer* des){
    // Hướng về bên trái thì load ảnh nhân vật bên trái
    if (status_ == FLY_LEFT)
        LoadImg("image//left.png",des);
    else LoadImg("image//right.png",des);
    if (input_type_.left_== 1 || input_type_.right_ == 1)
        frame_++;
    if (frame_ >= FrameNum) frame_ =0;
    rect_.x = x_pos_;
    rect_.y = y_pos_;

    SDL_Rect* current_clip = &frame_clip_[frame_];
    SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};
    SDL_RenderCopy(des, p_object_,current_clip, &renderQuad);
}
// Hàm điều khiển trạng thái nhân vật
void MainObject::HandleInputAction(SDL_Event events,  SDL_Renderer* screen){
    if (events.type == SDL_KEYDOWN){
        switch (events.key.keysym.sym){
            case SDLK_SPACE:
                if (status_ == FLY_LEFT) {
                    press = true;
                    //status_ = FLY_RIGHT;
                    input_type_.right_ = 1;
                }
                else {
                    //status_ = FLY_LEFT;
                    press = true;
                    input_type_.left_ = 1;
                }
                break;
            default:
                break;
        }
    }
    else if (events.type == SDL_KEYUP){
        switch (events.key.keysym.sym){
            case SDLK_SPACE:
                if (status_ == FLY_LEFT) {
                    press = false;
                    status_ = FLY_RIGHT;
                    input_type_.right_ = 0;
                }
                else {
                    press = false;
                    status_ = FLY_LEFT;
                    input_type_.left_ = 0;
                }
                break;
            default:
                break;
        }
    }


}
// Hàm Di Chuyển Nhân Vật
void MainObject::DoPlayer(){
    y_val_ += 0.008;
    if (!press){
        if (x_val_ >= 0){
            x_val_ += 0.01;
            if (x_val_<0) x_val_ = 0;
        }
        else{
            x_val_ +=0.002;
            if (x_val_ >0) x_val_ = 0;
        }

    }
    else {
        x_val_ = 0;
        y_val_ = 0;
    }
    //if (x_val_>7) x_val_=7;
    //if (x_val_<-7) x_val_=-7;
    if (FLY_LEFT == 1){
        x_pos_ += x_val_;
        y_pos_ -= y_val_;
    }
    else if (FLY_RIGHT == 1){
        x_pos_ -= x_val_;
        y_pos_ -= y_val_;
    }


}





