#include "../common.hpp"

vector<int> nums(1000,-1);


void ming_nums(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        int m;
        cin>>m;
        nums[m] = 1;
    }

    for(int i = 0;i < 1000;i++){
        if(nums[i] != -1){
            cout<<nums[i];
        }
    }
}

void solution(){
    ming_nums();
}