#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
//수의 가장 높은 자릿수가 가장 큰 것을 기준으로 정렬하기

void swap(float& i, float& j) {
    float temp = i;
    i = j;
    j = temp;
}

void quickSort(vector<vector<float>> &compare_vec, int i, int j) {
    if (i >= j) return;          //left가 right보다 크거나 같으면 더이상 바꿀게 없는 것이므로 탈출
    int left = i;
    int right = j;
    int pivot = (left + right) / 2;

    while (left < right) {
        while (compare_vec[1][left] < compare_vec[1][pivot]) left++;     //왼쪽에서 pivot보다 큰거 찾기
        while (compare_vec[1][right] > compare_vec[1][pivot]) right--;   //오른쪽에서 pivot보다 작은거 찾기
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
    string answer = "";     //정답
    int i = 0;
    float compare_num = 0;
    vector<vector<float>> compare_vec(2, vector<float>(numbers.size(), 0));

    //실수형으로 처리하면 한번에 정렬할 수 있음
    //2차원 벡터에 1행에는 최고 자릿수, 2행에는 원래의 수를 소수로 만든 수가 들어감
    while (compare_vec[1].size() < numbers.size()) {
        if (numbers[i] < 10) {            //한자리 수
            compare_vec[0][i] = 1;
            compare_vec[1][i] = ((float)numbers[i]) / 10;
        }
        else if (numbers[i] < 100) {      //두자리 수
            compare_vec[0][i] = 2;
            compare_vec[1][i] = ((float)numbers[i]) / 100;
        }
        else if (numbers[i] < 1000) {      //세자리 수
            compare_vec[0][i] = 3;
            compare_vec[1][i] = ((float)numbers[i]) / 1000;
        }
        else {                            //네자리 수(10000) 
            compare_vec[0][i] = 4;
            compare_vec[1][i] = ((float)numbers[i]) / 10000;
        }
        i++;
    }
    //소수점 먼저 비교 -> 같은거 있으면 일의자리 더 작은 것을 더 큰 수로 지정
    //1,10,100,1000 따로 처리해주기 ->필요없는거같은데,,, 이생각 왜했지???
    //퀵 정렬
    quickSort(compare_vec, 0, compare_vec[1].size() - 1);
    int ans_num = 0;
    for (int i = 0; i < compare_vec[1].size(); i++) {
        //i가 마지막 인덱스가 아니고, 현재 인덱스 값과 다음 인덱스 값이 같을 때 반복
        while (i != compare_vec[1].size() - 1 && compare_vec[1][i] == compare_vec[1][i + 1]) {      

        }
        //소수점아래로는 정렬된 상태. 하지만 같은 수일 경우 자릿수 낮은 수가 우선순위임. 그거 처리 해주기.
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