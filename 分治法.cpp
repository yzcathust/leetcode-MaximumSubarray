#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return indexSum(nums,0,nums.size()-1);
    }
private:
    int indexSum(vector<int> & nums, int beg, int end)
    {
        if(beg == end)
        {
            return nums[beg];
        }
        int middle = (beg + end) / 2;
        int left = indexSum(nums,beg,middle);
        int right = indexSum(nums,middle+1, end);
        int max = left >= right ? left : right;
        
        int leftSum = 0;
        int rightSum = 0;
        int leftMax = nums[middle], rightMax = nums[middle + 1];
        for(int i = middle; i != beg - 1; --i)
        {
            leftSum += nums[i];
            if(leftSum > leftMax)
            {
                leftMax = leftSum;
            }
        }
        for(int i = middle+1; i != end + 1; ++i)
        {
            rightSum += nums[i];
            if( rightSum >  rightMax)
            {
                 rightMax =  rightSum;
            }
        }
		leftMax += rightMax;
        max = max >= leftMax ? max : leftMax;
        return max;
    }
};

int main()
{
	vector<int> coll;
	coll.push_back(-2);
	coll.push_back(1);
	coll.push_back(-3);
	coll.push_back(4);
	coll.push_back(-1);
	coll.push_back(2);
	coll.push_back(1);
	coll.push_back(-5);
	coll.push_back(4);
	Solution s;
	s.maxSubArray(coll);
}