#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

struct Robot{
    int r,c;
    const vector<int>* path;
    int idx;
    bool gone = false;
};

inline int key(int r, int c){return r*1000+c;}

int solution(vector<vector<int>> points, vector<vector<int>> routes){
    int nP = points.size();
    int nR = routes.size();
    
    vector<pair<int,int>> P(nP + 1);
    for(int i = 0; i< nP; ++i)
        P[i+1]= {points[i][0], points[i][1]};
    
    vector<Robot> robots(nR);
    for(int i = 0;i <nR;++i){
        robots[i].path=&routes[i];
        robots[i].idx=0;
        robots[i].r=P[routes[i][0]].first;
        robots[i].c=P[routes[i][0]].second;
    }
    
    long long risk = 0;
    int finished = 0;
    
    {
        unordered_map<int,int> cnt;
        for(auto& rb: robots)++cnt[key(rb.r,rb.c)];
        for(auto& kv:cnt) if(kv.second>=2)++risk;
    }
    
    while(finished<nR){
        vector<char> out(nR,0);
        
        for(int i =0;i<nR;++i){
            auto& rb = robots[i];
            if(rb.gone)continue;
            
            int trgR = P[(*rb.path)[rb.idx]].first;
            int trgC = P[(*rb.path)[rb.idx]].second;
            
            if(rb.r == trgR && rb.c==trgC){
                if(rb.idx+1==(int)rb.path->size()){
                    rb.gone=true;++finished;continue;
                }
                ++rb.idx;trgR=P[(*rb.path)[rb.idx]].first;trgC=P[(*rb.path)[rb.idx]].second;
            }
            if(rb.r !=trgR)rb.r+=(trgR>rb.r?1:-1);
            else if(rb.c!=trgC)rb.c+=(trgC>rb.c?1:-1);
            
            if(rb.idx==(int)rb.path->size()-1&&rb.r==trgR&&rb.c==trgC)out[i]=1;
        }
        unordered_map<int,int>cnt;
        for(int i =0;i<nR;++i)
            if(!robots[i].gone)++cnt[key(robots[i].r,robots[i].c)];
        for(auto& kv:cnt)if(kv.second>=2)++risk;
        for(int i=0;i<nR;++i)
            if(out[i]){robots[i].gone=true;++finished;}
    }
    return(int)risk;
}