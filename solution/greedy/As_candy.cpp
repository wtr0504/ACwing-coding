#include "../common.hpp"

#define ll long long

vector<int> v(100005);
void As_candy(){
    int n,x;
    ll res = 0l;
    cin>>n>>x;

    for(int i = 1;i <= n;i++) cin>>v[i];

    for(int i = 1;i < n;i++){
        int sum = v[i] + v[i + 1];
        if(sum > x){
            if(v[i + 1] - (sum - x) >= 0){
                v[i + 1] -= (sum - x);
            } else{
                v[i + 1] = 0;   
            }
            res += (sum - x);
        }
    }
    cout<<res<<endl;
}


void solution(){
    As_candy();
}