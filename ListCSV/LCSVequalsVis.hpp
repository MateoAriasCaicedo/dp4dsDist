// File: ListCSV/LCSVequalsVis.hpp

#ifndef LCSVEQUALSVIS_HPP_
#define LCSVEQUALSVIS_HPP_

#include <iostream>
using namespace std;

#include "ListCSV.hpp"
#include "LCSVisEmptyVis.hpp"

template<class T> class ListCSVequalHelperVis; // Forward declaration.

// ========= LCSVequalsVis =========
template<class T>
class LCSVequalsVis : public AListCSVVis<T> {
private:
    ListCSV<T> const &_rhs; // Input parameter.
    bool _result;           // Output result.

public:
    // ========= Constructor =========
    explicit LCSVequalsVis(ListCSV<T> const &rhs): _rhs(rhs) {}

    // ========= visit =========
    void emptyCase(ListCSV<T> &host) override {
        cerr << "LCSVequalsVis: Exercise for the student." << endl;
        throw -1;
    }

    void nonEmptyCase(ListCSV<T> &host) override {
        cerr << "LCSVequalsVis: Exercise for the student." << endl;
        throw -1;
    }

    // ========= visit const =========
    void emptyCase(ListCSV<T> const &host) override {
        cerr << "LCSVequalsVis: Exercise for the student." << endl;
        throw -1;
    }

    void nonEmptyCase(ListCSV<T> const &host) override {
        cerr << "LCSVequalsVis: Exercise for the student." << endl;
        throw -1;
    }

    // ========= result =========
    // Pre: This visitor has been accepted by a host list.
    // Post: true is returned if the host list is equal to rhs; otherwise, false is returned.
    // Two lists are equal if they contain the same number of equal elements in the same order.
    bool result() const {
        cerr << "LCSVequalsVis: Exercise for the student." << endl;
        throw -1;
    }
};

// ========= ListCSVequalHelperVis =========
template<class T>
class ListCSVequalHelperVis : public AListCSVVis<T> {
private:
    T const &_first; // Input parameter.
    ListCSV<T> const &_rest; // Input parameter.
    bool _result; // Output result.

public:
    // ========= Constructor =========
    ListCSVequalHelperVis(T const &first, ListCSV<T> const &rest): _first(first), _rest(rest) {}

    // ========= visit =========
    void emptyCase(ListCSV<T> &host) override {
        cerr << "ListCSVequalHelperVis: Exercise for the student." << endl;
        throw -1;
    }

    void nonEmptyCase(ListCSV<T> &host) override {
        cerr << "ListCSVequalHelperVis: Exercise for the student." << endl;
        throw -1;
    }

    // ========= visit const =========
    void emptyCase(ListCSV<T> const &host) override {
        cerr << "ListCSVequalHelperVis: Exercise for the student." << endl;
        throw -1;
    }

    void nonEmptyCase(ListCSV<T> const &host) override {
        cerr << "ListCSVequalHelperVis: Exercise for the student." << endl;
        throw -1;
    }

    // ========= result =========
    // Pre: This visitor has been accepted by a host list.
    // Post: true is returned if first equals host.first() and rest equals host.rest();
    // otherwise, false is returned.
    bool result() const {
        cerr << "ListCSVequalHelperVis: Exercise for the student." << endl;
        throw -1;
    }
};

// Global function for convenience.
// ========= operator== =========
template<class T>
bool operator==(ListCSV<T> const &lhs, ListCSV<T> const &rhs) {
    cerr << "operator==: Exercise for the student." << endl;
    throw -1;
}

#endif
