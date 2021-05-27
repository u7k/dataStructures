// Uygur Kiran - 2021/05/21
#include <iostream>
#include <stack>
using namespace std;

/**
 * syntax check for the bounds of an expr.
 * e.g. {} () [] {()} -> true
 *      [) {) {() )(  -> false
 * @return bool
 */
 bool isBalanced(string str) {
     char open[5] = {'{', '(', '[', '<', '\0'};
     char close[5] = {'}', ')', ']', '>', '\0'};

     stack<char> s;
     int charCount = str.length();
     char temp;

     for (int i = 0; i<charCount; i++) {
         if (isspace(str[i])) continue;

        if (find(begin(open), end(open), str[i]) != end(open)) {
            s.push(str[i]);
            continue;
        } else if (find(begin(close), end(close), str[i]) != (end(close))) {
            if (s.empty()) return false;
            switch (str[i]) {
                case '}':
                    temp = s.top();
                    s.pop();
                    if (temp != open[0]) return false;
                    break;
                case ')':
                    temp = s.top();
                    s.pop();
                    if (temp != open[1]) return false;
                    break;
                case ']':
                    temp = s.top();
                    s.pop();
                    if (temp != open[2]) return false;
                    break;
                case '>':
                    temp = s.top();
                    s.pop();
                    if (temp != open[3]) return false;
                    break;
            }
        }
     }
     return s.empty();
 }

// run /////////////
int main() {
     char inp[100] = "";
     do {

     cout << endl << "Enter expression: ";
     cin.getline(inp, sizeof(inp));
     string res = isBalanced(inp) ? "*** BALANCED ***" : "*** NOT BALANCED ***";
     cout << res;

     } while (strlen(inp) > 1);

    return 0;
}