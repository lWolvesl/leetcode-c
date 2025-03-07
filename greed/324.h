static int cmp(const void *pa, const void *pb) {
    return *(int *)pa - *(int *)pb;
}

void wiggleSort(int* nums, int numsSize) {
    int * arr = (int *)malloc(sizeof(int) * numsSize);
    memcpy(arr, nums, sizeof(int) * numsSize);
    qsort(arr, numsSize, sizeof(int), cmp);
    int x = (numsSize + 1) / 2;
    for (int i = 0, j = x - 1, k = numsSize - 1; i < numsSize; i += 2, j--, k--) {
        nums[i] = arr[j];
        if (i + 1 < numsSize) {
            nums[i + 1] = arr[k];
        }
    }
    free(arr);
}