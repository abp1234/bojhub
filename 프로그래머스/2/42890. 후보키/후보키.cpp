#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <algorithm>

using namespace std;

bool isUq(const vector<vector<string>>& rl, const vector<int>& cs){
    set<string> st;
    for(const auto& rw : rl){
        string k;
        for(int i : cs)k+=rw[i]+"|";
        if(st.count(k))return false;
        st.insert(k);
    }
    return true;
}

bool isMn(const vector<vector<int>>& ck, const vector<int>& c){
    for(const auto& k : ck){
        bool f = true;
        for(int i : k)
            if(find(c.begin(),c.end(),i)==c.end())
                f=false;
        if(f) return false;
    }
    return true;
}


int solution(vector<vector<string>> relation) {
    int answer = 0;
    int nc =relation[0].size(),nr=relation.size();
    vector<vector<int>> ck;
    
    for(int l =1;l<=nc;++l){
        vector<int> id(nc);
        for(int i =0; i<nc; ++i)id[i]=i;
        
        vector<bool> sl(nc,false);
        fill(sl.end()-l, sl.end(),true);
        do{
            vector<int> c;
            for(int i =0; i<nc;++i)
                if(sl[i])c.push_back(id[i]);
            if(!isMn(ck,c))continue;
            if(isUq(relation,c))ck.push_back(c);
        }while(next_permutation(sl.begin(),sl.end()));
    }
    
    answer=ck.size();
    return answer;
}