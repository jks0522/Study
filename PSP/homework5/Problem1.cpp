#include <cstdio>

using namespace std;

// 최대 행, 열 크기 선언
const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard{
public:
    // 칸의 번호로 행의 번호를 계산하는 메소드
    int getRowByIndex(int index) {
        return (index - 1) / 9 + 1;
    }

    // 칸의 번호로 열의 번호를 계산하는 메소드
    int getColByIndex(int index) {
        return (index - 1) % 9 + 1;
    }

    // 칸의 번호로 그룹 번호를 계산하는 메소드
    int getGroupByIndex(int index) {
        int r = getRowByIndex(index);
        int c = getColByIndex(index);
        return getGroupByPosition(r,c);
    }

    // 칸의 위치 (행, 열)로 그룹 번호를 계산하는 메소드
    int getGroupByPosition(int row, int column) {
        // 그룹의 3개 행 중 어느 행인지 구함
        int left = ((row - 1) / 3 ) * 3 + 1;
        // 그룹의 3개 열 중 어느 열인지 구함
        int offset = ((column - 1) / 3);
        return left + offset;   // 두 값을 더한게 그룹의 번호
    }

    // 칸의 위치 (행, 열)로 칸의 번호를 계산하는 메소드
    int getIndexByPosition(int row, int column) {
        return (row - 1) * 9 + (column - 1) % 9 + 1;
    }
};

/*
* index를 입력받고 해당 인덱스의 행, 열, 그룹 번호를 출력해주는 함수
* caseIndex     테스트케이스 번호
*/
void process(int caseIndex) {
    int index;  // 1 ~ 81 사이의 자연수
    scanf("%d", &index);    // index 입력

    SudokuBoard board = SudokuBoard();  // SudokuBoard 객체 생성

    // 칸의 번호로 행, 열, 그룹 번호를 계산한다
    int row = board.getRowByIndex(index);
    int col = board.getColByIndex(index);
    int group = board.getGroupByIndex(index);

    printf("Case #%d:\n", caseIndex);   // 테스트케이스 번호 출력
    printf("%d %d %d\n", row, col, group);  // 행, 열, 그룹 번호를 공백으로 구분하여 출력
}

int main() {
    int caseSize;   // 테스트케이스의 수
    scanf("%d", &caseSize); // 테스트케이스를 입력받음

    for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
        process(caseIndex); // 테스트케이스의 수 만큼 process 함수 호출
    }

    return 0;
}