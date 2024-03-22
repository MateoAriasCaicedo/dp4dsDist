// File: Shape/MysteryShape.cpp
// Exercise for the student.

#include "MysteryShape.hpp"
#include "Utilities.hpp"
#include <cmath> // sqrt.

MysteryShape::MysteryShape(double side_lenght) {
    if (side_lenght < 0) {
        throw -1;
    }

    _sideLenght = side_lenght;
}

double MysteryShape::area() {
    return (_sideLenght * _sideLenght * sqrt(3)) / 4;
}

void MysteryShape::display() {
    cout << "Equilateral triangle\n";
    cout << "Side lenght: " << _sideLenght << "\n";
}

double MysteryShape::perimeter() {
    return 3 * _sideLenght;
}

void MysteryShape::scale(double factor) {
    _sideLenght *= factor;
}

void MysteryShape::promptAndSetDimensions() {
    _sideLenght = promptDoubleGE("Side lenght?", 0.0);
}
