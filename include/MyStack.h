#ifndef MYSTACK_H
#define MYSTACK_H

//***************************************//
//static stack template                  //
//finish all functions                   //
//***************************************//

#include <iostream>

template <class T>
class MyStack
{
private:
   T *stackArray;  // Pointer to the stack array
   int stackSize;    // The stack size
   int numElem;		//index of the top element in the stack array

public:
   // Constructor
   MyStack(int);	//pass in an int: tells the maximum size of the stack

   // Copy constructor
   MyStack(const MyStack &);

   //operator= overloading
   MyStack& operator=(const MyStack &);

   // Destructor
   ~MyStack();

   // Stack operations
   void push(T);	//add an item to the stack by passing in a value
   T pop();	//pop a value out by returning the value
   T top();	//return the value at the top position in the stack
   bool isFull() const;	//tell if the statck is full
   bool isEmpty() const;	//tell if the stack is empty
   int size() const;	//tell how many items are in the stack
};

//YOUR CODE
//......

template <class T> MyStack<T>::MyStack(int i) {
    stackArray = new T[i];
    stackSize = i;
    numElem = -1;
}

template <class T>
MyStack<T>::MyStack(const MyStack& rhs) {
   stackSize = rhs.size();
   stackArray = new T[stackSize];
   for(int i = 0; i < stackSize; ++i) {
      stackArray[i] = rhs.stackArray[i];
   }
   numElem = stackSize - 1;
}

template <class T>
MyStack<T>& MyStack<T>::operator=(const MyStack<T>& rhs) {
   (*this) = MyStack<T>(rhs);
}

template <class T>
MyStack<T>::~MyStack() {
   delete [] stackArray;
}

template <class T>
void MyStack<T>::push(T cur) {	//add an item to the stack by passing in a value
   if (numElem + 1 >= stackSize) throw "Stack is Full";
   else stackArray[++numElem] = cur;
}

template <class T>
T MyStack<T>::pop() {	//pop a value out by returning the value
   return stackArray[numElem--];
}

template <class T>
T MyStack<T>::top() {	//return the value at the top position in the stack
   return stackArray[numElem];
}

template <class T>
bool MyStack<T>::isFull() const { //tell if the statck is full
   if (numElem + 1 >= stackSize) return true;
   else return false;
}

template <class T>
bool MyStack<T>::isEmpty() const {	//tell if the stack is empty
 if (numElem == -1) return true;
 else return false;
}

template <class T>
int MyStack<T>::size() const {	//tell how many items are in the stack
   return numElem + 1;
}

#endif