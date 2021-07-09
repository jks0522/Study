#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<double> st;
    int size = s.size();
    for(int i = 0; i < size; i++) {
        char c = s[i];
        if(c == '+' || c == '-' || c == '*' ||  c == '/' ) {
            double num2 = st.top();
            st.pop();
            double num1 = st.top();
            st.pop();
            switch(c){
                case '+':
                    st.push(num1 + num2);
                    break;
                case '-':
                    st.push(num1 - num2);
                    break;
                case '*':
                    st.push(num1 * num2);
                    break;
                case '/':
                    st.push(num1 / num2);
                    break;
            }

        } else {
            st.push(arr[c - 'A']);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';

    return 0;
}