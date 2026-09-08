#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class BrowserHistory{
private:
    string history[MAX];
    int top;

public:
    BrowserHistory(){
        top = -1;
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == MAX - 1;
    }

    void visitPage(string url){
        if(isFull()){
            cout << "History is full!" << endl;
        }
        else{
            top++;
            history[top] = url;
            cout << "Visited: " << url << endl;
        }
    }

    void goBack(){
        if(isEmpty()){
            cout << "No previous page available." << endl;
        }
        else{
            cout << "Going back from: " << history[top] << endl;
            top--;
        }
    }

    void currentPage(){
        if(isEmpty()){
            cout << "No page is currently open." << endl;
        }
        else{
            cout << "Current page: " << history[top] << endl;
        }
    }

    void showHistory(){
        if(isEmpty()){
            cout << "Browsing history is empty." << endl;
        }
        else{
            cout << "Browsing History:" << endl;
            for(int i = top; i >= 0; i--){
                cout << history[i] << endl;
            }
        }
    }
};

int main(){
    BrowserHistory browser;
    int choice;
    string url;

    do{
        cout << "\n===== STUDENT PORTAL BROWSER =====" << endl;
        cout << "1. Visit New Page" << endl;
        cout << "2. Go Back" << endl;
        cout << "3. Display Current Page" << endl;
        cout << "4. Show Browsing History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            browser.visitPage(url);
            break;

        case 2:
            browser.goBack();
            break;

        case 3:
            browser.currentPage();
            break;

        case 4:
            browser.showHistory();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    }while(choice != 5);

    return 0;
}