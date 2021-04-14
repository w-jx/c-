/*
 * @Author: your name
 * @Date: 2021-04-07 18:23:55
 * @LastEditTime: 2021-04-09 20:55:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /sortPractice/heapSort.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void adjust_heap(vector<int>&nums,int idx,int len) {
	int child = 2*idx+1;
	while (child<len) {

		if (child+1<len && nums[child+1]>nums[child])
			++child;
		if (nums[idx]>nums[child])
			break;
		swap(nums[idx],nums[child]);
		idx = child;
		child=child*2+1;

	}	


}
void make_heap(vector<int> & nums) {

	int n = nums.size();
	for(int i=n/2-1;i>=0;--i) {
		adjust_heap(nums,i,n);
	}

}
void heap_sort(vector<int> &nums)
{

	make_heap(nums);
	int n = nums.size();
	for(int i=n-1;i>=0;--i) {
		swap(nums[i],nums[0]);
		adjust_heap(nums,0,i);

	}


}
void test01()
{
	vector<int> v{2,6,1,9,3,10,4};
	heap_sort(v);
	for_each(v.begin(),v.end(),[](int x){
			cout<<x<<" ";});

}
int main()
{
	test01();
	return 0;
}

