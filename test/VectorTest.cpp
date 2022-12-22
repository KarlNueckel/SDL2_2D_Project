#include "gtest/gtest.h" 
#include "../headers/Vector2D.hpp"

//Testing Vector2D class constructors
//For default class
TEST(VectorTest_PASS, defaultConstructor_X) {//test class sets xComponent Correctly
    Vector2D *test = new Vector2D();//default constructor

    EXPECT_EQ(test->getXComponent(), 0);//default constructor should make this value 0
}
TEST(VectorTest_PASS, defaultConstructor_Y) {//test class sets yComponent correctly
    Vector2D *test = new Vector2D();//default constructor

    EXPECT_EQ(test->getYComponent(), 0);//default constructor should make this value 0
}

//For paramaterized constructor Vector2D(int xComponent, int yComponent)
TEST(VectorTest_PASS, paramConstructor_X) {
    Vector2D *test = new Vector2D(5, 6);//parmaterized constructor

    EXPECT_EQ(test->getXComponent(), 5);//5 is for xComponent
}
TEST(VectorTest_PASS, paramConstructor_Y) {
    Vector2D *test = new Vector2D(5, 6);//parmaterized constructor

    EXPECT_EQ(test->getYComponent(), 6);//6 is for yComponent
}

//Point2D parameter
TEST(VectorTest_PASS, point2DConstructor_X) {//test class runs
    struct Point2D startPoint;
    startPoint.x = 0;
    startPoint.y = 0;

    struct Point2D endPoint; 
    endPoint.x = 7;
    endPoint.y = 9;

    Vector2D *test = new Vector2D(startPoint, endPoint);//parmaterized constructor

    EXPECT_EQ(test->getXComponent(), 7);//endPoint.x - startPoint.x = 7
}
TEST(VectorTest_PASS, point2DConstructor_Y) {//test class runs
    struct Point2D startPoint;
    startPoint.x = 0;
    startPoint.y = 0;

    struct Point2D endPoint; 
    endPoint.x = 7;
    endPoint.y = 9;

    Vector2D *test = new Vector2D(startPoint, endPoint);//parmaterized constructor

    EXPECT_EQ(test->getYComponent(), 9);//endPoint.y - startPoint.y = 9
}

