#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point {
public:
    double x;
    double y;

    Point(){};

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    friend istream& operator>>(istream &input, Point &p);
    friend ostream& operator<<(ostream &output, const Point &p);
};

istream& operator>>(istream &input, Point &p) {
    double x, y;
    input >> x >> y;
    p.x = x;
    p.y = y;

    return input;
}

ostream& operator<<(ostream &output, const Point &p) {
    output << "(" << p.x << "; " << p.y << ")";
    return output;
}

class Figure {
public:
    virtual bool pointIsContained(Point p){};
};

int main() {


    return 0;
}
