#include <cstdio>
#include <algorithm>    

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    int sum = 0;

    scanf("%d", &n);
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);  
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    
    sort(a, a + n, cmp);
    sort(b, b + n);

    for(int i = 0; i < n; i++)
    {
        sum += (a[i] * b[i]);
    }

    printf("%d\n", sum);
}