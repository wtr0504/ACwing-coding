#include "../common.hpp"


void combine_output(int start,vector<int> path,int r,int n){
    if(start > n) return;
    if(r == path.size()){
        for(auto & num : path){
            cout<<setw(3)<<num;
        }
        cout<<endl;
        return;
    }
    for(int i = start;i < n;i++){
        path.push_back(i + 1);
        combine_output(i + 1,path,r,n);
        path.pop_back();
    }
}

void solution(){
    int n,r;
    cin>>n>>r;
    combine_output(0,{},r,n);
}