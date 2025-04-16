#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string>board; 
map<char,vector<pair<int,int>>>Coldi;  

int dx[4] = {1, -1, 0,0};
int dy[4] = {0, 0, 1, -1};


bool isOut(int x, int y) {
    return x < 0|| y < 0||x>=n||y >= m;
}

vector<vector<bool>>getExternalEmpty() {
    vector<vector<bool>> ext(n,vector<bool>(m,false));
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    queue<pair<int,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
        
            if((i == 0||i==n-1||j ==0||j==m-1)&&board[i][j] =='.') {
                q.push({i,j});
                visited[i][j] =true;
                ext[i][j] =true;
            }
        }
    }
    

    while(!q.empty()) {
        auto [x, y] = q.front(); 
        q.pop();
        
        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!isOut(nx, ny) && !visited[nx][ny]&&board[nx][ny] == '.') {
                visited[nx][ny] =true;
                ext[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return ext;
}


bool isAccessible(int x, int y, const vector<vector<bool>> &ext) {
    for(int d=0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
 
        if(isOut(nx, ny)) return true;
      
        if(!isOut(nx, ny) && board[nx][ny] == '.' && ext[nx][ny]) {
            return true;
        }
    }
    return false;
}


int solution(vector<string> storage, vector<string> requests) {

    n = (int)storage.size();
    m = (int)storage[0].size();
    board = storage;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] != '.') {
                Coldi[board[i][j]].push_back({i, j});
            }
        }
    }
    

    for(const auto &req :requests) {
        char c = req[0];
       
        if(req.size()== 2) {
            if(Coldi.count(c)) {
                for(auto &pos : Coldi[c]) {
                    int x = pos.first, y = pos.second;
                 
                    if(board[x][y] == c) {
                        board[x][y] = '.';
                    }
                }
    
                Coldi[c].clear();
            }
        } 

        else {
    
            auto ext =getExternalEmpty();
            
            if(Coldi.count(c)) {
                vector<pair<int,int>>remain; 
                for(auto &pos : Coldi[c]) {
                    int x = pos.first, y = pos.second;

                    if(board[x][y] == c&&isAccessible(x,y,ext)) {
                        board[x][y] = '.';
                    } else {
                      
                        remain.push_back({x,y});
                    }
                }
          
                Coldi[c] = remain;
            }
        }
    }
    

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]!='.') answer++;
        }
    }
    return answer;
}
