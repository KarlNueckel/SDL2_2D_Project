#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include "Point2D.hpp"

struct Vector2D {
    int xComponent;
    int yComponent;

    Vector2D();
    Vector2D(Point2D startPoint, Point2D endPoint);
    Vector2D(int xComponent, int yComponent);
    ~Vector2D();

    Vector2D velocityNormalize(int velocity) const;
    int getXComponent();
    int getYComponent();
};

#endif
