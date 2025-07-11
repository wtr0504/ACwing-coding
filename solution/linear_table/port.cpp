#include <bits/stdc++.h>
#include "../common.hpp"
#include <queue>
int n;

struct Node{
    int time;
    int x;
};
int num[100005];

queue<Node> q;

void solution(){
    cin>>n;
    int res;
    while(n--){
        int t,k;
        cin>>t>>k;
        for(int i = 0;i < k;i++){
            int x;
            cin>>x;
            q.push({t,x});
            if(num[x] == 0){
                res++;
            }
            num[x]++;
            while(!q.empty() && q.front().time <= t - 86400){
                if(--num[q.front().x] == 0){
                    res--;
                }
                q.pop();
            }
        }
        cout<<res<<endl;
    }
}
