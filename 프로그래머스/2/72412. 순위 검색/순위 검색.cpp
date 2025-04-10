#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> applicantMap;

 
    for (const string& im : info) {
        stringstream ss(im);
        string lang, job, career, food, scoreStr;
        ss >> lang >> job >> career >> food >> scoreStr;
        int score = stoi(scoreStr);
        
        vector<string> conditions = {lang, job, career, food};

        for (int i = 0; i < (1 << 4); ++i) {
            string key = "";
            for (int j = 0; j < 4; ++j) {
                if (i & (1 << j))
                    key += conditions[j];
                else
                    key += "-";
                if (j < 3)
                    key += " and ";
            }
            applicantMap[key].push_back(score);
        }
    }

   
    for (auto& entry : applicantMap) {
        sort(entry.second.begin(), entry.second.end());
    }

    for (const string& q : query) {
        stringstream ss(q);
        vector<string> tokens;
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        
        string key = tokens[0] + " and " + tokens[2] + " and " + tokens[4] + " and " + tokens[6];
        int score = stoi(tokens[7]);
        
     
        if (applicantMap.find(key) == applicantMap.end()) {
            answer.push_back(0);
        } else {
            const vector<int>& vec = applicantMap[key];
            auto it = lower_bound(vec.begin(), vec.end(), score);
            int count = vec.end() - it;
            answer.push_back(count);
        }
    }
    
    return answer;
}
