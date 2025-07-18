#include <bits/stdc++.h>

using namespace std;

unsigned int a,b;

void solution(){
    cin>>a;
    b = a << 16;
    a >>= 16;
    a = a | b ;
    cout<<a<<endl;
}