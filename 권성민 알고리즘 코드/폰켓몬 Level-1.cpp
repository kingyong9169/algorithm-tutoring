#include <vector>
using namespace std;
vector<int> select;
int solution(vector<int> nums)
{
	int check = 0;
	int choose = (nums.size() / 2); //���ϸ��� �̴� ����
	for (int i = 0; i < nums.size(); i++)
	{
		check = 0;
		for (int j = 0; j < select.size(); j++)
		{
			if (nums[i] == select[j])
			{
				check = 1;
			}
		}
		if (check == 0)
		{
			select.push_back(nums[i]); //ó���� ����
		}
	}
	if (select.size() <= choose)return select.size();
	else return choose;
}