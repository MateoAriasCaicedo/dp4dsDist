// File: ListCV/LCVremFirstVis.hpp

#ifndef LCVremFirstVis_hpp
#define LCVremFirstVis_hpp

#include "ListCV.hpp"
#include "LCVcloneVis.hpp" // Using another plugin.
using namespace std;

template<class T>
class LCVremFirstVis : public AListCVVis<T> {
    // Post: A pointer to a copy of this list with with the first element removed
    // is returned. An empty list is returned if this list is empty.
private:
    shared_ptr<AListCV<T>> _result; // Output result.

public:
    LCVremFirstVis() = default;

    LCVremFirstVis(const LCVremFirstVis &rhs) = delete;             // Disabled.
    LCVremFirstVis &operator=(const LCVremFirstVis &rhs) = delete;  // Disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    shared_ptr<AListCV<T>> result() const;
};

// ========= visit =========
template<class T>
void LCVremFirstVis<T>::visitMTList(const AListCV<T> &) {
    _result = make_shared<MTListCV<T>>();
}

template<class T>
void LCVremFirstVis<T>::visitNEList(const AListCV<T> &host) {
    const NEListCV<T> &neHost = static_cast<const NEListCV<T>&>(host);
    LCVcloneVis<T> cloneVis;
    neHost.rest()->accept(cloneVis);
    _result = cloneVis.result();
}

// ========= result =========
template<class T>
shared_ptr<AListCV<T>> LCVremFirstVis<T>::result() const {
    return _result;
}

#endif
