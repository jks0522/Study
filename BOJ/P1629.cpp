#include <iostream>
#include <cmath>

using namespace std;

long long solve(int a, int b, int c) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a%c;
    
    if( b % 2 == 1) return (solve(a, b-1, c) * a%c)%c;
    long long half = b/2;

    long long answer = solve(a, half, c);

    return (answer * answer)%c;
}

int main(void) {
    long long a, b, c;
    cin>>a>>b>>c;

    long long answer = solve(a, b, c);
    cout<<answer<<"\n";

    return 0;
}