#include <iostream>
#include <exception>

class StackOverflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public std::exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int top;

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& value) {
        if (top >= capacity - 1) {
            throw StackOverflowException();
        }
        arr[++top] = value;
    }

    T pop() {
        if (top < 0) {
            throw StackUnderflowException();
        }
        return arr[top--];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }
};

int main() {
    Stack<int> stack(2);

    try {
        stack.push(10);
        stack.push(20);
        stack.push(30);  
    } catch (const std::exception& e) {
        std::cerr << "Pushing to a full stack: " << e.what() << std::endl;
    }

    try {
        stack.pop();
        stack.pop();
        stack.pop();  
    } catch (const std::exception& e) {
        std::cerr << "Popping from an empty stack: " << e.what() << std::endl;
    }

    return 0;
}
