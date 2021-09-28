/*
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0, idx = 0;
    char word = s.at(idx);
    vector<int> vec;

    while (idx < s.size()) {
        word = s.at(idx);

        if (word == 'z') {                //zero
            vec.push_back(0);
            idx += 4;
        }
        else if (word == 'o') {           //one
            vec.push_back(1);
            idx += 3;
        }
        else if (word == 't') {
            if (s.at(idx + 1) == 'w') {     //two
                vec.push_back(2);
                idx += 3;
            }
            else {
                vec.push_back(3);            //three
                idx += 5;
            }
        }
        else if (word == 'f') {
            if (s.at(idx + 1) == 'o') {     //four
                vec.push_back(4);
            }
            else {
                vec.push_back(5);            //five
            }
            idx += 4;
        }
        else if (word == 's') {
            if (s.at(idx + 1) == 'i') {     //six
                vec.push_back(6);
                idx += 3;
            }
            else {
                vec.push_back(7);            //seven
                idx += 5;
            }
        }
        else if (word == 'e') {           //eight
            vec.push_back(8);
            idx += 5;
        }
        else if (word == 'n') {           //nine
            vec.push_back(9);
            idx += 4;
        }
        else {
            vec.push_back(int(word) - 48);   //숫자이므로 바로 추가 (아스키코드값의로 계산됨)
            idx++;
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        answer += vec[i] * pow(10, vec.size() - i - 1);
    }

    return answer;
}
*/