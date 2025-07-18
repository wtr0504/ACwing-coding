#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
#define ull unsigned long long 
// unordered_set<ull> s;
ull s;
int n;
void solution(){
    cin>>n;
    for(int i = 0;i < n;i++){
        int l;
        cin>>l;
        s ^= l;
    }
    cout<<s<<endl;
}