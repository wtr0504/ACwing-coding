#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;

int a,b;
string s;
int c[10000000];
int cnt;


void solution(){
    cin>>a>>s>>b;
    int e,sum;

    for(int i = 0;i < s.size();i++){
        e = pow(a,s.size() - 1 - i);
        if(s[i] < 'A'){
            e *= s[i] - '0';
            sum += e;
        } else{
            e *= s[i] - 'A' + 10;
            sum += e;
        }
    }
    while(sum > 0){
        c[cnt++] = sum % b;
        sum /= b;
    }
    for(int i = cnt - 1;i >= 0;i--){
        if(c[i] >= 10){
            printf("%c",(c[i] - 10 + 'A'));
        } else{
            printf("%d",(c[i]));
        }
    }
    cout<<endl;
}