#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    //모든사람 = 최대한 많은 사람이 아니므로
    //보트의 공간을 효율적으로 사용하는 것이 우선
    //내림차순 정렬 후 가장 무거운 사람을 태우고 (인덱스 0번)
    //순회하여 보트의 남은 용량 이하인 것 중 차이가 가장 적은 걸 태운다.
    //용량이 남았을 경우 뒤를 더 순회하여 태운다. 반복
    int answer = 0;
    vector<bool> check(people.size(),0);
    int checked = 0;
    sort(people.begin(),people.end(),greater<int>());
    int min = people.size()-1;
    while(checked < people.size()){
        int tmp = limit;
        for(int i = 0; i < people.size();i++){
            if(check[i])continue;
            if(tmp < people[min])break;
            if(tmp >= people[i]){
                tmp -= people[i];
                check[i] = true;
                checked++;
                if(i == min)min--;
            }
        }
        answer++;
    }

    
    return answer;
}