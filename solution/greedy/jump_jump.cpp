#include "../common.hpp"
#include <algorithm>
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
    sort(v.begin() + 1,v.begin() + n + 1);
    int i = 0,j = n;
    bool l2r = true;
    while(i < j){
        if(l2r){
            res += (long long)(pow(v[j] - v[i],2));
            i++;
            l2r = false;
        } else{
            res += (long long)(pow(v[j] - v[i], 2));
            j--;
            l2r = true;
        }
    }
    cout<<res<<endl;
}