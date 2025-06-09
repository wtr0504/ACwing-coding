#include "../common.hpp"
#include <algorithm>
#include <utility>
#include <vector>

struct compare{
    bool operator()(const pair<int,int> &lhs,const pair<int,int> &rhs){
        if(rhs.second != lhs.second) return lhs.second < rhs.second;
        return rhs.first < lhs.first;
    }
};
vector<pair<int, int>> v(1000005);
void line_overlap(){
    int n;
    cin>>n;
    int max_time = 0;
    for(int i = 0;i < n;i++){
        cin>>v[i].first>>v[i].second;
        max_time = max(max_time,v[i].second);
    }

    sort(v.begin(),v.begin() + n,compare());
    int sum = 1;
    int m = v[0].second;
    for(int i = 1;i < n;i++){
        if(m <= v[i].first){
            m = v[i].second;
            sum++;
        }
    }
    cout<<sum<<endl;
}

void solution(){
    line_overlap();
}