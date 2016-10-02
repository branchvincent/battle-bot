#include "Point.h"
#include "Utilities.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x_in, int y_in) {
    x = x_in;
    y = y_in;
}

String Point::toString() {
    return concat("(", x) + concat(", ", y) + ")";
}
