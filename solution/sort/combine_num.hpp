#include "../common.hpp"

bool cmp(const string& a,const string &b){
    return (a + b) > (b + a);
}


void combine_nums(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),cmp);
    for(int i = 0;i < n;i++){
        cout<<v[i];
    }
    cout<<endl;
}

void solution(){
    combine_nums();
}