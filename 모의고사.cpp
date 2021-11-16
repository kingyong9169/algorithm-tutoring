#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//1번: 1 2 3 4 5  2번: 2 1 2 3 2 4 2 5   3번: 3 3 1 1 2 2 4 4 5 5
vector<int> solution(vector<int> answers) {
    vector<int> answer;             //출력할 vector
    vector<int> cnt(3);             //몇개 맞혔는지 저장할 vector
    vector<int> person1 = { 1,2,3,4,5 };
    vector<int> person2 = { 2,1,2,3,2,4,2,5 };
    vector<int> person3 = { 3,3,1,1,2,2,4,4,5,5 };
    int max_score = 0;

    for (int i = 0; i < answers.size(); i++) {          //총 문제 수만큼 반복문 돌면서 각 사람마다 해당 문제를 맞추었는지 확인
        if (answers[i] == person1[i % 5]) cnt[0]++;
        if (answers[i] == person2[i % 8]) cnt[1]++;
        if (answers[i] == person3[i % 10]) cnt[2]++;
    }

    max_score = max(max(cnt[0], cnt[1]), cnt[2]);       //최대 점수 구하기
    for (int i = 0; i < 3; i++) {
        if (max_score == cnt[i]) {      //첫번째 사람부터 최대점수인지 확인하면서 answer에 push_back
            answer.push_back(i + 1);
        }
    }

    return answer;
}