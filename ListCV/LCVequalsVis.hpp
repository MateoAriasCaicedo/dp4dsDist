// File: ListCV/LCVequalsVis.hpp

#ifndef LCVequalsVis_hpp
#define LCVequalsVis_hpp

#include "ListCV.hpp"
#include "LCVisEmptyVis.hpp" // Using another plugin.
using namespace std;

/**
 * The host list is equal to the right hand side input list iff 
 * they are of the same length and contain the same data element in the same order.
 * 
 * @tparam T Type of data elements in the host list.
 */
template<class T>
class LCVequalsVis : public AListCVVis<T> {

private:
    template<class S>
    class LCVequalsHelpVis : public AListCVVis<S> {

        friend class LCVequalsVis<S>;

        LCVequalsVis<S> &_master;
        shared_ptr<const NEListCV<S>> _neList;
        bool _result;

    public:

        explicit LCVequalsHelpVis (LCVequalsVis<S> &master): _master(master) {}
        
        LCVequalsHelpVis(LCVequalsHelpVis<S> const &rhs) = delete; // Disabled.
        LCVequalsHelpVis &operator=(LCVequalsHelpVis<S> const &rhs) = delete; // Disabled.

        void visitMTList(AListCV<S> const &host) override {
            _result = false;  // Because _neList is not empty.
        }

        void visitNEList(AListCV<S>const &host) override {
            auto &neHost = static_cast<const NEListCV<T>&>(host);
            if (neHost.first() != _neList->first()) {
                _result = false;
            }
            else {
                // Check for equality between the host's rest and the _neList's rest.
                _master._rhs = _neList->rest();
                neHost.rest()->accept(_master);
                _result = _master._result;
            }
        }

        [[nodiscard]] bool result() const {
            return _result;
        }
    };

    friend class LCVequalsHelpVis<T>;

private:
    shared_ptr<LCVequalsHelpVis<T>> _helper;
    shared_ptr<const AListCV<T>>  _rhs; // Input parameter.
    bool _result; // Output result.

public:
    explicit LCVequalsVis(shared_ptr<const AListCV<T>>  rhs);

    LCVequalsVis(LCVequalsVis<T> const &rhs) = delete;              // Disabled.
    LCVequalsVis &operator=(LCVequalsVis<T> const &rhs) = delete;   // Disabled.

    void visitMTList(AListCV<T> const &host) override;
    void visitNEList(AListCV<T> const  &host) override;

    [[nodiscard]] bool result() const;
    // Pre: This visitor has been accepted by a host list.
    // Post: true is returned if the host list equals list rhs;
    // Otherwise, false is returned.
    // Two lists are equal if they contain the same number of equal elements in the same order.
};

// ========= Constructor =========
template<class T>
LCVequalsVis<T>::LCVequalsVis(shared_ptr<const AListCV<T>>  rhs): _rhs(rhs) {
    _helper = make_shared<LCVequalsHelpVis<T>>(*this);
}

// ========= visit =========
template<class T>
void LCVequalsVis<T>::visitMTList(AListCV<T> const &) {
    LCVisEmptyVis<T> isEmptyVis;
    _rhs->accept(isEmptyVis);
    _result = isEmptyVis.result();
}

template<class T>
void LCVequalsVis<T>::visitNEList(AListCV<T> const &host) {
    _helper->_neList = static_pointer_cast<const NEListCV<T>>(host.shared_from_this());
    _rhs->accept(*_helper);
    _result = _helper->_result;
}

// ========= result =========
template<class T>
bool LCVequalsVis<T>::result() const {
    return _result;
}

#endif
