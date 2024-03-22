// File: ListCV/LCVprependVis.hpp

#ifndef LCVprependVis_hpp
#define LCVprependVis_hpp

#include "ListCV.hpp"
using namespace std;

template<class T>
class LCVprependVis : public AListCVVis<T> {
private:
    T _val;                         // Input parameter.
    shared_ptr<AListCV<T>> _result; // Output result.

public:
    explicit LCVprependVis(T val);

    LCVprependVis(const LCVprependVis &rhs) = delete;               // disabled.
    LCVprependVis &operator=(const LCVprependVis &rhs) = delete;    // disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    shared_ptr<AListCV<T>> result() const;
    // Pre: This visitor has been accepted by a host list.
    // Post: A pointer to a copy of the host list with val prepended is returned.
};

// ========= Constructor =========

template<class T>
LCVprependVis<T>::LCVprependVis(T val) : _val(val) {}

// ========= visit =========

template<class T>
void LCVprependVis<T>::visitMTList(AListCV<T> const  &host) {
    _result = make_shared<NEListCV<T>>(_val);
}

template<class T>
void LCVprependVis<T>::visitNEList(AListCV<T> const  &host) {
    _result =  make_shared<NEListCV<T>>(_val, host.shared_from_this());
}

// ========= result =========

template<class T>
shared_ptr<AListCV<T>> LCVprependVis<T>::result() const {
    return _result;
}


template<class T>
shared_ptr<AListCV<T>> prepend(shared_ptr<AListCV<T>> list, T data) {
    cerr << "prepend: Exercise for the student." << endl;
    throw -1;
}

#endif
