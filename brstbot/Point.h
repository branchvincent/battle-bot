#ifndef POINT_H
#define POINT_H

#include <WString.h>

class Point {

    public:
        Point();
        Point(int x_in, int y_in);
        String toString();

    public:
        float x;
        float y;
};

#endif
