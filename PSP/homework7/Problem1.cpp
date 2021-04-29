#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// 괄호 문자열을 위한 클래스
class Parenthesis {
public:
    bool type;  // 열린 괄호면 true, 닫힌 괄호면 false
    int index;  // 해당 괄호의 인덱스

    // index와 bool 값을 받아서 index와 type에 대입
    Parenthesis(int index, bool type) {
        this->index = index;
        this->type = type;
    }

    // index와 문자를 받아서 문자가 '('일 경우 type은 true
    // 문자가 ')'일 경우 type은 false
    Parenthesis(int index, char c) {
        this->index = index;
        if(c == '(') {
            this->type = true;
        } else {
            this->type = false;
        }
    }
};

/**
 * 올바른 괄호 문자열(VPS)인지 검사하는 함수
 * const vector<Parenthesis>& parentheses   검사할 벡터
 * 
 * 올바른 VPS면 true, 아니면 false 반환
 */
bool isValidParentheses(const vector<Parenthesis>& parentheses) {
    // 현재 짝을 찾지 못한 열린 괄호들
    stack<Parenthesis> myStack;
    
    // 벡터안에 있는 parentheses 하나하나 검사
    for(int i = 0; i < parentheses.size(); i++) {
        Parenthesis p = parentheses[i];

        // type이 true일 경우('('일 경우) 스택에 push
        if(p.type == true) {
            myStack.push(p);
        } else if(p.type == false) {
            // type이 false일 경우(')'일 경우)
            // 스택이 비어있지 않으면 pop
            // 스택이 비어있으면 짝이 안맞는 경우이므로 false 리턴
            if(myStack.size() > 0) {
                myStack.pop();
            } else {
                return false;
            }
        }
    }
    // 벡터를 다 검사했는데 스택에 원소가 남아있으면
    // 짝이 안 맞는 괄호가 남아있다는 뜻이므로 false 리턴
    if(myStack.size() > 0) {
        return false;
    }
    
    // 나머지 경우에는 true 리턴
    return true;
}

/**
 * 테스트케이스마다 과정을 처리하는 함수
 * caseIndex    테스트케이스 번호
 * 
 * VPS이면 "YES" 출력, 아니면 "NO" 출력
 */
void process(int caseIndex) {
    string str; // 괄호 문자열
    cin >> str; // 괄호 문자열을 입력 받음

    vector<Parenthesis> parentheses;    // Parenthesis 타입을 담을 벡터 선언
    // Parenthesis 타입의 값을 벡터에 하나하나 넣어줌
    for (int i = 0; i < str.length(); ++i) {
        parentheses.push_back(Parenthesis(i, str[i]));
    }

    // 유효한 VPS인지 검사
    bool isValid = isValidParentheses(parentheses);

    // 유효한 VPS일 경우 "YES"출력, 아닐 경우 "NO" 출력
    if (isValid) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int caseSize;   // 테스트케이스 개수
    cin >> caseSize;    // 테스트케이스 개수 입력

    // 테스트케이스 수 만큼 process 함수 호출을 통해 문제 해결
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
}