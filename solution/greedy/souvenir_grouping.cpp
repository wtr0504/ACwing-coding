#include "../common.hpp"
#include <algorithm>
#include <vector>

vector<int> v(30000 + 5);
void solution(){
    int w;
    int n;
    cin>>w>>n;
    for(int i = 1;i <= n;i++){
        cin>>v[i];
    }
    sort(v.begin() + 1,v.begin() + n + 1);
    int i = 1,j = n;
    int res = 0;
    while(i < j){
        if(v[i] + v[j] <= w){
            res++;
            i++;
            j--;
        } else if(v[i] + v[j] > w){
            j--;
            res++;
        }
    }
    if(i == j) res++;
    cout<<res<<endl;
}