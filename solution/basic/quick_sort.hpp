#include "../common.hpp"
#include <vector>
#include <algorithm>


void quick_sort(vector<int>& nums,int start,int end){
    if(start >= end){
        return;
    }
    int pivot_index = start + rand() % (end - start + 1);
    swap(nums[pivot_index], nums[end]); 
    int left = start,right = end - 1;
    int pivot = nums[end];
    while(left < right){
        while(nums[left] < pivot && left < right) left++;
        while(nums[right] >= pivot && left < right) right--;
        swap(nums[right],nums[left]);
    }
    if(nums[left] >= pivot){
        swap(nums[end],nums[left]);
    } else{
        left++;
        swap(nums[end],nums[left]);
    }
    
    quick_sort(nums,start,left - 1);
    quick_sort(nums,left + 1,end);
}



void solution(){
    int n;
    while(cin>>n){
        srand(time(0));
        vector<int> nums(n);
        for(int i = 0;i < n;i++) cin>>nums[i];
        quick_sort(nums,0,n-1);
        for(int i = 0;i < n-1 ;i++){
            cout<<nums[i]<<" ";
        }
        cout<<nums[n-1]<<endl;
    }
}