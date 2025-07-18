#include <bits/stdc++.h>
#include "../common.hpp"

int a[1005];
int enemy[1005];

struct edge{
    int x,y,relation;
};

edge rl[5005];

int n,m;

int find(int x){
    if(x == a[x]){
        return x;
    } else{
        return find(a[x]);
    }
}

void add(int x,int y){
    int u = find(x);
    int v = find(y);
    a[u] = v;
}

bool check(int x,int y){

}

/**
    这里错加没有关系，前面在两个组里，后面又变为朋友，结果不会增加
 */

void solution(){
    int res = 1;
    cin>>n>>m;
    char c;
    int x,y;
    for(int i = 0;i < n;i++) a[i] = i;
    for(int i = 0;i < m;i++){
        cin>>rl[i].relation>>rl[i].x>>rl[i].y;
    }
    for(int i = 0;i < m;i++){
        x = rl[i].x,y = rl[i].y,c = rl[i].relation;
        if(c == 'F') add(x,y);
        else{

            if(enemy[x] == 0) enemy[x] = find(y);
            else add(y,enemy[y]);

            if(enemy[y] == 0) enemy[y] = find(x);
            else add(x,enemy[y]);
            // res++;
        }
    }

    for(int i = 0;i < n;i++){
        if(a[i] == i){
            res++;
        }
    }
    cout<<res<<endl;


}