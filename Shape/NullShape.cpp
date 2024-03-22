// File: Shape/NullShape.cpp

#include "NullShape.hpp"

NullShape::NullShape() {
}

double NullShape::area() {
    return 0.0;
}

double NullShape::perimeter() {
    return 0.0;
}

void NullShape::scale(double factor) {  
    cerr << "scale: Exercise for the student." << endl;
    throw -1;
}

void NullShape::display() {
    cout << "NullShape" << endl;
}

void NullShape::promptAndSetDimensions() {
}

