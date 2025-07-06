
void heapify(std::vector<int> &nums,int n,int i){
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if(left < n && nums[left] > nums[largest]){
        largest = left;
    }

    if(right < n && nums[right] > nums[largest]){
        largest = right;
    }
    if(largest != i){
        std::swap(nums[largest],nums[i]);
        heapify(nums,n,largest);
    }
}

void heapSort(std::vector<int> &nums){
    int n = nums.size();
    for(int i = n/2 - 1;i >= 0;i--){
        heapify(nums,n,i);
    }
    for(int i = n-1;i > 0;i--){
        std::swap(nums[0],nums[i]);
        heapify(nums,i,0);
    }
}