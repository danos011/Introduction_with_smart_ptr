#ifndef TECPROG1_DIAMOND_H
#define TECPROG1_DIAMOND_H

#include <string>
#include <cmath>

#include "shape.h"
#include "base-types.h"
#include "Exeptions.h"

class Diamond : public Shape {
private:
    point_t center_;
    point_t a_;
    point_t c_;

    double makeCut(const point_t& a, const point_t& b) const;

public:
    Diamond(const point_t& center, const point_t& a, const point_t& c);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCenter) override;
    void move(const double dx, const double dy) override;
    void show() const override;
    void scale(const double k) override;
};


#endif //TECPROG1_DIAMOND_H
