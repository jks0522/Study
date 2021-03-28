#include <cstdio>

void p(int n);

int main()
{
    int t;
    scanf("%d", &t);

    for(int i= 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        p(n);
    }
}

void p(int n)
{
    long long* arr = new long long[n];

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for(int i = 3; i < n; i++)
    {
        arr[i] = arr[i -2] + arr[i - 3];
    }

    printf("%lld\n", arr[n-1]);
}