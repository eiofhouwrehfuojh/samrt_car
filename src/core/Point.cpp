#include "Point.hpp"
namespace adas
{
    Point::Point(const Point& rhs) noexcept : x(rhs.x), y(rhs.y) {}
    Point::Point(const int x_val, const int y_val) noexcept : x(x_val), y(y_val) {}

    Point& Point::operator=(const Point& rhs) noexcept 
    {
    if (this != &rhs) { // 检查自赋值
        x = rhs.x;
        y = rhs.y;
    }
    return *this;
    }
 

    Point& Point::operator+=(const Point& rhs) noexcept 
    {
    x += rhs.x;
    y += rhs.y;
    return *this;
    }
 
    Point& Point::operator-=(const Point& rhs) noexcept 
    {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
    }
 

    int Point::GetX() const noexcept 
    {
    return x;
    }
 

    int Point::GetY() const noexcept 
    {
    return y;
    }
}