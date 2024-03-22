// File: ListCV/LCVisEmptyVis.hpp

#ifndef LCVisEmptyVis_hpp
#define LCVisEmptyVis_hpp

#include "ListCV.hpp"
using namespace std;

template<class T>
class LCVisEmptyVis : public AListCVVis<T> {
private:
    bool _result; // Output result.

public:
    LCVisEmptyVis() = default;

    LCVisEmptyVis(const LCVisEmptyVis &rhs) = delete;               // disabled.
    LCVisEmptyVis &operator=(const LCVisEmptyVis &rhs) = delete;    // disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    [[nodiscard]] bool result() const;
    // Pre: This visitor has been accepted by a host list.
    // Post: true is returned if the host list is empty; Otherwise, false is returned.
};

// ========= visit =========
template<class T>
void LCVisEmptyVis<T>::visitMTList(const AListCV<T> &) {
    _result = true;
}

template<class T>
void LCVisEmptyVis<T>::visitNEList(const AListCV<T> &) {
    _result = false;
}

// ========= result =========
template<class T>
bool LCVisEmptyVis<T>::result() const {
    return _result;
}

#endif
