#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//1��: 1 2 3 4 5  2��: 2 1 2 3 2 4 2 5   3��: 3 3 1 1 2 2 4 4 5 5
vector<int> solution(vector<int> answers) {
    vector<int> answer;             //����� vector
    vector<int> cnt(3);             //� �������� ������ vector
    vector<int> person1 = { 1,2,3,4,5 };
    vector<int> person2 = { 2,1,2,3,2,4,2,5 };
    vector<int> person3 = { 3,3,1,1,2,2,4,4,5,5 };
    int max_score = 0;

    for (int i = 0; i < answers.size(); i++) {          //�� ���� ����ŭ �ݺ��� ���鼭 �� ������� �ش� ������ ���߾����� Ȯ��
        if (answers[i] == person1[i % 5]) cnt[0]++;
        if (answers[i] == person2[i % 8]) cnt[1]++;
        if (answers[i] == person3[i % 10]) cnt[2]++;
    }

    max_score = max(max(cnt[0], cnt[1]), cnt[2]);       //�ִ� ���� ���ϱ�
    for (int i = 0; i < 3; i++) {
        if (max_score == cnt[i]) {      //ù��° ������� �ִ��������� Ȯ���ϸ鼭 answer�� push_back
            answer.push_back(i + 1);
        }
    }

    return answer;
}