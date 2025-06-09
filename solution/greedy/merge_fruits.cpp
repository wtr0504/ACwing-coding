#include "../common.hpp"
#include <algorithm>
#include <utility>
#include <vector>

vector<int> v(10005);
int sz = 0;
void up(int i){
    while(i > 0){
        int father = i / 2;
        if(v[father] <= v[i]){
            return;
        } else {
            swap(v[father],v[i]);
            i = father;
        }
    }
}

void insert(int val){
    v[sz++] = val;
    up(sz - 1);
}

void down(int i){
    int child = 2 * i;
    while(child < sz){
        if(child < sz - 1 && v[child + 1] < v[child]){
            child++;
        }
        if(v[child] < v[i]){
            swap(v[child],v[i]);
            i = child;
            child = 2 * i;
        } else {
            return;
        }
    }
}

void pop_fornt(){
    v[0] = v[--sz];
    down(0);
}

int gettop(){
    return v[0];
}


void merge_fruit(){
    unsigned int res = 0;
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.begin() + n);
    sz = n;
    while(sz >= 2){
        int t1 = gettop();
        pop_fornt();
        int t2 = gettop();
        pop_fornt();
        res += t1 + t2;
        insert(t1 + t2);
    }
    cout<<res<<endl;
}

void solution(){
    merge_fruit();
}



