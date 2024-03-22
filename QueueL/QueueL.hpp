// File: QueueL/QueueL.hpp

#ifndef QueueL_HPP_
#define QueueL_HPP_

#include <iostream> // ostream.

#include "AQueue.hpp"
#include "ListL.hpp"

using namespace std;

// ========= QueueL =========
template<class T>
class QueueL: public AQueue<T> {
private:
    // Attribute is exercise for the student.
public:
    QueueL(int cap = 1);
    T dequeue() override;
    void enqueue(T const &val) override;
    T const &headOf() const override;
    bool isEmpty() const override;
    bool isFull() const override;
    void toStream(ostream &os) const override;
};

// ========= Constructor =========
template<class T>
QueueL<T>::QueueL(int cap):
    _listL(),
    _length(0),
    _cap(cap){
}

// ========= dequeue =========
template<class T>
T QueueL<T>::dequeue() {
    cerr << "QueueL<T>::dequeue: Exercise for the student." << endl;
    throw -1;
}

// ========= enqueue =========
template<class T>
void QueueL<T>::enqueue(T const &val) {
    cerr << "QueueL<T>::enqueue: Exercise for the student." << endl;
    throw -1;
}

// ========= headOf =========
template<class T>
T const &QueueL<T>::headOf() const {
    cerr << "QueueL<T>::headOf: Exercise for the student." << endl;
    throw -1;
}

// ========= isEmpty =========
template<class T>
bool QueueL<T>::isEmpty() const {
    cerr << "QueueL<T>::isEmpty: Exercise for the student." << endl;
    throw -1;
}

// ========= isFull =========
template<class T>
bool QueueL<T>::isFull() const {
    cerr << "isFull: Exercise for the student." << endl;
    throw -1;
}

// ========= operator<< =========
template<class T>
ostream &operator<<(ostream &os, QueueL<T> const &rhs) {
    cerr << "operator<<: Exercise for the student." << endl;
    throw -1;
}

// ========= toStream =========
template<class T>
void QueueL<T>::toStream(ostream &os) const {
    cerr << "QueueL<T>::toStream: Exercise for the student." << endl;
    throw -1;
}

#endif
