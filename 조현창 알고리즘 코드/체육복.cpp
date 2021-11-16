#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n,1);
    for(int l: lost){
        check[l-1]--;
    }
    for(int r:reserve){
        check[r-1]++;
    }
    for(int i = 0; i < n; i++){
        if(check[i] > 1){
            if(i > 0){
                if(!check[i-1]){
                    check[i-1]++;
                    check[i]--;
                    continue;
                }
            }
            if(!check[i+1]){
                check[i+1]++;
                check[i]--;
            }
        }
    }
    
    for(int c:check)if(c)answer++;
    return answer;
}
