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

class Triangle : public Figure {
public:
    Point p1st, p2nd, p3th;

    Triangle(){};

    Triangle(Point p1, Point p2, Point p3) {
        this->p1st = p1;
        this->p2nd = p2;
        this->p3th = p3;
    }

    double sign(Point p1, Point p2, Point p3) {
        return (((p1.x - p3.x) * (p2.y - p3.y)) - ((p2.x - p3.x) * (p1.y - p3.y)));
    }

    virtual bool pointIsContained(Point p) {
        double d1, d2, d3;
        bool negative, positive;

        d1 = sign(p, p1st, p2nd);
        d2 = sign(p, p2nd, p3th);
        d3 = sign(p, p3th, p1st);

        negative = ((d1 <= 0) || (d2 <= 0) || (d3 <= 0));
        positive = ((d1 >= 0) || (d2 >= 0) || (d3 >= 0));

        return !(positive && negative);
    }
};


int main() {


    return 0;
}
