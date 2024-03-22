// File: ListCV/ListCV.hpp

#ifndef LISTCV_HPP_
#define LISTCV_HPP_

#include <iostream> // ostream.
#include <cassert>
#include <memory>
using namespace std;

#include "AListCV.hpp"

// ========= The empty (MT) list =========
template<class T>
class MTListCV : public AListCV<T> {

public:
    MTListCV() = default;
    MTListCV(MTListCV<T> const &rhs) = delete; // Disabled.
    MTListCV &operator=(MTListCV<T> const &rhs) = delete; // Disabled.

    void accept(AListCVVis<T> &visitor) const override;
};

// ========= The non-empty(NE) list =========
template<class T>
class NEListCV : public AListCV<T> {
private:
    T _first;
    shared_ptr<const AListCV<T>> _rest;

public:
    explicit NEListCV(T first);
    // Post: This list exists and contains exactly one element, first.

    NEListCV(T first, shared_ptr<const AListCV<T>> rest);
    // Pre: rest != nullptr
    // Post: This list exists and contains first and rest.

    NEListCV(NEListCV<T> const &rhs) = delete; // Disabled.
    NEListCV &operator=(NEListCV<T> const &rhs) = delete; // Disabled.

    T const &first() const;
    shared_ptr<const AListCV<T>> rest() const;
    void accept(AListCVVis<T> &visitor) const override;
};

// ========= Constructors =========
template<class T>
NEListCV<T>::NEListCV(T first): _first(first) , _rest(new MTListCV<T>()) {
}

template<class T>
NEListCV<T>::NEListCV(T first, shared_ptr<const AListCV<T>> rest):      _first (first), _rest(rest) {
}

// ========= first and rest =========
template<class T>
T const &NEListCV<T>::first() const {
    return _first;
}

template<class T>
shared_ptr<const AListCV<T>> NEListCV<T>::rest() const {
    return _rest;
}

// ========= accept =========
template<class T>
void MTListCV<T>::accept(AListCVVis<T> &visitor) const {
    visitor.visitMTList(*this);
}

template<class T>
void NEListCV<T>::accept(AListCVVis<T> &visitor) const {
    visitor.visitNEList(*this);
}

#endif
