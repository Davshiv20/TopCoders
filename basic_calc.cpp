#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    stack<int> stk;
    int ans = 0;
    int sign = 1;
    long long int curr_val = 0;
    for (auto i : str)
    {
        if (isdigit(i))
        {
            curr_val = 10 * curr_val + (i - '0');
        }

        if (i == '+')
        {
            ans += curr_val * sign;
            curr_val = 0;
            sign = 1;
        }
        else if (i == '-')
        {
            ans += curr_val * sign;
            curr_val = 0;
            sign = -1;
        }
        else if (i == '(')
        {
            stk.push(ans);
            stk.push(sign);
            ans = 0;
            sign = 1;
        }
        else if (i == ')')
        {
            ans += curr_val * sign;
            curr_val = 0;
            ans = ans * stk.top(); // multiplying with a sign;
            stk.pop();
            ans = ans + stk.top(); // adding or subtracting;
            stk.pop();
        }
      
    }
    ans += curr_val * sign;
    cout << ans << endl;
}