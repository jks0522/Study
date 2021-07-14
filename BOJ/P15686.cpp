#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, answer = 999999999;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

// 치킨 거리를 계산하는 함수
void calculate(const vector<pair<int, int>>& selected) {
    int sum = 0;
    for(int i = 0; i < house.size(); i++) {
        int minimum = 999999999;
        for(int j = 0; j < m; j++) {
            minimum = min(minimum, abs(selected[j].first - house[i].first) + abs(selected[j].second - house[i].second));
        }

        sum += minimum;
    }

    answer = min(answer, sum);
}

// 폐업시키지 않을 지킨집을 고르는 함수
void select(vector<pair<int, int>>& selected, int index) {
    if(selected.size() == m) {
        calculate(selected);
        return;
    }

    for(int i = index; i < chicken.size(); i++) {
        selected.push_back(chicken[i]);
        select(selected, i+1);
        selected.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int num;
            cin >> num;
            if(num == 2)
                chicken.push_back({i, j});
            else if(num == 1)
                house.push_back({i, j});
        }
    }

    vector<pair<int, int>> selected;

    select(selected, 0);

    cout << answer << '\n';

    return 0;
    
}