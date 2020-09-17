#ifndef LIST_H
#define LIST_H

#include <stdexcept>

using namespace std;

template <typename Tr>
class Element {
    typedef typename Tr::dataType T;
    typedef typename Tr::Operation Operation; 

    Operation compare;
    T* element;

    public: 
        Element() {
            element = nullptr;
        }

        void set(T* element) {
            if (!this->element || compare(*element, *this->element)) {
                this->element = element;
            }
        }

        T get() {
            if (!element) {
                throw runtime_error("Null pointer");
            }
            return *element;
        }
};

#endif