#include "../common.hpp"
#define ll long long
void count_square(){
    int m,n;
    cin>>m>>n;
    ll sum = 0,sum1 = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            sum += min(i,j);
            sum1 += i * j;
        }
    }
    cout<<sum<<" "<<sum1 - sum<<endl;
}

void solution(){
    count_square();
}