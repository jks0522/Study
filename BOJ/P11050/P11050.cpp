#include <cstdio>

int binomial(int n, int k);
int factorial(int n);

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int result = binomial(n, k);
    printf("%d", result);
    return 0;
}

int binomial(int n, int k)
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}

int factorial(int n)
{
    if(n <= 1)
        return 1;
    return factorial(n-1) * n;
}