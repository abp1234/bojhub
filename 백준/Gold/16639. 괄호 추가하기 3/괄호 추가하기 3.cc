#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> getMaxMin(vector<vector<pair<int, int>>>& board, const vector<char>& oper, int i, int j) {
    vector<int> tmp;
    for (int mid = i; mid < j; mid++) {
        if (oper[mid] == '+') {
            tmp.push_back(board[i][mid].first + board[mid + 1][j].first);
            tmp.push_back(board[i][mid].first + board[mid + 1][j].second);
            tmp.push_back(board[i][mid].second + board[mid + 1][j].first);
            tmp.push_back(board[i][mid].second + board[mid + 1][j].second);
        }
        else if (oper[mid] == '-') {
            tmp.push_back(board[i][mid].first - board[mid + 1][j].first);
            tmp.push_back(board[i][mid].first - board[mid + 1][j].second);
            tmp.push_back(board[i][mid].second - board[mid + 1][j].first);
            tmp.push_back(board[i][mid].second - board[mid + 1][j].second);
        }
        else {
            tmp.push_back(board[i][mid].first * board[mid + 1][j].first);
            tmp.push_back(board[i][mid].first * board[mid + 1][j].second);
            tmp.push_back(board[i][mid].second * board[mid + 1][j].first);
            tmp.push_back(board[i][mid].second * board[mid + 1][j].second);
        }
    }
    return { *max_element(tmp.begin(), tmp.end()), *min_element(tmp.begin(), tmp.end()) };
}

int main() {
    int N;
    cin >> N;

    int n = N / 2;

    string formula;
    cin >> formula;

    vector<int> num;
    vector<char> oper;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) num.push_back(formula[i] - '0');
        else oper.push_back(formula[i]);
    }

    vector<vector<pair<int, int>>> board(n + 1, vector<pair<int, int>>(n + 1, { 0, 0 }));

    for (int scope = 0; scope <= n; scope++) {
        for (int i = 0; i + scope <= n; i++) {
            int j = i + scope;
            if (i == j) {
                board[i][j].first = num[i];
                board[i][j].second = num[i];
            }
            else {
                pair<int, int> res = getMaxMin(board, oper, i, j);
                board[i][j].first = res.first;
                board[i][j].second = res.second;
            }
        }
    }

    cout << board[0][n].first << '\n';
    return 0;
}