#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

void quickSort(vector<int> &nums,int left,int right) {
    if (left>=right)
        return;
    int base = nums[left];
    int i=left,j=right;

    while (i<j) {
        while (nums[j]>=base && j>i) 
            --j;
        while (nums[i]<=base && i<j)
            ++i;
        if (i<j)
            swap(nums[i],nums[j]);
    }
    swap(nums[left],nums[i]);
    quickSort(nums,left,i-1);
    quickSort(nums,i+1,right);
}
void quick_sort(vector<int> & v) {
    quickSort(v,0,v.size()-1);
}

void test01()
{
    vector<int> v{1,4,6,2,8,5,19};

    quick_sort(v);

    for_each(v.begin(),v.end(),[=](int x){
        cout<<x<<" ";
    });
    cout<<endl;

}
int main()
{
    test01();
    return 0;
}