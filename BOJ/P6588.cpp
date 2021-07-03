#include <iostream>
#include <vector>

using namespace std;

void checkPrime(vector<int>& prime, int n) {
    for(int i = 2; i <= n; i++) {
        if(prime[i] == 0) {
            prime[i] = 1;
            for(int j = 2; i * j <= n; j++) {
                prime[i*j] = -1;
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> testcase;
    int max = 0;
    
    while(true) {
        int n;
        cin >> n;
        if(n == 0)
            break;
        testcase.push_back(n);
        if(n > max)
            max = n;
    }

    vector<int> prime(max + 1, 0);
    checkPrime(prime, max);

    for(int i = 0; i < testcase.size(); i++) {
        int num = testcase[i];
        bool isPossible = false;

        for(int j = num-2; j*2 >= num; j--) {
            if(prime[j] == 1 && prime[num-j] == 1) {
                cout << num << " = " << num-j << " + " << j << '\n';
                isPossible = true;
                break;
            }
        }

        if(!isPossible)
            cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
