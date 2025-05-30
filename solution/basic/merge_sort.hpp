#include "../common.hpp"

void merge(vector<int>& nums,int left,int mid,int right){
    if(left >= right) return;
    vector<int> temp;
    int i = left,j = mid + 1;
    while(i <= mid && j <= right){
        if(nums[i] < nums[j]){
            temp.push_back(nums[i++]);
        } else{
            temp.push_back(nums[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(nums[i++]);
    }
    while(j < right)
        temp.push_back(nums[j++]);
    for(int i = 0;i < temp.size();i++){
        nums[left + i] = temp[i];
    }
}

void merge_sort(vector<int>& nums,int left,int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(nums,left,mid);
    merge_sort(nums,mid+1,right);
    merge(nums,left,mid,right);
}

void solution(){
    int n;
    while(cin>>n){
        vector<int> nums(n);
        for(int i = 0;i < n;i++) cin>>nums[i];
        merge_sort(nums,0,n-1);
        for(int i = 0;i < n-1 ;i++){
            cout<<nums[i]<<" ";
        }
        cout<<nums[n-1]<<endl;
    }
}