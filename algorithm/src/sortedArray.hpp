#pragma once

/*
 * #旋转数组查找#
 *原始排序数组在某一个地方可能发生了旋转
 *[1,2,3,4,5] -->  [3,4,5,1,2]
 *在这样一个数组中查找某个元素是否存在
*/
int search_in_rotated_sorted_array(int* nums, int numsSize, int target);

/*
 * #在排序数组中查找元素的第一个和最后一个位置#
 *给定非递减数组和目标值，找出目标值的起止位置坐标
 *nums-->[5,7,7,8,8,10], target-->7
 *返回[1,2]
*/
int* find_first_and_last_position_of_element_in_sorted_array(int* nums, int numsSize, int target, int* returnSize);


/* 实现函数 */
int search_in_rotated_sorted_array(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize -1;
    
    if (nums[left] == target)
    {
        return left;
    }
    if (nums[right] == target)
    {
        return right;
    }

    int ret = -1;
    int middle;
    while (left + 1 < right)
    {
        middle = (left + right) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        if (nums[middle] > nums[left])
        {
            if (target > nums[left] && target < nums[middle])
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }
        else
        {
            if (target > nums[middle] && target < nums[right])
            {
                left = middle;
            }
            else
            {
                right = middle;
            }
        }
    }

    return ret;

}


/* 实现函数 */
int find_in_left(int* nums, int target,int left, int right)
{
    if (nums[left] == target)
        return left;
    int start = (left + right) / 2;
    while (start<right)
    {
        if (nums[start] == target && nums[start - 1] != target)
        {
            break;
        }
        else if (nums[start] < target)
        {
            left = start;
            start = (start + right) / 2;
        }
        else if (nums[start] > target)
        {
            right = start;
            start = (start + left) / 2;
        }
        else
        {
            start = (start + left) / 2;
        }
    }
    return start;
}
int find_in_right(int* nums, int target, int left, int right)
{
    if (nums[right] == target)
        return right;
    int end = (left + right) / 2;
    while (end>left)
    {
        if (nums[end] == target && nums[end + 1] != target)
        {
            break;
        }
        else if (nums[end] > target)
        {
            right = end;
            end = (end + left) / 2;
        }
        else if (nums[end] < target)
        {
            left = end;
            end = (end + right) / 2;
        }
        else
        {
            end = (end + right) / 2;
        }
    }
    return end;
}

int* find_first_and_last_position_of_element_in_sorted_array(int* nums, int numsSize, int target, int* returnSize)
{
    int* ret = (int*)malloc(2 * sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    if (0 >= numsSize || target<nums[0] || target>nums[numsSize-1])
        return ret;

    if (nums[0] == target)
    {
        ret[0] = 0;
        ret[1] = find_in_right(nums, target, 0, numsSize - 1);
        return ret;
    }
    if (nums[numsSize - 1] == target)
    {
        ret[1] = numsSize - 1;
        ret[0] = find_in_left(nums, target, 0, numsSize - 1);
        return ret;
    }

    ret[0] = find_in_left(nums, target, 0, numsSize - 1);
    ret[1] = find_in_right(nums, target, 0, numsSize - 1);

    return ret;
    
}

void test_sorted_array()
{
    int arr[6] = { 5, 7, 7, 8, 8, 10 };

    std::cout << "sorted array: ";
    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    int ans_size;
    int* ans = find_first_and_last_position_of_element_in_sorted_array(arr, 6, 7, &ans_size);
    std::cout << "target " << 7 << " in [ " << ans[0] << ", " << ans[1] << " ]" << std::endl;

}