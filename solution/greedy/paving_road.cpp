#include "../common.hpp"
vector<int> road(1000000 + 5);

void paving_roads_1(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>road[i];
    }
    long long res = 0;
    for(int i = 1;i <= n;i++){
        res += max(0,road[i] - road[i-1]);
    }
    cout<<res<<endl;
}

void solution(){
    paving_roads_1();
}