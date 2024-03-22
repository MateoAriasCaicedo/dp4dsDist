// File: ListCV/LCVappendVis.hpp

#ifndef LCVappendVis_hpp
#define LCVappendVis_hpp

#include "ListCV.hpp"
using namespace std;

template<class T>
class LCVappendVis : public AListCVVis<T> {
private:
    T _val;                         // Input parameter.
    shared_ptr<AListCV<T>> _result; // Output result.

public:
    explicit LCVappendVis(T val);

    LCVappendVis(LCVappendVis const &rhs) = delete;             // disabled.
    LCVappendVis &operator=(LCVappendVis const &rhs) = delete; // disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    shared_ptr<AListCV<T>>  result() const;
    // Pre: This visitor has been accepted by a host list.
    // Post: A pointer to a copy of the host list with val appended is returned.
};

// ========= Constructor =========
template<class T>
LCVappendVis<T>::LCVappendVis(T val): _val(val) {}

// ========= visit =========
template<class T>
void LCVappendVis<T>::visitMTList(AListCV<T>  const &host) {
    _result = make_shared<NEListCV<T>>(_val);
}

template<class T>
void LCVappendVis<T>::visitNEList(AListCV<T>  const &host) {
    const NEListCV<T> &neHost = static_cast<const NEListCV<T>&>(host);  // can use auto in lieu of const NEListCV<T>
                                                                        // on the left-hand-side.
    neHost.rest()->accept(*this);  // result() is the list with val appended to host.rest.
    _result = make_shared<NEListCV<T>>(neHost.first(), _result);
}

// ========= result =========
template<class T>
shared_ptr<AListCV<T>> LCVappendVis<T>::result() const {
    return _result;
}

#endif
