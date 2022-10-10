#include "Rectangle.h"

Rectangle::Rectangle(const point_t& bottomLeft, const point_t& upperRight) :
        bottomLeft_(bottomLeft),
        upperRight_(upperRight)
{
//    if(bottomLeft.x_ > upperRight.x_ || bottomLeft.y_ > upperRight.y_){
//        throw WrongPointsSet();
//    }
    center_.y_ = upperRight_.y_ / 2;
    center_.x_ = upperRight_.x_ / 2;
}

double Rectangle::getArea() const
{
    double length = sqrt(pow(upperRight_.x_ - bottomLeft_.x_, 2));
    double width = sqrt(pow(upperRight_.y_ - bottomLeft_.y_, 2));
    return length * width;
}

rectangle_t Rectangle::getFrameRect() const
{
    double length = sqrt(pow(upperRight_.x_ - bottomLeft_.x_, 2));
    double width = sqrt(pow(upperRight_.y_ - bottomLeft_.y_, 2));
    return rectangle_t{length, width, center_};
}

void Rectangle::move(const point_t& newCenter)
{
    double difX = center_.x_ - bottomLeft_.x_;
    double difY = center_.y_ - bottomLeft_.y_;
    center_ = newCenter;

    bottomLeft_.x_ = center_.x_ - difX;
    bottomLeft_.y_ = center_.y_ - difY;

    upperRight_.x_ = center_.x_ + difX;
    upperRight_.y_ = center_.y_ + difY;
}

void Rectangle::move(const double dx, const double dy)
{
    bottomLeft_.x_ += dx;
    bottomLeft_.y_ += dy;

    upperRight_.x_ += dx;
    upperRight_.y_ += dy;

    center_.x_ += dx;
    center_.y_ += dy;
}

void Rectangle::show() const
{
    rectangle_t cage = getFrameRect();

    point_t pointBuf = cage.getBotLeft();

    printf("%.1f ", round(pointBuf.x_ * 10.0) / 10.0);
    printf("%.1f ", round(pointBuf.y_ * 10.0) / 10.0);

    pointBuf = cage.getUpRight();

    printf("%.1f ", round(pointBuf.x_ * 10.0) / 10.0);
    printf("%.1f ", round(pointBuf.y_ * 10.0) / 10.0);
}

void Rectangle::scale(const double k)
{
    bottomLeft_.x_ *= k;
    bottomLeft_.y_ *= k;

    upperRight_.x_ *= k;
    upperRight_.y_ *= k;
}