// Uygur Kiran

#include <iostream>
#include <stack>
using namespace std;

void reverse(char txt[], int charCount) {
    stack<char> chars;

    // push
    for (int i = 0; i < charCount; i++) {
        chars.push(txt[i]);
    }

    // pop
    for (int i = 0; i < charCount; i++) {
        txt[i] = chars.top(); // change char at idx
        chars.pop();
    }
}

int main() {
    cout << "enter a string to reverse: ";
    char txt[51];
    cin >> txt;

    reverse(txt, strlen(txt));
    cout << endl << "RESULT: " << txt << endl << endl;

    return 0;
}