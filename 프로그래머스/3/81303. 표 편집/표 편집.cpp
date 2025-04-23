#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    
    vector<int> prev(n),next(n);
    vector<bool> alive(n, true);
    stack<int> deleted;
    
    for(int i =0;i<n;i++){
        prev[i]=i-1;
        next[i]=i+1;
    }
    next[n-1]=-1;
    
    for(const string& c : cmd){
        if(c[0]=='U'){
            int x = stoi(c.substr(2));
            while(x--)k=prev[k];
        }
        else if(c[0]=='D'){
            int x = stoi(c.substr(2));
            while(x--)k=next[k];
        }
        else if(c[0]=='C'){
            deleted.push(k);
            alive[k]=false;
            if(prev[k]!=-1)next[prev[k]]=next[k];
            if(next[k]!=-1)prev[next[k]]=prev[k];
            k=(next[k]!=-1)?next[k]:prev[k];
        }
        else if(c[0]=='Z'){
            int r = deleted.top();deleted.pop();
            alive[r]=true;
            if(prev[r]!=-1)next[prev[r]]=r;
            if(next[r]!=-1)prev[next[r]]=r;
        }
    }
    
    
    
    string answer(n,'O');
    for(int i=0;i<n;i++){
        if(!alive[i]) answer[i]='X';
    }

    
    
    
    return answer;
}