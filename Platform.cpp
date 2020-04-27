#include "Platform.h"
#include "CommonFunc.h"

Platform::Platform()
{
    plat_type = REAL_PLAT;
    drop_val_ = 0;
    Drop = false;
    object = 0;
}
Platform::~Platform()
{

}
void Platform::setPlat_type(int plat_type_)
{
    plat_type = plat_type_;
}
void Platform::renderPlat(Platform* plat_objects)
{

}
