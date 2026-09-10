#include <iostream>
using namespace std;

#define MAX 50

class Stack{
    char arr[MAX];
    int top;

public:
    Stack(){
        top = -1;
    }

    void push(char ch){
        top++;
        arr[top] = ch;
    }

    char pop(){
        char ch = arr[top];
        top--;
        return ch;
    }

    char peek(){
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};

int priority(char op){
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix){
    Stack s;
    string postfix = "";

    for(char ch : infix){
        if(ch >= '0' && ch <= '9'){
            postfix += ch;
        }
        else{
            while(!s.empty() && priority(s.peek()) >= priority(ch)){
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    while(!s.empty()){
        postfix += s.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix){
    int arr[MAX];
    int top = -1;

    for(char ch : postfix){
        if(ch >= '0' && ch <= '9'){
            arr[++top] = ch - '0';
        }
        else{
            int b = arr[top--];
            int a = arr[top--];

            if(ch == '+')
                arr[++top] = a + b;
            else if(ch == '-')
                arr[++top] = a - b;
            else if(ch == '*')
                arr[++top] = a * b;
            else if(ch == '/')
                arr[++top] = a / b;
        }
    }

    return arr[top];
}

int main(){
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix expression: " << postfix << endl;
    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}