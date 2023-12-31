#pragma once

/*
 * #��ת�������#
 *ԭʼ����������ĳһ���ط����ܷ�������ת
 *[1,2,3,4,5] -->  [3,4,5,1,2]
 *������һ�������в���ĳ��Ԫ���Ƿ����
*/
int search_in_rotated_sorted_array(int* nums, int numsSize, int target);

/*
 * #�����������в���Ԫ�صĵ�һ�������һ��λ��#
 *�����ǵݼ������Ŀ��ֵ���ҳ�Ŀ��ֵ����ֹλ������
 *nums-->[5,7,7,8,8,10], target-->7
 *����[1,2]
*/
int* find_first_and_last_position_of_element_in_sorted_array(int* nums, int numsSize, int target, int* returnSize);


/* ʵ�ֺ��� */
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


/* ʵ�ֺ��� */
int find_in_left(int* nums, int target,int left, int right)
{
    if (nums[left] == target)
        return left;
    int start = (left + right) / 2;
    while (start<right)
    {
        if (nums[start] == target and nums[start - 1] != target)
        {
            break;
        }
        else if (nums[start] < target)
        {
            start = (start + right) / 2;
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
        if (nums[end] == target and nums[end + 1] != target)
        {
            break;
        }
        else if (nums[end] > target)
        {
            end = (end + left) / 2;
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

    int left = 0;
    int right = numsSize - 1;
    int middle;

    return ret;
    
}