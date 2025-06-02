#include "../common.hpp"

void next_arrangement(vector<int>& nums){
    int i = nums.size() - 2;
    while(i >= 0 && nums[i] >= nums[i+1]){
        i--;
    }
    int j = nums.size() - 1;
    while(i >= 0 && nums[j] <= nums[i]){
        j--;
    }
    if(i >= 0 && j >= 0){
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin() + i + 1,nums.end());
}

void solution(){
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin>>nums[i];

    for(int i = 0;i < m;i++) next_arrangement(nums);

    for(int i = 0;i < n-1;i++){
        cout<<nums[i]<<" ";
    }
    cout<<nums[n - 1]<<endl;
}