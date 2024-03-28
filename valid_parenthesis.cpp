#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    // int left=0;
    // int right=0;
    int maxi=0;
    stack<int>stk;
    stk.push(-1);
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
           stk.push(i);
        }
        else{
            stk.pop();
            if(!stk.empty())
            {
                maxi=max(i-stk.top(),maxi);
            }
            else{
                stk.push(i);
            }
            
        }
        // if(left==right)
        // {
        //     maxi=max(maxi,left*2);
        // }
        // if(right>left)
        // {
        //     right=0;
        //     left=0;
        // }
    }
    cout<<maxi<<endl;

}   