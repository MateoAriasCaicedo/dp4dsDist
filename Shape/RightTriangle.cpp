// File: Shape/RightTriangle.cpp

#include <cmath> // sqrt.


#include "RightTriangle.hpp"
#include "Utilities.hpp"

RightTriangle::RightTriangle(double base, double height) {
    try {
        if (base < 0.0 || height < 0.0) {
            throw -1;
        }
    } catch (int a) {
        cerr << "Violated precondition: the base and the height must greater or equal to zero\n";
        exit(a);
    }

    _base = base;
    _height = height;
}

double RightTriangle::area() {
    return (_base * _height) / 2;
}

double RightTriangle::perimeter() {
    return _base + _height + sqrt(_base * _base + _height * _height);
}

void RightTriangle::scale(double factor) {
    if (factor <= 0) {
        throw -1;
    }

    _height *= factor;
    _base *= factor;
}

void RightTriangle::display() {
    cout << "Right triangle\n";
    cout << "Base: " << _base << "\n";
    cout << "Height: " << _height << "\n";
}

void RightTriangle::promptAndSetDimensions() {
    _base = promptDoubleGE("Base?", 0.0);
    _height = promptDoubleGE("Height?", 0.0);
}
