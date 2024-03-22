// File: ListCV/LCVfirstVis.hpp

#ifndef LCVfirstVis_hpp
#define LCVfirstVis_hpp

#include "ListCV.hpp"
using namespace std;

template<class T>
class LCVfirstVis : public AListCVVis<T> {
    // Pre: This list is not empty.
    // Post: The firstimum element of this list is returned.
private:
    T _result; // Output result.

public:
    LCVfirstVis()= default;

    LCVfirstVis(const LCVfirstVis &rhs) = delete;               // Disabled.
    LCVfirstVis &operator=(const LCVfirstVis &rhs) = delete;    // Disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    T result() const;
};


// ========= visit =========
template<class T>
void LCVfirstVis<T>::visitMTList(const AListCV<T> &) {
    assert(false);
}

template<class T>
void LCVfirstVis<T>::visitNEList(const AListCV<T> &host) {
    auto &neHost = static_cast<const NEListCV<T>&>(host); // auto in lieu of const NEListCV<T> to keep it short.
    _result = neHost.first();
}

// ========= result =========
template<class T>
T LCVfirstVis<T>::result() const {
    return _result;
}

#endif
