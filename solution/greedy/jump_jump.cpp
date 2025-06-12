#include "../common.hpp"
#include <cmath>
#include <vector>


vector<int> v(300 + 5);
void solution(){
    int n;
    cin>>n;
    long long res = 0;
    for(int i = 1;i <= n;i++){
        cin>>v[i];
    }
    int i = 0,j = n;
    bool l2r = true;
    while(i < j){
        if(l3r){
            res += (long long)(pow(v[j] - v[i],2));
        }
    }

}