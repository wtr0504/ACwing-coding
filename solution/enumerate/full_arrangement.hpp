#include "../common.hpp"


void full_arrangement(vector<int> path,vector<bool> &visited,int n){
    if(path.size() == n){
        for(auto &num : path){
            cout<<setw(5)<<num;
        }
        cout<<endl;
    }
    for(int i = 0;i < n;i++){
        if(!visited[i]){
            visited[i] = true;
            path.push_back(i + 1);
            full_arrangement(path,visited,n);
            visited[i] = false;
            path.pop_back();
        }
    }
}

void solution(){
    int n;
    cin>>n;
    vector<bool> visited(n,false);
    full_arrangement({},visited,n);
}