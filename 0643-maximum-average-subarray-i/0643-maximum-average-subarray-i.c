#include <stdio.h>

double findMaxAverage(int* nums, int n, int k) {
    int sum = 0;
    for(int i = 0; i<k; i++)
    {
        sum += nums[i];
    }

    int max_sum = sum;
    for(int i = k; i < n; i++)
    {
        sum = sum - nums[i-k] + nums[i];
        if(sum > max_sum)
        {
            max_sum = sum;
        }

    }
    return (double)max_sum / k;

}