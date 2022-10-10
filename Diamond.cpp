#include "Diamond.h"

Diamond::Diamond(const point_t& center,const point_t& a, const point_t& c) :
        center_(center),
        a_(a),
        c_(c)
{

}

double Diamond::makeCut(const point_t& a, const point_t& b) const
{
    return sqrt(pow(a.x_ - b.x_, 2) + pow(a.y_ - b.y_, 2));
}

double Diamond::getArea() const
{
    double d1 = makeCut(a_, center_);
    double d2 = makeCut(c_, center_);

    return d1 * d2 * 0.5;
}

rectangle_t Diamond::getFrameRect() const
{
    double d1 = makeCut(a_, center_);
    double d2 = makeCut(c_, center_);

    return rectangle_t{d2 * 2, d1 * 2, center_};
}

void Diamond::move(const point_t& newCenter)
{
    double dy;
    double dx;

    if(center_.x_ - a_.x_ != 0.0){
        dx = center_.x_ - a_.x_;
        a_.x_ = newCenter.x_ + dx;
    }
    else{
        dx = center_.x_ - c_.x_;
        c_.x_ = newCenter.x_ + dx;
    }

    if(center_.y_ - a_.y_ != 0.0){
        dy = center_.y_ - a_.y_;
        a_.y_ = newCenter.y_ + dy;
    }
    else{
        dy = center_.y_ - c_.y_;
        c_.y_ = newCenter.y_ + dy;
    }

    center_ = newCenter;


}

void Diamond::move(const double dx, const double dy)
{
    center_.x_ += dx;
    center_.y_ += dy;

    a_.x_ += dx;
    a_.y_ += dy;

    c_.x_ += dx;
    c_.y_ += dy;
}

void Diamond::show() const
{
    rectangle_t cage = getFrameRect();

    point_t pointBuf = cage.getBotLeft();

    printf("%.1f ", round(pointBuf.x_ * 10.0) / 10.0);
    printf("%.1f ", round(pointBuf.y_ * 10.0) / 10.0);

    pointBuf = cage.getUpRight();

    printf("%.1f ", round(pointBuf.x_ * 10.0) / 10.0);
    printf("%.1f ", round(pointBuf.y_ * 10.0) / 10.0);

}

void Diamond::scale(const double k)
{
    center_.x_ *= k;
    center_.y_ *= k;

    a_.x_ *= k;
    a_.y_ *= k;

    c_.x_ *= k;
    c_.y_ *= k;
}
