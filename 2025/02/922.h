void swap(int *a, int* b){
    int temp = *a;
    *a = *b,*b=temp;
}


int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int odd = 1;  // 奇数指针，从索引 1 开始
    int even = 0; // 偶数指针，从索引 0 开始

    while (odd < numsSize && even < numsSize) {
        // 找到偶数的错误位置
        while (even < numsSize && nums[even] % 2 == 0) {
            even += 2;
        }
        // 找到奇数的错误位置
        while (odd < numsSize && nums[odd] % 2 == 1) {
            odd += 2;
        }
        // 如果仍然在范围内，交换
        if (even < numsSize && odd < numsSize) {
            swap(nums+even,nums+odd);
        }
    }

    *returnSize = numsSize;
    return nums;
}

// 官方题解
void swap(int* a, int* b) {
    int t = *a;
    *a = *b, *b = t;
}

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int j = 1;
    for (int i = 0; i < numsSize; i += 2) {
        if (nums[i] % 2 == 1) {
            while (nums[j] % 2 == 1) {
                j += 2;
            }
            swap(nums + i, nums + j);
        }
    }
    *returnSize = numsSize;
    return nums;
}