#include "../common.hpp"
#include <algorithm>

vector<int> v(200005,0);

int helper(int target,int l,int r){
    
    while(l < r){
        int mid = (l + r)/2;
        if(v[mid] >= target){
            r = mid;
        } else{
            l = mid + 1;
        }
    }
    if(v[l] == target) return 1;
    return 0;
}

void solution(){
    int n,c;
    cin>>n>>c;
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.begin() + n - 1);
    int res = 1;
    int i = 0,j = n-1;
    for(int i = 0;i < n;i++){
        

    }


}