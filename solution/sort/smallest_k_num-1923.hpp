#include "../common.hpp"



int quick_sort(vector<int>& nums,int start,int end,int k){
    if(start == end){
        return nums[k];
    }
    int index = start + rand() % (end - start + 1);
    swap(nums[index],nums[end]);
    int pivot = nums[end];
    int left = start,right = end - 1;
    while(left < right){
        while(left < right && nums[left] < pivot) left ++;
        while(left < right && nums[right] >= pivot) right--;
        swap(nums[right],nums[left]); 
    }
    if(nums[left] >= pivot){
        swap(nums[left],nums[end]);
    }else{
        left++;
        swap(nums[left],nums[end]);
    }
    if(k < left) return quick_sort(nums,start,left - 1,k);
    else if(k > left) return quick_sort(nums,left + 1,end,k);
    else{
        return nums[left];
    }
}


int smallest_k_num(vector<int> &nums,int k){
    int res;
    return quick_sort(nums,0,nums.size() - 1,k);
}

void solution(){
    int n,k;
    while(cin>>n>>k){
        vector<int> nums(n);
        for(int i = 0;i < n;i++) cin>>nums[i];
        cout<<smallest_k_num(nums,k)<<endl;;
    }
}