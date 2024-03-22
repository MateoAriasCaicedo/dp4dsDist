// File: ListCV/LCVcloneVis.hpp

#ifndef LCVcloneVis_hpp
#define LCVcloneVis_hpp

#include "ListCV.hpp"
using namespace std;

template<class T>
class LCVcloneVis : public AListCVVis<T> {
private:
    shared_ptr<AListCV<T>>  _result; // Output result.

public:
    LCVcloneVis() = default;

    LCVcloneVis(LCVcloneVis const &rhs) = delete;            // disabled.
    LCVcloneVis &operator=(LCVcloneVis const &rhs) = delete; // disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const &host) override;

    shared_ptr<AListCV<T>>  result() const;
    // Pre: This visitor has been accepted by a host list.
    // Post: A pointer to a copy of the host list is returned.
};

// ========= visit =========
template<class T>
void LCVcloneVis<T>::visitMTList(AListCV<T> const &) {
    _result = make_shared<MTListCV<T>>();
}

template<class T>
void LCVcloneVis<T>::visitNEList(AListCV<T> const &host) {
    const NEListCV<T> &neHost = static_cast<const NEListCV<T>&>(host);  // can use auto in lieu of const NEListCV<T>
                                                                        // on the left-hand-side.
    neHost.rest()->accept(*this);
    _result = make_shared<NEListCV<T>>(neHost.first(), _result);
}

// ========= result =========
template<class T>
shared_ptr<AListCV<T>> LCVcloneVis<T>::result() const {
    return _result;
}

#endif
