#include "../headers/Vector2D.hpp"

#include <cmath>

Vector2D::Vector2D() {
    xComponent = 0;
    yComponent = 0;
}
Vector2D::Vector2D(Point2D startPoint, Point2D endPoint) {
    xComponent = endPoint.x - startPoint.x;
    yComponent = endPoint.y - startPoint.y;
}

Vector2D::Vector2D(int xComponent, int yComponent) {
    this->xComponent = xComponent;
    this->yComponent = yComponent;
}

Vector2D::~Vector2D() {

}

int Vector2D::getXComponent(){
    return xComponent;
}
int Vector2D::getYComponent(){
    return yComponent;
}
Vector2D Vector2D::velocityNormalize(int velocity) const {
    int magnitude = (int) std::sqrt(std::pow(xComponent, 2) + std::pow(yComponent, 2));
    return Vector2D((xComponent * velocity) / magnitude, (yComponent * velocity) / magnitude);
}