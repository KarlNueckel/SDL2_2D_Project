#ifndef POINT2D_HPP
#define POINT2D_HPP

struct Point2D {
    int x;
    int y;

    Point2D() {
        x = 0;
        y = 0;
    }

    Point2D(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

#endif
