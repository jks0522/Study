#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Histogram {
public:
    int height; // 히스토그램 높이
    int leftX;  // 히스토그램 왼쪽 변의 x좌표
    int rightX; // 히스토그램 오른쪽 변의 x좌표

    Histogram() { }

    Histogram(int index, int height) {
        this->leftX = index;
        this->rightX = this->leftX + 1; // 각 히스토그램 너비는 1이므로 좌변에서 +1
        this->height = height;
    }
};

/**
 * 히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이를 계산하는 함수
 * const vector<Histogram>& histograms  검사할 벡터
 * 
 * return answer    직사각형 최대 넓이 반환
 */
long long getLargestRectangleArea(const vector<Histogram>& histograms) {
    long long answer = 0;   // int형의 범위를 넘어갈 수 있기 때문에 long long으로 선언

    stack<Histogram> continuedHistograms;   // Histogram 스택 선언

    continuedHistograms.push(Histogram(-1, 0)); // 가상의 히스토그램 push
    // 왼쪽 히스토그램부터 오른쪽까지 차례대로 검사
    for(int i = 0; i < histograms.size() + 1; i++) {
        Histogram h;    // Histogram 객체 선언
        if(i < histograms.size()) {
            h = histograms[i];
        } else {
            // 가장 오른쪽에 높이 0의 가상의 히스토그램 추가
            h = Histogram(histograms.size(), 0);
        }

        // 스택의 사이즈가 1보다 크고, h보다 높이가 높은 히스토그램이
        // 있을때만 루프
        while(continuedHistograms.size() > 1
            && continuedHistograms.top().height > h.height) {
            // 나중에 top값을 사용하기 위해 저장
            Histogram lh = continuedHistograms.top();
            continuedHistograms.pop();

            // 바로 전의 히스토그램
            Histogram bh = continuedHistograms.top();

            // bh의 오른쪽 변부터 h의 왼쪽변까지를 너비로
            // lh의 높이를 높이로
            // 두 값을 곱하여 히스토그램의 넓이를 구함
            long long width = abs(h.leftX - bh.rightX);
            long long height = lh.height;
            long long area = width * height;

            // 이미 구한 값보다 클 경우 갱신
            answer = max(answer, area);
        }
        
        // h를 스택에 push
        continuedHistograms.push(h);
        
    }
    return answer;  // 정답 리턴
    
}

/**
 * 테스트케이스 마다 히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이를 계산받아 출력하는 함수
 * caseIndex    테스트케이스 번호
 */
void process(int caseIndex) {
    int n;  // 기둥의 수
    cin >> n;   // 기둥의 수 입력받음

    vector<Histogram> histograms;   // Histogram 벡터 선언
    
    // n개의 높이를 입력받아 각각의 Histogram타입을 벡터에 push_back
    for(int i = 0; i < n; i++) {
        int height;
        cin >> height;
        histograms.push_back(Histogram(i, height));
    }

    // 히스토그램 내부에 존재할 수 있는 직사각형의 최대 넓이를 계산
    // 값이 int형 범위보다 커질 수 있기 때문에 long long으로 선언
    long long answer = getLargestRectangleArea(histograms);
    cout << answer << endl; // 정답 출력
}

int main() {
    int caseSize;   // 테이트케이스 개수
    cin >> caseSize;    // 테스트케이스 수 입력받음

    // 테스트케이스 마다 process함수를 통해 적절한 출력
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
}