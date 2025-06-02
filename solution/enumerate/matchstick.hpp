#include "../common.hpp"

vector<int> matchstick_num = {6,2,5,5,4,5,6,3,7,6};
vector<int> c(2000,0);
void matchstick(){
    int res = 0;
    int n;
    cin>>n;
    c[0] = 6;
    for(int i = 0;i <= 2000;i++){
        for(int j = i;j > 0; j /= 10){
            c[i] += matchstick_num[j % 10];
        }
    }

    for(int i = 0;i <= 1000;i++){
        for(int j = 0;j <= 1000;j++){
            if(c[i] + c[j] + c[i + j] + 4 == n){
                res++;
            }
        }
    }
    cout<<res<<endl;
}


void solution(){
    matchstick();
}