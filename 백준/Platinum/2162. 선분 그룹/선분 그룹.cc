#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

using namespace std;

struct Point {
	int x, y;
	Point(int x =0, int y =0):x(x),y(y){}
};

struct Line
{
	Point p1, p2;
	Line(Point p1, Point p2) : p1(p1),p2(p2){}
};

int findParent(vector<int>& parent, int x) {
	if (parent[x] != x) {
		parent[x] = findParent(parent, parent[x]);
	}
	return parent[x];
}

void unionParent(vector<int>& parent, int a, int b) {
	a = findParent(parent, a);
	b = findParent(parent, b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int direction(const Point& a, const Point& b, const Point& c) {
	int dxab = b.x - a.x;
	int dxac = c.x - a.x;
	int dyab = b.y - a.y;
	int dyac = c.y - a.y;

	if (dxab * dyac < dyab * dxac)return 1;
	if (dxab * dyac > dyab * dxac)return -1;
	if (dxab == 0 && dyab == 0)return 0;
	if (dxab * dxac < 0 || dyab * dyac < 0)return-1;
	if (dxab * dxab + dyab * dyab >= dxac * dxac + dyac * dyac)return 0;
	return 1;
}



bool intersection(const Line& l1, const Line& l2) {
	if (direction(l1.p1, l1.p2, l2.p1) * direction(l1.p1, l1.p2, l2.p2) <= 0 &&
		direction(l2.p1, l2.p2, l1.p1) * direction(l2.p1, l2.p2, l1.p2) <= 0) {
		return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;

	vector<Line> lines;
	vector<int> parent(N);
	iota(parent.begin(), parent.end(), 0);

	for (int i = 0; i < N; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		lines.push_back(Line(Point(x1, y1), Point(x2, y2)));
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (intersection(lines[i], lines[j])) {
				unionParent(parent, i, j);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		parent[i] = findParent(parent, i);
	}
	map<int, int> cnt;
	for (int i = 0; i < N; ++i) {
		cnt[parent[i]]++;
	}

	cout << cnt.size() << '\n';
	cout << max_element(cnt.begin(), cnt.end(),
		[](const pair<int, int>& a, const pair<int, int>& b) {
			return a.second < b.second;
		})->second << '\n';

}
