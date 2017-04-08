#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		 int max = nums[0];
		 int sum = 0;
		 for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++ iter)
		 {
			 if(sum > 0)
			 {
				 sum += *iter;
			 }
			 else
			 {
				 sum = *iter;
			 }
			 if(sum > max)
			 {
				 max = sum;
			 }
		 }
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