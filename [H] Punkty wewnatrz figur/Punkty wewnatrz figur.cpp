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

    vector < Figure* > figures;
    char fig;

    while(cin >> fig) {

        if(fig == '*') break;

        if(fig == 'r') {

            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Point p1(x1, y1);
            Point p2(x2, y2);
            Figure *f = new Rectangle(p1, p2);
            figures.push_back(f);

        } else if(fig == 'c') {

            double xC, yC, r;
            cin >> xC >> yC >> r;
            Point c(xC, yC);
            Figure *f = new Circle(c, r);
            figures.push_back(f);

        } else if(fig == 't') {

            double x1, y1, x2, y2, x3, y3;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            Point p1(x1, y1), p2(x2, y2), p3(x3, y3);
            Figure *f = new Triangle(p1, p2, p3);
            figures.push_back(f);
        }
    }

    Point example;
    int pointNumber = 0;
    while(cin >> example) {
        if(example.x == 9999.9 && example.y == 9999.9) break;

        pointNumber++;
        bool isContained = false;
        for(int i = 0; i < figures.size(); i++) {
            if(figures[i]->pointIsContained(example)) {
                isContained = true;
                cout << "Point " << pointNumber << " is contained in figure " << i+1 << endl;
            }
        }

        if(isContained == false) {
            cout << "Point " << pointNumber << " is not contained in any figure" << endl;
        }
    }

    for(int i = 0; i < figures.size(); i++) {
        delete figures[i];
    }

    return 0;
}
