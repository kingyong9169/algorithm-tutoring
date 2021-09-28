#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
//���� ���� ���� �ڸ����� ���� ū ���� �������� �����ϱ�

void swap(float& i, float& j) {
    float temp = i;
    i = j;
    j = temp;
}

void quickSort(vector<vector<float>> &compare_vec, int i, int j) {
    if (i >= j) return;          //left�� right���� ũ�ų� ������ ���̻� �ٲܰ� ���� ���̹Ƿ� Ż��
    int left = i;
    int right = j;
    int pivot = (left + right) / 2;

    while (left < right) {
        while (compare_vec[1][left] < compare_vec[1][pivot]) left++;     //���ʿ��� pivot���� ū�� ã��
        while (compare_vec[1][right] > compare_vec[1][pivot]) right--;   //�����ʿ��� pivot���� ������ ã��
        if (left <= right) {
            swap(compare_vec[1][left], compare_vec[1][right]);
            swap(compare_vec[0][left], compare_vec[0][right]);
            left++;
            right--;
        }
        quickSort(compare_vec, i, left);
        quickSort(compare_vec, right, j);
    }
}

string solution(vector<int> numbers) {
    string answer = "";     //����
    int i = 0;
    float compare_num = 0;
    vector<vector<float>> compare_vec(2, vector<float>(numbers.size(), 0));

    //�Ǽ������� ó���ϸ� �ѹ��� ������ �� ����
    //2���� ���Ϳ� 1�࿡�� �ְ� �ڸ���, 2�࿡�� ������ ���� �Ҽ��� ���� ���� ��
    while (compare_vec[1].size() < numbers.size()) {
        if (numbers[i] < 10) {            //���ڸ� ��
            compare_vec[0][i] = 1;
            compare_vec[1][i] = ((float)numbers[i]) / 10;
        }
        else if (numbers[i] < 100) {      //���ڸ� ��
            compare_vec[0][i] = 2;
            compare_vec[1][i] = ((float)numbers[i]) / 100;
        }
        else if (numbers[i] < 1000) {      //���ڸ� ��
            compare_vec[0][i] = 3;
            compare_vec[1][i] = ((float)numbers[i]) / 1000;
        }
        else {                            //���ڸ� ��(10000) 
            compare_vec[0][i] = 4;
            compare_vec[1][i] = ((float)numbers[i]) / 10000;
        }
        i++;
    }
    //�Ҽ��� ���� �� -> ������ ������ �����ڸ� �� ���� ���� �� ū ���� ����
    //1,10,100,1000 ���� ó�����ֱ� ->�ʿ���°Ű�����,,, �̻��� ������???
    //�� ����
    quickSort(compare_vec, 0, compare_vec[1].size() - 1);
    int ans_num = 0;
    for (int i = 0; i < compare_vec[1].size(); i++) {
        //i�� ������ �ε����� �ƴϰ�, ���� �ε��� ���� ���� �ε��� ���� ���� �� �ݺ�
        while (i != compare_vec[1].size() - 1 && compare_vec[1][i] == compare_vec[1][i + 1]) {      

        }
        //�Ҽ����Ʒ��δ� ���ĵ� ����. ������ ���� ���� ��� �ڸ��� ���� ���� �켱������. �װ� ó�� ���ֱ�.
        ans_num = compare_vec[1][i] * pow(10, compare_vec[0][i]);   . 
        answer += to_string(ans_num);
    }

    return answer;
}

int main() {
    vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(31);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(264);
    string ans = solution(numbers);

    cout << ans;

    return 0;
}