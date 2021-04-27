/*
 * @Author: wenjx 
 * @Date: 2021-04-23 18:26:52
 * @LastEditTime: 2021-04-23 19:35:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /wenjx/c-/sortPractice/mergeSort.cpp
 */
#include <iostream>
#include <vector>

using namespace std;



/**对数组[left,mid] [mid+1,right]元素 合并
 * @description: 
 * @param {vector<int>} &nums 数组
 * @param {int} left
 * @param {int} mid
 * @param {int} right
 * @return {*}
 */
void mergeArray(vector<int> &nums,int left,int mid,int right) 
{
    vector<int> temp_nums(nums);
    int firstidx=left,secondidx=mid+1;
    for(int k=left;k<=right;++k) {
        if (firstidx==mid+1) {
            nums[k]=temp_nums[secondidx++];
        } 
        else if (secondidx==right+1)
            nums[k]=temp_nums[firstidx++];
        else if (temp_nums[firstidx]>temp_nums[secondidx] ) {
            nums[k]=temp_nums[secondidx++];
        }
        else if (temp_nums[firstidx]<temp_nums[secondidx]) {
            nums[k]=temp_nums[firstidx++];
        }
    }
}

// void mergeArray(vector<int> &nums,int left,int mid,int right) 
// {
//     //[left,mid] [mid+1,right]

//     int firstidx=left,secondidx=mid+1;
//     vector<int> temp_num(right-left+1);
//     int idx=0;
//     while (firstidx<=mid && secondidx<=right) {
//         if (nums[firstidx]<=nums[secondidx] ) {
//             temp_num[idx++]=nums[firstidx++];
//         }
//         else 
//             temp_num[idx++]=nums[secondidx++]; 
//     }

//     while (firstidx<=mid) 
//         temp_num[idx++]=nums[firstidx++];
//     while (secondidx<=right) 
//         temp_num[idx++]=nums[secondidx++];
    
//     int idx_new=left;
//     for(int i=0;i<right-left+1;i++) {
//         nums[idx_new++]=temp_num[i];
//     }
// }


/** 对数组进行归并排序
 * @description: 
 * @param {vector<int>} &nums 
 * @param {int} left 数组左下标
 * @param {int} right 数组右下标
 * @return {*}
 */
void mergeSort(vector<int> &nums,int left,int right) {
    if (left>=right)
        return;
    int mid = left+(right-left)/2;
    mergeSort(nums,left,mid);//针对[left,mid]区间数组元素进行排序
    mergeSort(nums,mid+1,right);//针对[mid+1,right]区间数组元素进行排序
    mergeArray(nums,left,mid,right);//对区间[left,mid]和区间[mid+1,right]的有序数组进行合并
}
 
/** 对数组nums 进行从小到大排序
 * @description: 
 * @param {vector<int>} &nums
 * @return {*}
 */
void Sort(vector<int> &nums) {
    mergeSort(nums,0,nums.size()-1);
}
int main()
{
    vector<int> v{2,7,5,3,9};
    Sort(v);
    for(const auto& iter:v)
        cout<<iter<<" ";
    cout<<endl;
}