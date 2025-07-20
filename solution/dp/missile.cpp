#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int a[105];
int d1[105],d2[105];
int res1,res2;
int cnt = 0;

int f1(){
    int len = 1;
    d1[1] = a[1];
    for(int i = 2;i <= cnt;i++){
        if(a[i] <= d1[len]){
            d1[++len] = a[i];
        } else {
            auto x = upper_bound(d1 + 1,d1 + 1 + len,a[i],greater<int>()); //用upper_bound是为了找第一个< a[i]的，用lower_bound是为了找第一个大于等于a[i]的
            *x = a[i];
        }
    }
    return len;
}

int f2(){
    int len = 1;
    d2[len] = a[1];
    for(int i = 2;i <= cnt;i++){
        if(a[i] > d2[len]){
            d2[++len] = a[i];
        } else {
            auto x = lower_bound(d2 + 1,d2 + 1 + len,a[i]);
            *x = a[i];
        }
    }
    return len;
}


void solution(){
    int c;
    while(cin>>c){
        a[++cnt] = c;
    }
    cout<<f1()<<endl<<f2()<<endl;
}