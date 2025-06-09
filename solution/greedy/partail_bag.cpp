#include "../common.hpp"
#include <algorithm>
#include <compare>
#include <functional>
#include <iomanip>
#include <ios>
#include <utility>
#include <vector>


vector<double> weight(105,0);
vector<double> total_value(106,0);
vector<pair<double,int>> average_value(106);

struct Compare{
    bool operator() (const pair<double,int> &lhs, const pair<double, int>& rhs){
        return lhs.first > rhs.first;
    }
};

void partail_bag(){
    int n,t;
    cin>>n>>t;
    int w,v;
    int i = 1;
    while(i <= n){
        cin>>w>>v;
        weight[i] = w;
        total_value[i] = v;
        average_value[i].first = (double)v / (double)w;
        average_value[i].second = i;
        i++;
    }
    sort(average_value.begin() + 1,average_value.begin() + i,Compare());
    double res = 0;
    double cur_weight = 0.0;
    for(int i = 1;i <= n && cur_weight < (double)t;i++){
        int cur_good = average_value[i].second;
        if(weight[cur_good] <= t - cur_weight){
            cur_weight += weight[cur_good];
            res += total_value[cur_good];
        } else{
            double ww = t - cur_weight;
            res += ww * ((double)total_value[cur_good] /(double)weight[cur_good]);
            break;
        }
    }
    cout<<std::fixed<<std::setprecision(2)<<res<<endl;
}

void solution(){
    partail_bag();
}