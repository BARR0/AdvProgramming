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
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *anagramMappings(int* A, int ASize, int* B, int BSize, int* returnSize) {
    if(ASize != BSize){
        printf("WHAT?!?!!???");
        return NULL;
    }
    int *AB = (int *)malloc(sizeof(int) * ASize);
    int m = ASize * 2;
    int keys[m];
    int vals[m];
    for(int i = 0; i < m; ++i)
    {
        vals[i] = -1;
    }
    for(int i = 0; i < BSize; ++i)
    {
        put(keys, vals, m, B[i], i);
    }
    for(int i = 0; i < ASize; ++i)
    {
        AB[i] = get(keys, vals, m, A[i]);
    }
    *returnSize = ASize;
    return AB;
}

int main(){
    int A[] = {0, 1, 2, 3, 4};
    int B[] = {4, 3, 2, 1, 0};
    int r;
    int *P = anagramMappings(A, 5, B, 5, &r);
}
