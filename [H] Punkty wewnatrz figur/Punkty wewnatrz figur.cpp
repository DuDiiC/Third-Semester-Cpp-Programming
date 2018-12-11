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

class Rectangle : public Figure {
public:
    Point upperLeft, lowerRight;

    Rectangle(){};

    Rectangle(Point uL, Point lR) {
        this->upperLeft = uL;
        this->lowerRight = lR;
    }

    virtual bool pointIsContained(Point p) {
        if(p.x > upperLeft.x && p.x < lowerRight.x) {
            if(p.y < upperLeft.y && p.y > lowerRight.y) {
                return true;
            }
        }
        return false;
    }
};

class Circle : public Figure {
public:
    Point center;
    double radius;

    Circle(){};

    Circle(Point c, double r) {
        this->center = c;
        this->radius = r;
    }

    virtual bool pointIsContained(Point p) {
        if(pow((p.x - this->center.x), 2) + pow((p.y - this->center.y), 2) < pow(this->radius, 2)) return true;
        else return false;
    }
};

int main() {


    return 0;
}
