#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual double CalculateArea() const = 0;

    static bool CompareAreas(const Shape& shape1, const Shape& shape2) {
        double area1 = shape1.CalculateArea();
        double area2 = shape2.CalculateArea();
        
       
        double epsilon = 0.0001;
        if (fabs(area1 - area2) < epsilon) {
            cout << "The areas of the shapes are approximately equal." << endl;
            return true;
        } else {
            cout << "The areas of the shapes are not equal." << endl;
            return false;
        }
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double CalculateArea() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double CalculateArea() const override {
        return width * height;
    }
};

int main() {
    double circleRadius, rectWidth, rectHeight;

    cout << "Enter the radius of a circle: ";
    cin >> circleRadius;

    cout << "Enter the width of a rectangle: ";
    cin >> rectWidth;

    cout << "Enter the height of a rectangle: ";
    cin >> rectHeight;

    Circle circle(circleRadius);
    Rectangle rectangle(rectWidth, rectHeight);

    cout << "Area of the circle: " << circle.CalculateArea() << endl;
    cout << "Area of the rectangle: " << rectangle.CalculateArea() << endl;

    Shape::CompareAreas(circle, rectangle);
    
    return 0;
}
