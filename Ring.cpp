#include "Ring.h"

const double PI = 3.14;

Ring::Ring(const point_t& center, const double outerRadius, const double innerRadius) :
        center_(center),
        outerRadius_(outerRadius),
        innerRadius_(innerRadius)
{
    if(outerRadius < innerRadius){
        return;
    }
}

double Ring::getArea() const
{
    return 2 * PI * (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_);
}

rectangle_t Ring::getFrameRect() const
{
    return rectangle_t{2 * outerRadius_, 2 * outerRadius_, center_};
}

void Ring::move(const point_t& newCenter)
{
    center_ = newCenter;
}

void Ring::move(const double dx, const double dy)
{
    center_.x_ += dx;
    center_.y_ += dy;
}

void Ring::show() const
{
    rectangle_t cage = getFrameRect();

    point_t pointBuf = cage.getBotLeft();

    printf("%.1f ", round(pointBuf.x_ * 10.0) / 10.0);
    printf("%.1f ", round(pointBuf.y_ * 10.0) / 10.0);

    pointBuf = cage.getUpRight();

    printf("%.1f ", round(pointBuf.x_ * 10.0) / 10.0);
    printf("%.1f ", round(pointBuf.y_ * 10.0) / 10.0);

}

void Ring::scale(const double k)
{
    outerRadius_ *= k;
    innerRadius_ *= k;
}