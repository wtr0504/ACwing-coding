#include "../common.hpp"



bool is_prime_number(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    int sqrt_n = static_cast<int>(sqrt(number));
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

void helper(vector<int> &nums,int start,int m,int cnt,int sum,int &res){
    if(cnt > m) return;
    if(cnt == m){
        if(is_prime_number(sum)){
            res++;
        }
        return;
    }
    for(int i = start;i < nums.size();i++){
        sum += nums[i];
        helper(nums,i+1,m,cnt + 1,sum,res);
        sum -= nums[i];
    }
}


void select_number(){

    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin>>nums[i];
    int res;
    helper(nums,0,m,0,0,res);
    cout<<res<<endl;
}

void solution(){
    select_number();
}