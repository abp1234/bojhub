// #include <string>
// #include <vector>

// using namespace std;

// int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
//     int answer = 0;
    
//     // 반복문 schedules 순회 
//     // 반복문 해당 schedules에 대한 timelogs 순회 // 해당 schedules 에 +10을 한 값보다 작은 지 확인 클 경우 check 변수 1로 변경 후 break// 순회중 startday를 고려하여 6,7일은 제외 
//     // check 변수 0 일경우 answer+=1
//     return answer;
// }

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size();

    for (int i = 0; i < n; ++i) {
        bool late = false;
        for (int j = 0; j < 7; ++j) {
            int day = (startday + j - 1) % 7 + 1; 
            if (day == 6 || day == 7) continue;  

            if (timelogs[i][j] > ((schedules[i]/100+(schedules[i]%100 + 10)/60))*100 +((schedules[i] + 10)%100)%60) {
                late = true;
                break;
            }
        }
        if (!late) ++answer;
    }
    return answer;
}