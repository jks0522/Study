#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;  // 정수의 개수
    cin >> N;   // 정수의 개수 입력

    set<int> integers;  // 정수를 담을 세트

    for(int i = 0; i < N; i++) {
        int X;  // 정수 X
        cin >> X;   // 정수 X 입력

        // 세트에 이미 저장되어 있는 숫자일 경우 "DUPLICATED" 출력
        if(integers.count(X) > 0) {
            cout << "DUPLICATED" << "\n";
        } else {
            // 처음 등장한 숫자의 경우 세트에 담고 "OK" 출력
            integers.insert(X);
            cout << "OK" << "\n";
        }
    }

    return 0;
}