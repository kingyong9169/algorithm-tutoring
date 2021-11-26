#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	sort(people.begin(), people.end());
	int answer = 0; int first = 0; int last = people.size() - 1;
	while (first <= last)
	{
		if (people[first] + people[last] <= limit) //2�� ����
		{
			first++; last--; answer++;
		}
		else //limit�� �ѰԵǸ� ���� ū ����� ��Ʈ�� ȥ�� Ÿ�ߵȴ�.
		{
			last--; answer++;
		}
	}
	return answer;
}