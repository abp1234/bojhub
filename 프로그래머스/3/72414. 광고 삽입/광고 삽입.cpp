#include <string>
#include <vector>

using namespace std;

inline int toSec(const string& hms){
    return stoi(hms.substr(0,2))*3600+
        stoi(hms.substr(3,2))*60+
        stoi(hms.substr(6,2));
}
inline string toHMS(long long s){
    int h = s/3600; s%=3600;
    int m = s/60; s%=60;
    int sec = s;
    char buf[9];
    sprintf(buf, "%02d:%02d:%02d",h,m,sec);
    return string(buf);
}


string solution(string play_time, string adv_time, vector<string> logs) {
    const int PLAY = toSec(play_time);
    const int ADV = toSec(adv_time);
    
    vector<long long> sumCnt(PLAY + 1, 0);
    
    for(const string& lg : logs){
        int s = toSec(lg.substr(0,8));
        int e = toSec(lg.substr(9,8));
        sumCnt[s]+=1;
        sumCnt[e] -= 1;
    }
    
    for(int t = 1; t<=PLAY;++t)
        sumCnt[t]+=sumCnt[t-1];
    vector<long long> acc(PLAY+2,0);
    for(int t = 1;t<=PLAY;++t)
        acc[t]=acc[t-1]+sumCnt[t-1];
    
    long long bestSum=-1;
    int bestStart=0;
    for(int s=0;s+ADV<=PLAY;++s){
        long long cur = acc[s+ADV]-acc[s];
        if(cur>bestSum){
            bestSum=cur;
            bestStart=s;
        }
    }
    return toHMS(bestStart);
    
    
    
   // return;
}
    //sumCnt 누적합 배열 선언 초단위
    // logs 순회 하며 배열에 기록
    // 슬라이딩 윈도우를 통해 최대 결과 위치 찾기 
    // 반환
    
    
//logs.sorts(빠른순으로)
    // heapq에 끝나는 숫자 를 top이 빠른 시간이 오도록 넣고, 현재 넣는 숫자의 시작 시간 보다 빠른 끝나는 시간을 pop
    // 현재 큐안의 숫자를 계산, 및 최대 값 비교 시작 시간과 최대값기록
    // 최대 시작 시간을 리턴