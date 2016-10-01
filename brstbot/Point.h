#ifndef POINT_H
#define POINT_H

class Point {
  public:
    float x;
    float y;

  public:
    String toString() {
      return concat("(", x) + concat(", ", y) + ")";
    }

    Point(int x_in, int y_in) {
      x = x_in;
      y = y_in;
    }

    Point() {
      x = 0;
      y = 0;
    }
};

#endif
