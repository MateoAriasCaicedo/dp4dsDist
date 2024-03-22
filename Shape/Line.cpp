// File: Shape/Line.cpp

#include "Line.hpp"
#include "Utilities.hpp"

Line::Line(double length) {  
    if(length < 0.0) {
        cerr << "Line precondition violated: length cannot be negative." << endl;
        throw -1;
    }
    _length = length;
}

double Line::area() {  
    return 0.0;
}

double Line::perimeter() {  
    return _length;
}

void Line::scale(double factor) {
    if (factor <= 0) {
        cerr << "Shape precondition violated: factor must be > 0";
        throw -1;
    }

    _length *= factor;
}

void Line::display() {
    cout << "Line\n" << "Length: " << _length << endl;
}

void Line::promptAndSetDimensions() {
    _length = promptDoubleGE("Length?", 0.0);
}

