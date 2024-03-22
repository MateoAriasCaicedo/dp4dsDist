// File: ListCV/ListCVMain.cpp

#include <iostream>
#include <cstdlib> // EXIT_SUCCESS.
#include <cctype> // toupper.
using namespace std;

#include "Utilities.hpp" // promptIntBetween.
#include "ArrayT.hpp"
#include "ListCV.hpp"
#include "LCVprependVis.hpp"
#include "LCVtoStreamVis.hpp"
#include "LCVcloneVis.hpp"
#include "LCVappendVis.hpp"
#include "LCVconcatVis.hpp"
#include "LCVcontainsVis.hpp"
#include "LCVisEmptyVis.hpp"
#include "LCVequalsVis.hpp"
#include "LCVfirstVis.hpp"
#include "LCVlengthVis.hpp"
#include "LCVgetLengthVis.hpp"
#include "LCVmaxVis.hpp"
#include "LCVgetMaxVis.hpp"
#include "LCVreverseVis.hpp"
#include "LCVremFirstVis.hpp"
#include "LCVremLastVis.hpp"

const int NUM_LISTS = 5;
bool getValidSourceDest(int &s, int &d); // Forward declaration.

typedef AListCV<int> AListInt;
typedef ArrayT<shared_ptr<AListInt>> ArrayOfListIntP; // An array of shared pointers to AListInt.
typedef MTListCV<int> MTListCVInt;
typedef NEListCV<int> NEListCVInt;

int main() {
    ArrayOfListIntP lists(NUM_LISTS);
    int value;
    int listNum, source, dest;
    for (int i = 0; i < NUM_LISTS; i++) {
        lists[i] = make_shared<MTListCVInt>();
    }


    char response;
    do {
        cout << "\nThere are [0.." << NUM_LISTS - 1 << "] immutable lists." << endl;
        cout << "cl(o)ne       (p)repend      (a)ppend  conca(t)enate  (r)everse  len(g)th\n"
             << "(e)mpty       co(n)tains     equa(l)   (m)ax          (f)irst    removeF(i)rst\n"
             << "removeLa(s)t  RemoveVal(u)e  (z)ip     e(v)en         od(d)      (w)rite\n"
             << "(q)uit: ";
        cin >> response;
        switch (toupper(response)) {
        case 'O':
            if (getValidSourceDest(source, dest)) {
                LCVcloneVis<int> cloneVis;
                lists[source]->accept(cloneVis);
                lists[dest] = cloneVis.result();
            }
            break;
        case 'P':
        {
            cout << "Integer to prepend: ";
            cin >> value;
            if (getValidSourceDest(source, dest)) {
                LCVprependVis<int> prependVis(value);
                lists[source]->accept(prependVis);
                lists[dest] = prependVis.result();
            }
        }
        break;
        case 'A':
        {
            int value;
            cout << "Integer to append: ";
            cin >> value;
            if (getValidSourceDest(source, dest)) {
                LCVappendVis<int> appendVis(value);
                lists[source]->accept(appendVis);
                lists[dest] = appendVis.result();
            }
        }
        break;
        case 'T':
            listNum = promptIntBetween("Suffix list? ", 0, NUM_LISTS - 1);
            if (getValidSourceDest(source, dest)) {
                if (listNum != source && listNum != dest) {
                    LCVconcatVis<int> concatVis(lists[listNum]);
                    lists[source]->accept(concatVis);
                    lists[dest] = concatVis.result();
                }
                else {
                    cout << "\nThe lists must be distinct." << endl;
                }
            }
            break;
        case 'R':
            if (getValidSourceDest(source, dest)) {
                LCVreverseVis<int> reverseVis;
                lists[source]->accept(reverseVis);
                lists[dest] = reverseVis.result();
            }
            break;
        case 'G':
        {
            listNum = promptIntBetween("Length of which list? ", 0, NUM_LISTS - 1);
//                LCVlengthVis<int> lengthVis;
            LCVgetLengthVis<int> lengthVis;
            lists[listNum]->accept(lengthVis);
            cout << "\nThe length of the list is " << lengthVis.result() << endl;
        }
        break;
        case 'E':
        {
            listNum = promptIntBetween("Test which list? ", 0, NUM_LISTS - 1);
            LCVisEmptyVis<int> isEmptyVis;
            lists[listNum]->accept(isEmptyVis);
            if (isEmptyVis.result()) {
                cout << "\nThe list is empty." << endl;
            }
            else {
                cout << "\nThe list is not empty." << endl;
            }
        }
        break;
        case 'N':
        {
            int value;
            cout << "Search for what integer value? ";
            cin >> value;
            listNum = promptIntBetween("Search which list? ", 0, NUM_LISTS - 1);
            LCVcontainsVis<int> containsVis(value);
            lists[listNum]->accept(containsVis);
            if (containsVis.result()) {
                cout << "\nThe list contains " << value << "." << endl;
            }
            else {
                cout << "\nThe list does not contain " << value << "." << endl;
            }
        }
        break;
        case 'L':
        {
            source = promptIntBetween("Source list? ", 0, NUM_LISTS - 1);
            dest = promptIntBetween("Destination list? ", 0, NUM_LISTS - 1);
            LCVequalsVis<int> equalsVis(lists[dest]);
            lists[source]->accept(equalsVis);
            if (equalsVis.result()) {
                cout << "\nThe lists are equal." << endl;
            }
            else {
                cout << "\nThe lists are not equal." << endl;
            }
        }
        break;
        case 'M':
        {
            listNum = promptIntBetween("List to get max from? ", 0, NUM_LISTS - 1);
            LCVisEmptyVis<int> isEmptyVis;
            lists[listNum]->accept(isEmptyVis);
            if (isEmptyVis.result()) {
                cout << "\nThe list is empty." << endl;
            }
            else {
//                    LCVmaxVis<int> maxVis;
                LCVgetMaxVis<int> maxVis;
                lists[listNum]->accept(maxVis);
                cout << "\nThe maximum element is " << maxVis.result() << endl;
            }
        }
        break;
        case 'F':
        {
            listNum = promptIntBetween("List to get first from? ", 0, NUM_LISTS - 1);
            LCVisEmptyVis<int> isEmptyVis;
            lists[listNum]->accept(isEmptyVis);
            if (isEmptyVis.result()) {
                cout << "\nThe list is empty." << endl;
            }
            else {
                LCVfirstVis<int> firstVis;
                lists[listNum]->accept(firstVis);
                cout << "\nThe first element is " << firstVis.result() << endl;
            }
        }
        break;
        case 'I':
            if (getValidSourceDest(source, dest)) {
                LCVremFirstVis<int> remFirstVis;
                lists[source]->accept(remFirstVis);
                lists[dest] = remFirstVis.result();
            }
            break;
        case 'S':
            if (getValidSourceDest(source, dest)) {
                LCVremLastVis<int> remLastVis;
                lists[source]->accept(remLastVis);
                lists[dest] = remLastVis.result();
            }
            break;
//        case 'U':
//            cout << "Integer to remove: ";
//            cin >> value;
//            if (getValidSourceDest(source, dest)) {
//                delete lists[dest];
//                lists[dest] = lists[source]->remove(value);
//            }
//            break;
//        case 'Z':
//            listNum = promptIntBetween("Shuffle list?", 0, iNUM_LISTS - 1);
//            if (getValidSourceDest(source, dest)) {
//                if (listNum != source && listNum != dest) {
//                    delete lists[dest];
//                    lists[dest] = lists[source]->zip(lists[listNum]);
//                }
//                else {
//                    cout << "The lists must be distinct." << endl;
//                }
//            }
//            break;
//            case 'V':
//                if (getValidSourceDest(source, dest)) {
//                    delete lists[dest];
//                    lists[dest] = lists[source]->evenIndex();
//                }
//                break;
//        case 'D':
//            if (getValidSourceDest(source, dest)) {
//                delete lists[dest];
//                lists[dest] = lists[source]->oddIndex();
//            }
//            break;
        case 'W':
            listNum = promptIntBetween("List to write? ", 0, NUM_LISTS - 1);
            cout << "\n";
            LCVtoStreamVis<int> toStreamVis(cout);
            lists[listNum]->accept(toStreamVis);
            cout << endl;
            break;
        }
    }
    while (toupper(response) != 'Q');
    return EXIT_SUCCESS;
}

bool getValidSourceDest(int &s, int &d) {
    s = promptIntBetween("Source list?", 0, NUM_LISTS - 1);
    d = promptIntBetween("Destination list?", 0, NUM_LISTS - 1);
    if (s == d) {
        cout << "The lists must be distinct." << endl;
        return false;
    }
    return true;
}
