#include <iostream>
#include <cstdio>

using namespace std;

/**
 * 두 직사각형이 교차하는 영역의 넓이를 구하는 함수
 * la   직사각형 a의 왼쪽 x좌표
 * ra   직사각형 a의 오른쪽 x좌표
 * ta   직사각형 a의 위쪽 y좌표
 * ba   직사각형 a의 아래쪽 y좌표
 * lb   직사각형 b의 왼쪽 x좌표
 * rb   직사각형 b의 오른쪽 x좌표
 * tb   직사각형 b의 위쪽 y좌표
 * bb   직사각형 b의 아래쪽 y좌표
 * 
 * 교차하는 영역의 넓이를 반환
 */
int get_area(int la, int ra, int ta, int ba,
            int lb, int rb, int tb, int bb)
{
    /*
    * l     교차하는 영역의 왼쪽 x값
    * r     교차하는 영역의 오른쪽 x값
    * t     교차하는 영역의 위쪽 y값
    * b     교차하는 영역의 아래쪽 y값
    * 두 (x, y) 좌표는 대각선으로 마주보고 있음
    */
    int l, r, t, b;
    l = max(la, lb);    // 두 l값 중 큰 값이 교차하는 영역의 l 값
    r = min(ra, rb);    // 두 r값 중 작은 값이 교차하는 영역의 r값
    t = min(ta, tb);    // 두 t값 중 작은 값이 교차하는 영역의 t값
    b = max(ba, bb);    // 두 b값 중 큰 값이 교차하는 영역의 b값
    
    // l이 r보다 같거나작고, b가 t보다 작거나 같을 때만 성립
    if(l<=r && b<= t)
        return((r-l)*(t-b));    // 가로길이 * 세로길이

    return 0;
}

void test_case()
{
    int ax, ay, bx, by; // 직사각형 x의 두 점 좌표
    int px, py, qx, qy; // 직사각형 y의 두 점 좌표
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    int la, ra, ba, ta; // 직사각형 a
    la = min(ax, bx);
    ra = max(ax, bx);
    ta = max(ay, by);
    ba = min(ay, by);

    int lb, rb, bb, tb; // 직사각형 b
    lb = min(px, qx);
    rb = max(px, qx);
    tb = max(py, qy);
    bb = min(py, qy);

    // 두 직사각형이 교차하는 영역의 넓이를 구함
    int answer = get_area(la, ra, ta, ba,
                            lb, rb, tb, bb);

    printf("%d\n", answer); // 교차 영역 넓이 출력
}

int main() {
    int t;  // 테스트케이스의 수
    scanf("%d", &t);

    // t만큼 테스트케이스 함수 반복
    for(int i = 0; i < t; i++)
        test_case();

    return 0;
}