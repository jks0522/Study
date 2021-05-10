#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// 2D상의 점을 나타낼 클래스
class Point2D {
public:
    int x;  // 점의 x 좌표
    int y;  // 점의 y 좌표
    int index;  // 점의 인덱스

    Point2D(int index, int x, int y) {
        this->index = index;
        this->x = x;
        this->y = y;
    }

    Point2D(int x, int y) {
        this->index = 1;
        this->x = x;
        this->y = y;
    }

    long long getSquaredDistanceTo(Point2D target) {
        // 두 좌표간의 제곱거리를 계산
        long long dx = abs(this->x - target.x);
        long long dy = abs(this->y - target.y);
        return dx * dx + dy * dy;
    }

    double getDistanceTo(Point2D target) {
        // 두 좌표간의 실수 거리를 계산
        long long sqd = this->getSquaredDistanceTo(target);
        return sqrt(sqd);
    }

    bool operator < (const Point2D& other) const {
        // 각 좌표의 우선순위를 비교하기 위한 비교 연산자

        // x좌표가 다르다면 x좌표를 기준으로 비교한다.
        if (this ->x != other.x) {
            return this->x < other.x;
        }

        // x좌표가 같다면 y좌표를 기준으로 비교한다.
        return this->y < other.y;
    }
};

/**
 * N개의 점 중 네 개로 만들 수 있는 정사각형의 넓이 중 최대값을 반환하는 함수
 * n    점의 개수
 * points   점들을 담고 있는 벡터
 */
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0;   // 최대값을 담을 변수

    // 모든 점을 set에 저장
    set<Point2D> pSet;
    for(int i = 0; i < n; i+= 1) {
        pSet.insert(points[i]);
    }

    for(int i = 0; i < n; i+= 1) {
        Point2D pa = points[i];
        for(int j = 0; j < n; j+= 1) {
            Point2D pb = points[j];
            // 두 기준점 pa와 pb를 지정한다.
            // 선분 pa-pb가 정사각형의 한 변이라고 하자.

            if (i == j) continue;   // 중복 되는 경우 제외

            // pa와 pb간의 제곱거리를 계산
            long long area = pa.getSquaredDistanceTo(pb);
            
            // 제곱 거리(정사각형의 넓이)가 이미 구해진 정사각형 넓이 answer 보다 작을 경우
            // 더 진행할 필요가 없으므로 continue
            if (area < answer)
                continue;

            // dx: pa, pb의 x좌표 차이, dy: y좌표 차이
            int dx = pb.x - pa.x;
            int dy = pb.y - pa.y;

            // pa, pb 기준 한쪽면만 pc, pd를 검사
            Point2D pd(pa.x - dy, pa.y + dx);
            Point2D pc(pb.x - dy, pb.y + dx);

            // pc, pd가 set에 존재하는 경우 정사각형 넓이를 answer와 비교해서 더 큰 값을 answer에 저장
            if (pSet.count(pc) > 0 && pSet.count(pd) >0) {
                answer = max(answer, area);
            }
        }
    }

    return answer;  // 정사각형의 최대 넓이를 반환
}

void process(int caseIndex) {
    int n;  // 좌표의 수
    cin >> n;   // 좌표의 수 입력

    vector<Point2D> points; // 좌표를 담을 Point2D 벡터

    // n개의 좌표를 입력받아 벡터에 저장
    for (int i =0 ; i < n; i += 1) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point2D(i, x, y));
    }

    // 정사각형 넓이 중 최대값을 구해 answer에 대입
    long long answer = getMaximumSquareArea(n, points);

    // 소수 둘째자리 까지 answer 출력
    cout << fixed << setprecision(2) << answer << endl;
}

int main() {
    int caseSize;   // 테스트케이스 개수
    cin >> caseSize;    // 테스트케이스 입력

    // 테스트케이스 개수만큼 process 함수 호출을 통해 문제 해결
    for(int caseIndex = 1; caseIndex <= caseSize ; caseIndex += 1) {
        process(caseIndex);
    }
}