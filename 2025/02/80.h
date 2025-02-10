// 基本思路，原数组标记后移动
// 优化，一次遍历

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) return numsSize; // 如果数组为空，直接返回 0

    int i = 0; // 慢指针，记录有效元素的位置
    int count = 1; // 记录当前元素的重复次数

    // 快指针 j 遍历数组
    for (int j = 1; j < numsSize; j++) {
        // 如果当前元素与前一个元素相同
        if (nums[j] == nums[j - 1]) {
            count++; // 重复次数加 1
        } else {
            count = 1; // 否则重置重复次数
        }

        // 如果重复次数 <= 2，将当前元素移动到慢指针位置
        if (count <= 2) {
            i++; // 慢指针前移
            nums[i] = nums[j]; // 将当前元素赋值给慢指针位置
        }
    }

    return i + 1; // 返回新数组的长度
}
