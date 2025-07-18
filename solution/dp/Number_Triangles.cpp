#include <iostream>

#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll num[1000005];
int r;

void solution(){
    cin>>r;
    int cnt = (1 + r) * r/2;
    for(int i = 1;i <= cnt;i++){
        cin>>num[i];
    }

    for(int i = 2;i <= r;i++){
        for(int j = 1;j <= i;j++){
            if(j == 1){
                num[(i)*(i-1)/2 + j] += num[(i - 1)*(i - 2)/2 + j];
            } else if(j == i){
                num[(1 + i)*i/2] += num[(i - 1)*(i - 2)/2 + j - 1];
            } else {
                num[i * (i-1)/2 + j] += max(num[ (i-1)*(i-2)/2 + j - 1],num[(i-1)*(i-2)/2 + j]);
            }
        }
    }
    cout<<*max_element(num + r * (r-1) / 2 + 1,num + (r+1)*r/2+1)<<endl;;


}

