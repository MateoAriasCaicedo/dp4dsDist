// File: VectorT/VectorT.hpp

#ifndef VectorT_HPP_
#define VectorT_HPP_

#include <iostream> // istream, ostream.
#include <memory>   // smart pointers

#include "ASeq.hpp"

using namespace std;

// ========= VectorT =========

template<class T>
class VectorT : public ASeq<T> {
private:
    unique_ptr<T[]> _data;
    int _cap; // Invariant: 0 < _cap, and _cap is a power of 2.
    int _size; // Invariant: 0 <= _size <= _cap.

    void doubleCapacity();

public:
    VectorT();

    // Post: This vector is initialized with capacity of 1 and size of 0.

    VectorT(VectorT const &rhs) = delete; // Disabled.
    VectorT &operator=(VectorT const &rhs) = delete; // Disabled.


    void append(T const &e);

    // Post: Element e is appended to this vector, possibly increasing cap().

    int cap() const override { return _cap; }
    // Post: The capacity of this vector is returned.

    void insert(int i, T const &e);

    // Pre: 0 <= i && i <= size().
    // Post: Items [i..size()-1] are shifted right and element e is
    // inserted at position i.
    // size() is increased by 1, possibly increasing cap().

    T &operator[](int i) override; // For read/write.
    T const &operator[](int i) const override; // For read-only.

    T remove(int i);

    // Pre: 0 <= i && i < size(). T has a copy constructor.
    // Post: Element e is removed from position i and returned.
    // Items [i+1..size()-1] are shifted left.
    // size() is decreased by 1 (and cap() is unchanged).

    int size() const { return _size; }
    // Post: The size of this vector is returned.

    void toStream(ostream &os) const override;

    // Pre: operator<< is defined for T.
    // Post: A string representation of this vector is returned to output stream os.

    int fromStream(istream &is) override;

    // Pre: operator>> is defined for T.
    // Post: The items of input stream is are appended to this vector.
};

// ========= Constructor =========
template<class T>
VectorT<T>::VectorT() {
    _data = make_unique<T[]>(1);
    _cap = 1;
    _size = 0;
}

// ========= append =========
template<class T>
void VectorT<T>::append(T const &e) {
    if (_size == _cap) {
        doubleCapacity();
    }
    _data[_size++] = e;
}

// ========= doubleCapacity =========
template<class T>
void VectorT<T>::doubleCapacity() {
    _cap *= 2;
    T *newDat = new T[_cap];
    for (int k = 0; k < _size; k++) {
        newDat[k] = _data[k];
    }
    _data.reset(newDat);
}

// ========= insert =========
template<class T>
void VectorT<T>::insert(int i, T const &e) {
    // Check the index being in bounds.
    if (i < 0 || i > _size) {
        cerr << "Index out of bounds\n";
        throw -1; // Precondition violated.
    }

    // Ensure that the insertion can occur without index out of bounds.
    if (_size == _cap) {
        doubleCapacity();
    }

    // Move item from i to size - 1 to the right.
    for (int j = _size; j > i; j--) {
        _data[j] = _data[j - 1];
    }

    _data[i] = e; // Insert the element at index i without loosing data.
    _size += 1; // Increase size after insertion.
}

// ========= operator[] =========
template<class T>
T &VectorT<T>::operator[](int i) {
    if (i < 0 || _size <= i) {
        cerr << "VectorT index out of bounds: index == " << i << endl;
        throw -1;
    }
    return _data[i];
}

template<class T>
T const &VectorT<T>::operator[](int i) const {
    if (i < 0 || _size <= i) {
        cerr << "VectorT index out of bounds: index == " << i << endl;
        throw -1;
    }
    return _data[i];
}

// ========= remove =========
template<class T>
T VectorT<T>::remove(const int i) {
    // Check the index to remove being in bounds.
    if (i < 0 || i >= _size) {
        std::cerr << "Index out of bounds\n";
        throw -1; // Precondition violated.
    }

    // Store element to remove.
    T removed = _data[i];

    // Move the elements after i to the left.
    for (int j = i; j < _size - 1; j++) {
        _data[j] = _data[j + 1];
    }

    // Decrease size after removing element.
    _size -= 1;

    // Return removed element.
    return removed;
}

// ========= toStream =========
template<class T>
void VectorT<T>::toStream(ostream &os) const {
    os << "(";
    for (int i = 0; i < _size - 1; i++) {
        os << _data[i] << ", ";
    }
    if (_size > 0) {
        os << _data[_size - 1];
    }
    os << ")";
}

// ========= fromStream =========
template<class T>
int VectorT<T>::fromStream(istream &is) {
    T temp;
    if constexpr (!is_shared_ptr<T>::value)
        while (is >> temp) {
            append(temp);
        }
    return _size;
}

#endif
