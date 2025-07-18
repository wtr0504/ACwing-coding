#include <bits/stdc++.h>


using namespace std;

int n,m;
char a[100001];
int cnt = 0;
void solution(){
    cin>>n>>m;
    cout<<n<<"=";
    
    while(n){
        int j = n % m;
        n /= m;
        if(j < 0){
            j -= m;
            n++;
        }
        if(j < 10) a[cnt++] = j;
        else {
            a[cnt++] = j - 10 + 'A';
        }
    }

    for(int i = cnt - 1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;

}