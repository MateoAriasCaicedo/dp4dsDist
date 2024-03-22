// File: QueueA/QueueA.hpp

#ifndef QueueA_HPP_
#define QueueA_HPP_

#include "AQueue.hpp"
#include "ArrayT.hpp"

// ========= QueueA =========
/**
 * A circular queue implemented as an array.
 * @tparam T
 */
template<class T>
class QueueA: public AQueue<T> {
private:
    ArrayT<T> _data;
    int _head, _tail;

public:
    explicit QueueA(int cap = 1);
    T dequeue() override;
    void enqueue(T const &val) override;
    T const &headOf() const override;
    bool isEmpty() const override;
    bool isFull() const override;
    void toStream(ostream &os) const override;
};

// ========= Constructor =========
template<class T>
QueueA<T>::QueueA(int cap) :
    _data(cap + 1),
    _head(0),
    _tail(0) {
}

// ========= dequeue =========
template<class T>
T QueueA<T>::dequeue() {
    cerr << "dequeue: Exercise for the student." << endl;
    throw -1;
}

// ========= enqueue =========
template<class T>
void QueueA<T>::enqueue(T const &val) {
    cerr << "enqueue: Exercise for the student." << endl;
    throw -1;
}

// ========= headOf =========
template<class T>
T const &QueueA<T>::headOf() const {
    cerr << "headOf: Exercise for the student." << endl;
    throw -1;
}

// ========= isEmpty =========
template<class T>
bool QueueA<T>::isEmpty() const {
    cerr << "isEmpty: Exercise for the student." << endl;
    throw -1;
}

// ========= isFull =========
template<class T>
bool QueueA<T>::isFull() const {
    cerr << "isFull: Exercise for the student." << endl;
    throw -1;
}

// ========= operator<< =========
template<class T>
ostream &operator<<(ostream &os, QueueA<T> const &rhs) {
    rhs.toStream(os);
    return os;
}

// ========= toStream =========
template<class T>
void QueueA<T>::toStream(ostream &os) const {
    cerr << "toStream: Exercise for the student." << endl;
    throw -1;
}

#endif
