void print(int* nums, int numsSize)
{
    printf("[");
    for (int i = 0; i < numsSize; ++i)
        printf("%d, ", nums[i]);
    printf("] len = %d\n", numsSize);
}

void moveZeroes(int* nums, int numsSize)
{
    int i = 0, count = 0;
    while (i < numsSize - count)
    {
        if (nums[i] == 0) 
        {
            memmove(nums + i, nums + i + 1, (numsSize - count - i - 1) * sizeof(int)); 
            nums[numsSize - 1] = 0;
            count++;
        }
        else
        {
            i++;
        }
    }
    
    for (i = 0; i < count; ++i)
        nums[numsSize - i - 1] = 0;
}

