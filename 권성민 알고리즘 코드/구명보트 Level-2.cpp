#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	sort(people.begin(), people.end());
	int answer = 0; int first = 0; int last = people.size() - 1;
	while (first <= last)
	{
		if (people[first] + people[last] <= limit) //2명 구출
		{
			first++; last--; answer++;
		}
		else //limit를 넘게되면 가장 큰 사람은 보트를 혼자 타야된다.
		{
			last--; answer++;
		}
	}
	return answer;
}