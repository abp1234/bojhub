#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 유일성 확인
bool isUq(const vector<vector<string>>& rl, const vector<int>& cs) {
    set<string> st;
    for (const auto& rw : rl) {
        string k;
        for (int i : cs) k += rw[i] + "|";
        if (st.count(k)) return false;
        st.insert(k);
    }
    return true;
}

// 최소성 확인
bool isMn(const vector<vector<int>>& ck, const vector<int>& c) {
    for (const auto& k : ck) {
        bool f = true;
        for (int i : k)
            if (find(c.begin(), c.end(), i) == c.end())
                f = false;
        if (f) return false;
    }
    return true;
}

int solution(vector<vector<string>> rl) {
    int nc = rl[0].size(), nr = rl.size();
    vector<vector<int>> ck;
    vector<int> av; // 후보 조합 대상 컬럼 목록

    // 1. 단일 컬럼 유일성 확인
    for (int i = 0; i < nc; ++i) {
        vector<int> c = {i};
        if (isUq(rl, c)) {
            ck.push_back(c); // 후보키로 등록
        } else {
            av.push_back(i); // 조합 후보로 보류
        }
    }

    // 2. 보류된 컬럼들로 조합 확장하며 검사
    for (int l = 2; l <= av.size(); ++l) {
        vector<bool> sl(av.size(), false);
        fill(sl.end() - l, sl.end(), true);

        do {
            vector<int> c;
            for (int i = 0; i < av.size(); ++i)
                if (sl[i]) c.push_back(av[i]);

            if (!isMn(ck, c)) continue;
            if (isUq(rl, c)) ck.push_back(c);

        } while (next_permutation(sl.begin(), sl.end()));
    }

    return ck.size();
}
