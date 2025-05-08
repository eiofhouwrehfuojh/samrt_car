#include "Direction.hpp"
namespace adas
{
    static const Direction directions[4]=
    {
        {0,'E'},{1,'S'},{2,'W'},{3,'N'},
    };
    static const Point points[4]=
    {
        {1,0},{0,-1},{-1,0},{0,1},
    };
    const Direction& Direction::GetDirection(const char heading) noexcept
    {
        for (const auto& direction : directions)
        {
            if(direction.heading == heading)
            {
                return direction;
            }
        }
        return directions[3];
    }
    Direction::Direction(const unsigned index, const char heading) noexcept
        : index(index), heading(heading) {}
    const Point& Direction::Move() const noexcept
    {
        return points[index];
    }
    const Direction& Direction::LeftOne() const noexcept
    {
        unsigned newIndex = (index + 3) % 4; // 左转相当于逆时针旋转，即index-1，但要考虑循环
        return directions[newIndex];
    }
 
    const Direction& Direction::RightOne() const noexcept
    {
        unsigned newIndex = (index + 1) % 4; // 右转相当于顺时针旋转，即index+1，但要考虑循环
        return directions[newIndex];
    }
     const char Direction::GetHeading() const noexcept
    {
        return heading;
    }
}