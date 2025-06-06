void merge(std::vector<int> &nums,int left,int mid,int right){
    std::vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    // 合并两个有序子数组
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    // 处理剩余部分
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];

    // 拷贝回原数组
    for (int i = 0; i < temp.size(); ++i)
        nums[left + i] = temp[i];

    
}

void mergeSort(std::vector<int> &nums,int left,int right){
    if (left >= right)
        return;
    int mid = (left + right)/2;
    mergeSort(nums,left,mid);
    mergeSort(nums,mid + 1,right);
    merge(nums,left,mid,right);
}

void quickSort(std::vector<int> &vi, int start, int end) {
    if (start >= end) {
        return;
    }

    int base = vi[end];

    int left = start;
    int right = end - 1;
    while (left < right) {
        while (left < right && vi[left] < base) {
            left++;
        }
        while (left < right && vi[right] >= base) {
            right--;
        }
        std::swap(vi[left], vi[right]);
    }

    if (vi[left] >= vi[end]) {
        std::swap(vi[left], vi[end]);
    } else {
        left++;
    }

    if (start < left - 1) {
        quickSort(vi, start, left - 1);
    }
    if (left + 1 < end) {
        quickSort(vi, left + 1, end);
    }

    return;
}


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