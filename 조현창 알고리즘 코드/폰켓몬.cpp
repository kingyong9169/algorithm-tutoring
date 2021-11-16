#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    bool check[200000] = {0,};
    for(int n:nums){
        if(!check[n-1]){
            check[n-1] = true;
            answer++;
        }
    }
    if(answer > nums.size()/2)answer = nums.size()/2;
    return answer;
}