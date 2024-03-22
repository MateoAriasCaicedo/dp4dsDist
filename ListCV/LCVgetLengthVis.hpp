// File: ListCV/LCVgetLengthVis.hpp

#ifndef LCVgetLengthVis_hpp
#define LCVgetLengthVis_hpp

#include <iostream>
using namespace std;

#include "ListCV.hpp"

/**
 * Calls a helper that accumulates the length of the list,
 * as it traverses down the list.
 */
template<class T>
class LCVgetLengthVis : public AListCVVis<T> {
private:
    int _result;  // output

public:
    LCVgetLengthVis() = default;

    LCVgetLengthVis(const LCVgetLengthVis &rhs) = delete;               // Disabled.
    LCVgetLengthVis &operator=(const LCVgetLengthVis &rhs) = delete;    // Disabled.

    void visitMTList(AListCV<T> const &mtl) override;
    void visitNEList(AListCV<T> const  &nel) override;

    [[nodiscard]] int result() const;
};

/**
 * Helper class doing forward accumulation to compute the length of the list.
 */
template<class T>
class LCVgetLengthVisHelp : public AListCVVis<T> {
private:
    int _result;
    int _acc;  // accumulated length.

public:
    explicit LCVgetLengthVisHelp(int acc);

    LCVgetLengthVisHelp(const LCVgetLengthVisHelp &rhs) = delete;               // Disabled.
    LCVgetLengthVisHelp &operator=(const LCVgetLengthVisHelp &rhs) = delete;    // Disabled.

    void visitMTList(const AListCV<T> &mtl) override;
    void visitNEList(const AListCV<T> &nel) override;

    [[nodiscard]] int result() const;
};

template<class T>
LCVgetLengthVisHelp<T>::LCVgetLengthVisHelp(int acc) : _acc(acc) {}

// ========= visit =========
template<class T>
void LCVgetLengthVis<T>::visitMTList(const AListCV<T> &mtl) {
    _result = 0;
}

template<class T>
void LCVgetLengthVis<T>::visitNEList(const AListCV<T> &nel) {
    auto &neHost = static_cast<const NEListCV<T>&>(nel); // auto in lieu of const NEListCV<T> for shortness.
    LCVgetLengthVisHelp<T> glh(1);
    neHost.rest()->accept(glh);
    _result = glh.result();
}

template<class T>
void LCVgetLengthVisHelp<T>::visitMTList(const AListCV<T> &mtl) {
    _result = _acc;
}

template<class T>
void LCVgetLengthVisHelp<T>::visitNEList(const AListCV<T> &nel) {
    auto &neHost = static_cast<const NEListCV<T>&>(nel);
    ++_acc;
    neHost.rest()->accept(*this);
    _result = result();
}

// ========= result =========
template<class T>
int LCVgetLengthVis<T>::result() const {
    return _result;
}

template<class T>
int LCVgetLengthVisHelp<T>::result() const {
    return _result;
}

#endif
