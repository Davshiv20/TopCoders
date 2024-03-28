#include<bits/stdc++.h>
using namespace std;

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Clear the newline character from the buffer

    while (t-- > 0) {
        string postfix_exp;
        getline(cin, postfix_exp);
        stack<int> stk;

        for (auto i : postfix_exp) {
            if (isdigit(i)) {
                stk.push(i - '0'); // Convert character to integer
            } else if (isOp(i)) {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();

                if (i == '+') {
                    stk.push(y + x);
                } else if (i == '-') {
                    stk.push(y - x);
                } else if (i == '*') {
                    stk.push(y * x);
                } else if (i == '/') {
                    stk.push(y / x);
                }
            }
        }

        cout << stk.top() << endl; // Print the result
    }

    return 0;
}
