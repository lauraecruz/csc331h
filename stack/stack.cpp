#include "stack.h"

template <class T> Stack<T>::Stack() {
  top = nullptr;
  capacity = 0;
}

template <class T> Stack<T>::~Stack() {
  initializeStack();
  cout << "Destructor called" << endl;
}

template <class T> Stack<T>::Stack(const Stack<T> &other) {
  copyStack(other);
}

template <class T> void Stack<T>::operator=(const Stack<T> &other) {
  if (this == &other) {
    cerr << "Both Stacks are the same" << endl;
    return;
  } else {
     initializeStack();
     copyStack(other);
  }
}

template <class T> bool Stack<T>::isFullStack() {
  return false; // stack is technically never full
}

template <class T> bool Stack<T>::isEmptyStack() {
   return capacity == 0;
}

template <class T> void Stack<T>::initializeStack() {
  if (isEmptyStack()) {
    cerr << "Stack is empty" << endl;
    return;
  } else {
    Node<T> *temp;

    while (top != nullptr) {
      temp = top;
      top = top->down;
      delete temp;
    }
    capacity = 0;
  }
}

template <class T> void Stack<T>::push(T item) {

  if (isFullStack()) {
    cerr << "Stack is full" << endl;
    return;
  } else if (isEmptyStack()) {
    top = new Node<T>;
    top->info = item;
    top->down = nullptr;
    capacity++;
    cout << "Successfully inserted item" << endl;
  } else {
    Node<T> *newNode = new Node<T>;

    newNode->info = item;
    newNode->down = top;
    top = newNode;

    capacity++;

    cout << "Successfully inserted item" << endl;
  }
}

template <class T> void Stack<T>::pop() {

  if (isEmptyStack()) {
    cerr << "Stack is empty, cannot retrieve" << endl;
    return;
  } else if(capacity == 1) {
      delete top;
      top = nullptr;
  } else {
    Node<T> *temp = top;
    top = top->down;
    delete temp;

    capacity--;

    cout << "Successfully deleted item" << endl;
  }
}

template <class T> T Stack<T>::_top() { return top->info; }

template <class T> void Stack<T>::copyStack(const Stack<T> &other) {
  if (other.capacity == 0) {
    cerr << "Cannot copy, is empty" << endl;
    return;
  } else if (this == &other) {
    cerr << "Both are the same, cannot copy" << endl;
    return;
  } else {
     capacity = other.capacity;

    top = new Node<T>;
    top->info = other.top->info;
    top->down = nullptr;

    Node<T> *other_temp = other.top->down;
    Node<T> *this_temp = top;

    while(other_temp != nullptr)
    {
      this_temp->down = new Node<T>;
      this_temp->down->info = other_temp->info;
      this_temp->down->down = nullptr;

      this_temp = this_temp->down;
      other_temp = other_temp->down;
   }

  }
}
