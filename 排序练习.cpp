
#include <iostream>
#include <vector>
using namespace std;


void shell_sort(vector<int> &nums) 
{
    if (nums.size()<=1)
        return ;
    int len = nums.size();
    int step = len/2;
    int temp  =0,j=0;
    while (step>=1) {
        for(int i=step;i<len;++i)  {
            temp  =nums[i];
            j=i-step;

            while (j>=0 && nums[j] >temp) {
                nums[j+step] =nums[j];
                j-=step;
            }
            nums[j+step]=temp;

        }

        --step;
    }
}

void test01()
{
    vector<int> vtest{4,3,2,5,1};
    shell_sort(vtest);

    for(int i=0;i<5;i++) 
        cout<<vtest[i]<<" ";
    cout<<endl;
}
int main()
{

    test01();


    return 0;
}

