#include <iostream>
using namespace std;
#define MAX 5

class Stack {
private:
    int A[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Stack is full." << endl;
        }
        else {
            top++;
            A[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty." << endl;
        }
        else {
            cout << A[top] << " popped from stack." << endl;
            top--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            cout << "Top element is: " << A[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--) {
                cout << A[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            if (s.isEmpty())
                cout << "Stack is currently empty." << endl;
            else
                cout << "Stack is not currently empty." << endl;
            break;

        case 6:
            if (s.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
