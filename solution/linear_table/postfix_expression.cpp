#include <bits/stdc++.h>
#include <stack>
#include "../common.hpp"

int res;


void solution(){
    stack<int> s;
    string str;
    cin>>str;
    int n = str.size();
    int i = 0;
    while(str[i] != '@'){
        int tmp = 0;
        // int j = 1;
        if(str[i] <= '9' && str[i] >= '0'){
            int tmp = 0;
            while(str[i] <= '9' && str[i] >= '0'){
                tmp = tmp * 10 + str[i] - '0';
                i++;
            }
            s.push(tmp);
        }

        if(str[i] == '*'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b * a);
        } else if(str[i] == '-'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b - a);
        } else if(str[i] == '+'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b + a);
        } else if(str[i] == '/'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(b / a);
        }
        i++;
    }
    cout<<s.top()<<endl;
}