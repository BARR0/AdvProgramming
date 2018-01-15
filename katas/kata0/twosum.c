#include <stdlib.h>
#include <stdio.h>

void put(int keys[], int vals[], int size, int key, int val)
{
    int i;
    for(i = key % size; vals[i] != -1; i = (i + 1) % size)
    {
        if(keys[i] == key)
        {
            vals[i] = val;
            return;
        }
    }
    keys[i] = key;
    vals[i] = val;
}

int get(int keys[], int vals[], int size, int key)
{
    for (int i = key % size; vals[i] != -1; i = (i + 1) % size)
    {
        if (keys[i] == key)
        {
            return vals[i];
        }
    }
    return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target)
{
    int m = numsSize * 2;
    int keys[m];
    int vals[m];
    for (int i = 0; i < m; ++i)
    {
        vals[i] = -1;
    }
    for (int i = 0; i < numsSize; ++i)
    {
        put(keys, vals, m, nums[i], i);
    }
    for (int i = 0; i < numsSize; ++i)
    {
        int res = get(keys, vals, m, target - nums[i]);
        if(res != -1 && res != i && (nums[i] + nums[res]) == target)
        {
            int *result = malloc(sizeof(int) * 2);
            result[0] = i;
            result[1] = res;
            // printf("%d + %d = %d\n", nums[i], nums[res], target);
            return result;
        }
    }
    return NULL;
}

// Not used on leetcode.com
int main()
{
    int t = -5;
    int n = 3;
    int a[n];
    a[0] = 1;
    a[1] = 2;
    a[2] = -7;
    int *r = twoSum(a, n, t);
    printf("%d + %d = %d\n", a[r[0]], a[r[1]], t);
    return 0;
}
