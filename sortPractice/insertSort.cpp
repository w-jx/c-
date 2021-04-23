/*
 * @Author: your name
 * @Date: 2021-04-18 15:04:12
 * @LastEditTime: 2021-04-18 15:11:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /sortPractice/insertSort.cpp
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void insert_Sort(vector<int>& nums)
{
    if (nums.size()<=1)
        return ;
    int j=0;
    for(int i=1;i<nums.size();++i) {
        int temp = nums[i];
        j=i-1;
        while (j>=0 && nums[j]>temp ) {
            nums[j+1]=nums[j];
            --j;
        }
        nums[j+1]=temp;
    }
}
void test01()//
{
    vector<int> nums{1,4,5,2,9};
    insert_Sort(nums);

    for_each(nums.begin(),nums.end(),[](int x){
        cout<<x<<" ";
    });
    cout<<endl;
}



int main(void)
{

	test01();//

	return 0;

}
