#include "../common.hpp"
#include <string>
#include <iostream>


using namespace std;
string a1,b1;
int a[50001],b[50001],i,x,len,j,c[50001];
void high_precision_multi (){
    cin >>a1 >>b1;//读入两个数
    for(int i = 1;i <= a1.size();i++) a[i] = a1[a1.size() - i] - '0';
    for(int i = 1;i <= b1.size();i++) b[i] = b1[b1.size() - i] - '0';
    for(int i = 1;i <= a1.size();i++){
        for(int j = 1;j <= b1.size();j++){
            c[i + j -1] += a[i] * b[j];
        }
    }
    int len = a1.size() + b1.size();
    for (int i = 1; i < len; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }

    while (len > 1 && c[len] == 0) len--; // 去除前导 0

    for (int i = len; i >= 1; i--) cout << c[i];
    cout << endl;
}

void solution(){
    high_precision_multi();
}