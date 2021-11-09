#include <string>
#include <vector>

using namespace std;
//��������: ���͸� �Ű������� �ѱ� �� ��ü�� �ѱ�� ���̱� ������ �迭�� �򰥸��� �ȵ�. 
//�迭�� �迭�� �̸��� �����ͷ�, �ּҰ�������, ���ʹ� ��ü �� ��ü�̱� ������ &�� ����ؼ� ��ü�� �ּҰ��� �Ѱ���ߵ�.
void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void QuickSort(vector<int>& sortArr, int left, int right) {         //�� ����
    if (left >= right) {
        return;
    }

    int pivot = left;      //���� ������ ���� pivot
    int low = left + 1;
    int high = right;

    while (low <= high) {       //low�� high�� ������������. �������� ���� pivot�� high�� �ٲ�µ�, �׋� pivot�� ������ ���� �� �˸��� ��ġ�� ã�� ����.
        while (low <= high && sortArr[low] <= sortArr[pivot]) {
            low++;
        }
        while (high >= left + 1 && sortArr[pivot] <= sortArr[high]) {
            high--;
        }
        if (low > high) {       //������ -> �Ǻ��� high swap
            Swap(sortArr[high], sortArr[pivot]);
        }
        else {      //�������� ���� -> low�� high swap
            Swap(sortArr[low], sortArr[high]);
        }
    }
    if (high > 0) {             //������ �迭���� �� ó�� ���� ���� ���� ��� high�� -1�� ��. �� ��� ����ó��
        QuickSort(sortArr, left, high - 1);
    }
    QuickSort(sortArr, high + 1, right);
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int MinIdx = 0, MaxIdx = 0;
    for (int i = 0; i < commands.size(); i++) {         //commands�� ���� ��(�׽�Ʈ���̽� ����)��ŭ �ݺ�
        MinIdx = commands[i][0] - 1;      //���� ������ �ε���
        MaxIdx = commands[i][1] - 1;      //���� ���� �ε���
        vector<int>sortArr(MaxIdx - MinIdx + 1);

        for (int j = 0; j < MaxIdx - MinIdx + 1; j++) {
            sortArr[j] = array[MinIdx + j];     //������ �迭
        }
        QuickSort(sortArr, 0, sortArr.size() - 1);      //����

        answer.push_back(sortArr[commands[i][2] - 1]);      //commands�� ����° ���� ������ �迭���� ã�� ��    
    }
    return answer;
}