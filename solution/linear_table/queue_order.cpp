#include <bits/stdc++.h>
#include "../common.hpp"

struct ListNode{
    int idx;
    int next;
    int pre;
};

ListNode l[105];

int n,m;

void insert(int idx,int k,int p){
    l[idx].idx = idx;
    if(p == 0){
        l[l[k].pre].next = idx;
        l[idx].next = k;
        l[idx].pre = l[k].pre;
        l[k].pre = idx;

    } else {
        int tmp = l[k].next;
        l[tmp].pre = idx;
        l[k].next = idx;
        l[idx].next = tmp;
        l[idx].pre = k;
    }
}

void remove(int idx){
    if(l[idx].idx != 0){
        l[l[idx].pre].next = l[idx].next;
        l[l[idx].next].pre = l[idx].pre;
        l[idx].idx = 0;
    }
}

void solution(){
    cin>>n;
    l[1].idx = 1;
    for(int i = 2;i <= n;i++){
        int k,p;
        cin>>k>>p;
        insert(i,k,p);
    }
    cin>>m;
    for(int i = 0;i < m;i++){
        int k;
        cin>>k;
        remove(k);
    }
    int i = 1;
    while(l[i].pre != 0 || l[i].idx == 0) 
        i++;
    while(l[i].next != 0){
        cout<<l[i].idx<<" ";
        i = l[i].next;
    }
    cout<<l[i].idx<<endl;
}