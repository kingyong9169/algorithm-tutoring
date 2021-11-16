#include <string>
#include <vector>

using namespace std;
//주의할점: 벡터를 매개변수로 넘길 때 객체를 넘기는 것이기 때문에 배열과 헷갈리면 안됨. 
//배열은 배열의 이름이 포인터로, 주소값이지만, 벡터는 객체 그 자체이기 때문에 &를 사용해서 객체의 주소값을 넘겨줘야됨.
void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void QuickSort(vector<int>& sortArr, int left, int right) {         //퀵 정렬
    if (left >= right) {
        return;
    }

    int pivot = left;      //가장 오른쪽 값이 pivot
    int low = left + 1;
    int high = right;

    while (low <= high) {       //low와 high가 엇갈릴때까지. 엇갈리고 나면 pivot과 high가 바뀐는데, 그떄 pivot은 본인의 정렬 후 알맞은 위치를 찾은 것임.
        while (low <= high && sortArr[low] <= sortArr[pivot]) {
            low++;
        }
        while (high >= left + 1 && sortArr[pivot] <= sortArr[high]) {
            high--;
        }
        if (low > high) {       //엇갈림 -> 피봇과 high swap
            Swap(sortArr[high], sortArr[pivot]);
        }
        else {      //엇갈리지 않음 -> low와 high swap
            Swap(sortArr[low], sortArr[high]);
        }
    }
    if (high > 0) {             //정렬할 배열에서 맨 처음 값이 가장 작을 경우 high가 -1이 됨. 이 경우 예외처리
        QuickSort(sortArr, left, high - 1);
    }
    QuickSort(sortArr, high + 1, right);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int MinIdx = 0, MaxIdx = 0;
    for (int i = 0; i < commands.size(); i++) {         //commands의 행의 수(테스트케이스 갯수)만큼 반복
        MinIdx = commands[i][0] - 1;      //정렬 시작할 인덱스
        MaxIdx = commands[i][1] - 1;      //정렬 끝날 인덱스
        vector<int>sortArr(MaxIdx - MinIdx + 1);

        for (int j = 0; j < MaxIdx - MinIdx + 1; j++) {
            sortArr[j] = array[MinIdx + j];     //정렬할 배열
        }
        QuickSort(sortArr, 0, sortArr.size() - 1);      //정렬

        answer.push_back(sortArr[commands[i][2] - 1]);      //commands의 세번째 값이 정렬한 배열에서 찾을 값    
    }
    return answer;
}