#include <iostream>
using namespace std;
template<class t>
/*
o push (elementType element) : void
o pop () : elementType element //return the first element and remove it.
o top () : elementType element //return the first element without removing it.
o isEmpty () : bool
o stackSize () : int
o clear (): void
o print () : void*/
class stack {
private:
    int top;
    t *arr;
    int max_size;
public:
    stack() {
        top = -1;
        max_size = 10;
        arr = new t[max_size];
    }

    //push an element at the end of the stack
    void push(t element) {
//        check if the stack is full
        if (top >= max_size - 1) {

            max_size *= 2;
            t *temp = new t[max_size];
            for (int i = 0; i < max_size; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = new t[max_size];
            arr = temp;
            delete[] temp;
            top++;
            arr[top] = element;

        } else {
            top++;
            arr[top] = element;
        }

    }

    //return the first element and remove it
    t pop() {
        if (top == -1) {
            cout << "stack is empty ... " << endl;
        } else {
            t tmp = arr[top];
            top--;
            return tmp;
        }
    }


    //return the first element without removing it
    t Top() {
        if (top == -1) {
            cout << "stack is empty ... " << endl;
        } else {
            return arr[top];
        }
    }

    //check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    //get the size of the stack
    int stackSize() {
        return top + 1;
    }

    // clear the stack
    void clear() {
        delete[] arr;
        top = -1;
        arr = new t[max_size];
    }

    // print the stack elements
    void print() {
        if (top == -1) {
            cout << "stack is empty ... " << endl;
        } else {
            cout << "[ ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << "]" << endl;
        }
    }

};






