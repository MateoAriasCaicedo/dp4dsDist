// File: Shape/MysteryShape.hpp
// Exercise for the student.


#ifndef MysteryShape_hpp
#define  MysteryShape_hpp

#include "AShape.hpp"

class MysteryShape : public AShape {
private:
    double _sideLenght;

public:
    // Pre: side_lenght >= 0.
    // Post: the equilateral triangle is initialized with side lenght of _sideLenght.
    explicit MysteryShape(double side_lenght = 0.0);

    double area() override;

    void display() override;

    double perimeter() override;

    void scale(double factor) override;

    void promptAndSetDimensions() override;
};

#endif
