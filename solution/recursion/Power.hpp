#include "../common.hpp"




vector<int> dp(20005);

string helper(int num){
    if(num == 2){
        return "2";
    }
    if(num == 1){
        return "2(0)";
    }
    string res;
    if(num == 3){
        return helper(2) + "+" + helper(1);
    } 
    int index = dp[num];
    if(num == pow(2,index)){
        return "2(" + helper(index) + ")";
    }
    return "2(" + helper(index) + ")" + "+" + helper(num - pow(2,index));
}


void Power(){
    int n;
    cin>>n;
    int cur = 0;
    int tmp = pow(2,cur);
    for(int i = 1;i <= n;i++){
        if(tmp <= i && i < 2 * tmp){
            dp[i] = cur;
        } else{
            cur++;
            dp[i] = cur;
            tmp = pow(2,cur);
        }
    }
    string s;
    while(n > 3){
        int index = dp[n];
        s += "2(" + helper(index) + ")+";
        n = n - pow(2,index);
    }
    if(n == 3){
        s += "2+2(0)";
    }
    if(n == 2){
        s += "2";
    }
    if(n==1){
        s+= "2(0)";
    }
    if(s.back() == '+'){
        s.pop_back();
    }
    cout<<s<<endl;
}

void solution(){
    Power();
}