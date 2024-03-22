// File: ListCV/LCVmaxVis.hpp

#ifndef LCVmaxVis_hpp
#define LCVmaxVis_hpp

#include "ListCV.hpp"
using namespace std;

template<class T>
class LCVmaxVis : public AListCVVis<T> {
    // Pre: This list is not empty.
    // Post: The maximum element of this list is returned.
private:
    T _result; // Output result.

public:
    LCVmaxVis() = default;

    LCVmaxVis(const LCVmaxVis &rhs) = delete; // Disabled.
    LCVmaxVis &operator=(const LCVmaxVis &rhs) = delete; // Disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    T result() const;
};

// ========= visit =========
template<class T>
void LCVmaxVis<T>::visitMTList(const AListCV<T> &) {
    assert(false);
}

// Zung, I tried this with a max helper, but could not figure out how to polymorphically dispatch a visitor.
// Stan: Take a look at LCVgetMaxVis. It uses what is called "forward accumulation."  See also LCVgetLength.
template<class T>
void LCVmaxVis<T>::visitNEList(const AListCV<T> &host) {
    LCVisEmptyVis<T> isEmptyVis;
    host.rest()->accept(isEmptyVis);
    if (isEmptyVis.result()) {
        _result = host.first();
    }
    else {
        host.rest()->accept(*this);
        _result = host.first() <= result() ? result() : host.first();
    }
}

// ========= result =========
template<class T>
T LCVmaxVis<T>::result() const {
    return _result;
}

#endif
