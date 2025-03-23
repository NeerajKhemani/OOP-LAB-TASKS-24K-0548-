#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    double borderThickness;

public:
    Shape(const string& c = "black", double thickness = 1.0)
        : color(c), borderThickness(thickness) {}

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    double centerX, centerY;

public:
    Circle(double r, double x, double y, const string& c = "black", double thickness = 1.0)
        : Shape(c, thickness), radius(r), centerX(x), centerY(y) {}

    void draw() const override {
        cout << "Drawing Circle at (" << centerX << ", " << centerY << ") with radius " << radius << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    double topLeftX, topLeftY;

public:
    Rectangle(double w, double h, double x, double y, const string& c = "black", double thickness = 1.0)
        : Shape(c, thickness), width(w), height(h), topLeftX(x), topLeftY(y) {}

    void draw() const override {
        cout << "Drawing Rectangle at top-left (" << topLeftX << ", " << topLeftY
             << ") with width " << width << " and height " << height << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double side1, double side2, double side3, const string& col = "black", double thickness = 1.0)
        : Shape(col, thickness), a(side1), b(side2), c(side3) {}

    void draw() const override {
        cout << "Drawing Triangle with sides: " << a << ", " << b << ", " << c << endl;
    }

    double calculatePerimeter() const override {
        return a + b + c;
    }

    double calculateArea() const override {
        double s = calculatePerimeter() / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class Polygon : public Shape {
private:
    pair<double, double> points[10];
    int numVertices;

    double distance(pair<double, double> p1, pair<double, double> p2) const {
        return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
    }

public:
    Polygon(pair<double, double> pts[], int count, const string& col = "black", double thickness = 1.0)
        : Shape(col, thickness), numVertices(count) {
        for (int i = 0; i < count; ++i) {
            points[i] = pts[i];
        }
    }

    void draw() const override {
        cout << "Drawing Polygon with " << numVertices << " vertices." << endl;
    }

    double calculatePerimeter() const override {
        double peri = 0.0;
        for (int i = 0; i < numVertices; ++i) {
            peri += distance(points[i], points[(i + 1) % numVertices]);
        }
        return peri;
    }

    double calculateArea() const override {
        double area = 0.0;
        for (int i = 0; i < numVertices; ++i) {
            area += (points[i].first * points[(i + 1) % numVertices].second)
                  - (points[(i + 1) % numVertices].first * points[i].second);
        }
        return fabs(area) / 2.0;
    }
};

int main() {
    Circle circle(5.0, 10.0, 20.0, "red", 2.0);
    Rectangle rect(4.0, 6.0, 0.0, 0.0, "blue", 1.5);
    Triangle tri(3.0, 4.0, 5.0, "green", 1.2);

    pair<double, double> polyPoints[4] = {
        {0, 0}, {4, 0}, {4, 3}, {0, 3}
    };
    Polygon poly(polyPoints, 4, "purple", 1.8);

    Shape* shapes[4] = { &circle, &rect, &tri, &poly };

    for (int i = 0; i < 4; ++i) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << "\n\n";
    }

    return 0;
}
