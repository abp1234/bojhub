#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    string friends = "ACFJMNRT";
    
    do{
        bool valid = true;
        for(const string &condition : data){
            char first = condition[0];
            char second = condition[2];
            char op = condition[3];
            int num = condition[4]-'0';
            
            int pos1 = friends.find(first);
            int pos2 = friends.find(second);
            int gap = abs(pos1 - pos2) - 1;
            
            if(op=='='){
                if(gap!=num){valid=false;break;}
            }else if(op=='<'){
                if(gap>=num){valid=false;break;}
            }else if(op=='>'){
                if(gap<=num){valid=false;break;}
            }
        }
        if(valid)answer++;
    }while(next_permutation(friends.begin(),friends.end()));
    
    
    return answer;
}