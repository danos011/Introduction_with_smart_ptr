#ifndef TECPROG1_BASE_TYPES_H
#define TECPROG1_BASE_TYPES_H

#include <cmath>

struct point_t
{
    double x_;
    double y_;

    point_t() :
            x_(0.0),
            y_(0.0)
    {}

    point_t(double x, double y) :
            x_(x),
            y_(y)
    {}
};

struct rectangle_t
{
    double length_;
    double width_;
    point_t pos_;

    rectangle_t() :
            length_(0.0),
            width_(0.0),
            pos_({0.0, 0.0})
    {}

    rectangle_t(double length, double width, point_t pos) :
            length_(length),
            width_(width),
            pos_(pos)
    {}

    point_t getUpRight() const{
        return point_t (length_, width_ );
    }

    point_t getBotLeft() const{
        return point_t (2*pos_.x_ - length_, 2*pos_.y_ - width_);
    }

};
#endif // TECPROG1_BASE_TYPES_H
