#include "Box.h"

Box::Box(Box *toClone) {
    start = toClone->start;
    end = toClone->end;
}

Box::Box(Point start, Point end) {
    this->start = move(start);
    this->end = move(end);
}

bool Box::intersects(const Box &other) {
    for (int i = 0; i < this->start.size(); i++) {
        if (other.start[i] < this->start[i] && other.end[i] < this->start[i]) {
            return false;
        }
    }
    for (int i = 0; i < this->end.size(); i++) {
        if (other.start[i] > this->end[i] && other.end[i] > this->end[i]) {
            return false;
        }
    }
    return true;
}

double Box::maxWidth() {
    double result = 0;
    for (int i = 0; i < end.size(); i++) {
        result = max(end[i] - start[i], result);
    }
    return result;
}
