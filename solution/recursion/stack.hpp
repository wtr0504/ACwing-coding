#include "../common.hpp"
/**
 * 这道题和leetcode hot 100 括号生产非常相似，采用回溯的思想
 * 
 */

bool visited[37][19] = {false};

int helper(int step,int n,int stk_cnt){
    int t = 0;
    if(step == n * 2){
        if(stk_cnt == 0){
            return 1;
        }else{
            return 0;
        }
    }
    if(visited[step][stk_cnt] != 0)
        return visited[step][stk_cnt];
    if(stk_cnt < n){
        t += helper(step + 1,n,stk_cnt + 1);
    }
    if(stk_cnt > 0){
        t += helper(step + 1,n,stk_cnt - 1);
    }
    visited[step][stk_cnt] = t;
    return t;

}


void my_stack(){
    int n;
    cin>>n;
    int res = 0;
    
    cout<<helper(0,n,0)<<endl;
}

void solution(){
    my_stack();
}
