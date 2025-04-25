#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Row[101][101];
bool Col[101][101];
int N;

bool isValid(int x,int y){
    if(Row[x][y]){
        if(y==0||Row[x][y-1]||Col[x][y]||(x>0&&Col[x-1][y]))
            ;
        else return false;
    }
    if(Col[x][y]){
        if((Row[x][y-1])||(Row[x+1][y-1])||(x>0&&Col[x-1][y]&&Col[x+1][y]))
            ;
        else return false;
    }
    return true;
}
bool isAllValidAround(int x,int y){
    for(int dx=-1;dx<=1;++dx){
        for(int dy=0;dy<=1;++dy){
            int nx = x+dx;
            int ny =y+dy;
            if(nx>=0&&ny>=0&&nx<=N&&ny<=N){
                if(!isValid(nx,ny))return false;
            }
        }
    }
    return true;
}
vector<vector<int>>solution(int n,vector<vector<int>>build_frame){
    N=n;
    for(auto cmd:build_frame){
        int x = cmd[0],y=cmd[1],a=cmd[2],b=cmd[3];
        if(a==0){
            if(b==1){
                Row[x][y]=true;
                if(!isValid(x,y))Row[x][y]=false;
            }else{
                Row[x][y]=false;
                if(!isAllValidAround(x,y))Row[x][y]=true;
            }
        }else{
            if(b==1){
                Col[x][y]=true;
                if(!isValid(x,y))Col[x][y]=false;
            }else{
                Col[x][y]=false;
                if(!isAllValidAround(x,y))Col[x][y]=true;
            }
        }
    }
    vector<vector<int>>answer;
    for(int x=0;x<=N;++x){
        for(int y=0;y<=N;++y){
            if(Row[x][y])answer.push_back({x,y,0});
            if(Col[x][y])answer.push_back({x,y,1});
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}


