#include "../common.hpp"
#include <string>
#include <vector>
#include <iostream>


void high_precision(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    vector<int> res;
    int c = 0;
    int cur = 0;
    int i = a.size() - 1,j = b.size() - 1;
    while(i >= 0 && j >= 0){
        cur = a[i--] + b[j--] + c - '0' * 2;
        c  = cur / 10;
        cur %= 10;
        res.push_back(cur);
    }
    while(i >= 0){
        cur = a[i--] + c - '0';
        c = cur / 10;
        cur %= 10;
        res.push_back(cur);
    }
    while(j >= 0){
        cur = b[j--] + c - '0';
        c = cur / 10;
        cur %= 10;
        res.push_back(cur);
    }
    if(c != 0){
        res.push_back(c);
    }
    for(int i = res.size() - 1;i >= 0;i--){
        cout<<res[i];
    }
    cout<<endl;
}

void solution(){
    high_precision();
}