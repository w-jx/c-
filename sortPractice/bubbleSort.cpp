#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bubbleSort(vector<int>& nums) {

	int n=nums.size();
	for(int i=0;i<n;++i) {
		for(int j=n-1;j>i;--j) {
			if (nums[j]<nums[j-1])
				swap(nums[j],nums[j-1]);

		}
	}

}
void test01()
{
	vector<int> v{2,10,7,3,6,4,9};
	bubbleSort(v);
	for_each(v.begin(),v.end(),[](int x){
			cout<<x<<" ";});
}
int main()
{
	test01();
	return 0;
}
