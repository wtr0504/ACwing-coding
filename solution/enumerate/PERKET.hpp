#include "../common.hpp"



void helper(vector<pair<int,int>> &data,vector<bool>& visited,int start,int &res,pair<int,int> path){
    int n = data.size();
    if(start >= n) return;
    for(int i = start;i < n;i++){
        if(!visited[i]){
            path.first *= data[i].first;
            path.second += data[i].second;
            visited[i] = true;
            res = min(res,abs(path.first - path.second));
            helper(data,visited,i + 1,res,path);
            visited[i] = false;
            path.first /= data[i].first;
            path.second -= data[i].second;
        }
    }
}

void PERKET(){
    int n;
    cin>>n;
    vector<pair<int,int>> pre_sum(n);
    vector<bool> visited(n,false);
    for(int i = 0;i < n;i++){
        int a,b;
        cin>>a>>b;
        pre_sum[i].first = a;
        pre_sum[i].second = b;
    }
    int res = INT_MAX;
    helper(pre_sum,visited,0,res,{1,0});
    cout<<res<<endl;
}

void solution(){
    PERKET();
}