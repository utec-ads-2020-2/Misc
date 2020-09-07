#ifndef DEBUGGER_H
#define DEBUGGER_H

using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"     
#define RED     "\033[31m" 

template<typename T>
class Debugger {
    int* arr;
    int size;

    void print(T value, T*& ptr) {
        cout << RED << value << "[" << ptr << "]: " << RESET; 
    }

    void log(T* arr, int size) {
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << "[" << arr + i << "] " << "\t";
        }
        cin.ignore();
    }

    public:
    Debugger(int* arr, int size) {
        this->arr = arr;
        this->size = size;
    }

    void out(T value, T*& ptr) {
        print(value, ptr); 
        log(arr, size); 
    }
};

#endif