 class Solution {
 public:
	 int removeDuplicates(vector<int>& nums) {

		 ////unique()ɾ����Χ�ڵ������ظ���
		 //vector<int>::iterator it;
		 //it = unique(nums.begin(), nums.end());
		 ////nums.resize(distance(nums.begin(), it));
		 ////int num = nums.begin() - it;
		 ////cout << "Ԫ�ظ���" << num << endl;
		 //vector<int>::iterator begin = nums.begin();
		 //while (begin != it)
		 //{
			// cout << *begin << " ";
			// ++begin;
		 //}
		 ////distance()���������֮��ľ���

		 //˫ָ�뷨
		 //˫ָ�뷨
		 int j = 0;
		 for (int i = 1; i < nums.size(); i++)
		 {
			 if (nums[j] != nums[i])
				 nums[++j] = nums[i];
		 }
		 nums.resize(j+1);
		 return j+1;
	 }
 };

int main()
{
	int myints[] = { 10, 20, 20, 20, 30, 30 };
	vector<int> nums(myints, myints+5);
	Solution s;
	s.removeDuplicates(nums);
	system("pause");
	return 0;
}
