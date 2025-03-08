#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string,int>genreTotal;
    unordered_map<string,vector<pair<int,int>>>genreSongs;
    
    for(int i =0;i<genres.size();i++){
        genreTotal[genres[i]]+=plays[i];
        genreSongs[genres[i]].push_back({plays[i],i});
    }
    
    vector<pair<string, int>> genreOrder;
    for (auto &entry : genreTotal) {
        genreOrder.push_back({entry.first, entry.second});
    }
    sort(genreOrder.begin(), genreOrder.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    
    for (auto &genrePair : genreOrder) {
        string genre = genrePair.first;
        auto &songs = genreSongs[genre];
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });
        
        // 최대 2곡씩 선택합니다.
        for (int i = 0; i < songs.size() && i < 2; i++) {
            answer.push_back(songs[i].second);
        }
    }
    
    return answer;
}