// File: ListCV/LCVtoStreamVis.hpp

#ifndef LCVtoStreamVis_hpp
#define LCVtoStreamVis_hpp

#include <iostream>
using namespace std;

#include "ListCV.hpp"

// ========= LCVtoStreamHelperVis =========
template<class T>
class LCVtoStreamHelperVis : public AListCVVis<T> {
private:
    ostream &_os; // Input parameter.

public:
    explicit LCVtoStreamHelperVis(ostream &os);

    LCVtoStreamHelperVis(const LCVtoStreamHelperVis &rhs) = delete;               // disabled.
    LCVtoStreamHelperVis &operator=(const LCVtoStreamHelperVis &rhs) = delete;    // disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const &host) override;
};

// ========= Constructor =========
template<class T>
LCVtoStreamHelperVis<T>::LCVtoStreamHelperVis(ostream &os): _os(os) {}

// ========= visit =========
template<class T>
void LCVtoStreamHelperVis<T>::visitMTList(AListCV<T> const &) {
    _os << ")";
}

template<class T>
void LCVtoStreamHelperVis<T>::visitNEList(AListCV<T> const &host) {
    auto &neHost = static_cast<const NEListCV<T>&>(host);
    _os << ", " << neHost.first();
    neHost.rest()->accept(*this);
}

// ========= LCVtoStreamVis =========
template<class T>
class LCVtoStreamVis : public AListCVVis<T> {
private:
    ostream &_os; // Input parameter.

public:
    explicit LCVtoStreamVis(ostream &os);

    LCVtoStreamVis(const LCVtoStreamVis &rhs) = delete;               // disabled.
    LCVtoStreamVis &operator=(const LCVtoStreamVis &rhs) = delete;    // disabled.

    void visitMTList(AListCV<T> const  &host) override;
    void visitNEList(AListCV<T> const  &host) override;
};

// ========= Constructor =========
template<class T>
LCVtoStreamVis<T>::LCVtoStreamVis(ostream &os): _os(os) {
}

// ========= visit =========
template<class T>
void LCVtoStreamVis<T>::visitMTList(AListCV<T> const  &) {
    _os << "()";
}

template<class T>
void LCVtoStreamVis<T>::visitNEList(AListCV<T> const  &host) {
    auto &neHost = static_cast<const NEListCV<T>&>(host);
    _os << "(" << neHost.first();
    LCVtoStreamHelperVis<T> toStreamHVis(_os);
    neHost.rest()->accept(toStreamHVis);
}

// ========= operator<< =========
template<class T>
ostream &operator<<(ostream &os, shared_ptr<const AListCV<T>> rhs) {
    static LCVtoStreamVis<T> toStreamVis(os); // static for efficiency.
    rhs->accept(toStreamVis);
    return os;
}

#endif
