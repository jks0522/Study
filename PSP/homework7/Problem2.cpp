#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Tower {
public:
    int index;  // 타워의 인덱스
    int height; // 타워의 높이
    int targetTowerIndex;   // 이 타워의 레이저를 수신하는 타워의 인덱스

    Tower(int index, int height) {
        this->index = index;
        this->height = height;
        this->targetTowerIndex = 0;
    }

    // targetTowerindex를 설정하는 메소드
    void setTargetTowerIndex(int targetTowerIndex) {
        this->targetTowerIndex = targetTowerIndex;
    }

    // targetTowerIndex를 받는 메소드
    int getTargetTowerIndex() {
        return this->targetTowerIndex;
    }
};

/**
 * 각각의 탑들에서 발사한 레이저 신호를 수신한 탑들의 번호를 계산하는 함수
 * vector<Tower>& towers    계산할 벡터
 * 
 * 계산결과를 각 원소의 targetTowerindex에 저장함
 */
void findTargetTowers(vector<Tower>& towers) {
    stack<Tower> touchableTowers;   // 스택 선언

    // 타워의 개수만큼 반복
    for(int i = 0; i < towers.size(); i++) {
        Tower& t = towers[i];   // 벡터의 i번째 원소를 t에 대입
        int targetTowerIndex = 0;   // 타겟 타워 인덱스를 0으로 초기화

        // 스택이 비어있지 않고, 맨 위 원소의 높이가 t의 높이보다 작다면 pop
        while(touchableTowers.empty() == false
                && touchableTowers.top().height < t.height) {
                    touchableTowers.pop();
        }

        // pop이 끝나고 남아있는 원소가 있을 경우
        // targetTowerIndex를 top원소의 index 값으로 바꿈
        if(touchableTowers.size() > 0) {
            targetTowerIndex = touchableTowers.top().index;
        }

        // 바뀐 targetTowerIndex를 t의 targetTowerIndex에 대입
        t.setTargetTowerIndex(targetTowerIndex);

        touchableTowers.push(t);    // t를 스택에 push

    }
}

int main() {
    int n;  // 타워의 수
    cin >> n;   // 타워의 수를 입력받음

    vector<Tower> towers;   // Tower 벡터 선언
    // n개의 높이를 입력받아 Tower타입의 값을 벡터에 저장
    for(int i = 0; i < n; ++i) {
        int hi;
        cin >> hi;
        towers.push_back(Tower(i + 1, hi));
    }

    // 각각의 탑들에서 발사한 레이저 신호를 수신한 탑들의 번호를 계산
    findTargetTowers(towers);

    // 빈 칸으로 구분하여 수신한 탑을 하나씩 출력
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            cout << " ";
        }

        Tower t = towers[i];
        // TargetTowerIndex 값을 받아서 변수에 대입
        int targetIndex = t.getTargetTowerIndex();
        cout << targetIndex;
    }
}