#include <cstdio>

int calGcd(int num1, int num2);
int calLcm(int num1, int num2, int gcd);

int main()
{
    int t = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int num1 =0, num2 = 0, lcm = 0, gcd = 0;
        scanf("%d %d", &num1, &num2);

        if(num2 > num1)
            gcd = calGcd(num2, num1);
        else
            gcd = calGcd(num1, num2);

        lcm = calLcm(num1, num2, gcd);
        printf("%d\n", lcm);
    }
    
    return 0;

}

int calGcd(int num1, int num2)
{
    if(num1 % num2 == 0)
        return num2;
    else
        return calGcd(num2, num1%num2);
}

int calLcm(int num1, int num2, int gcd)
{
    return num1 * num2 / gcd;
}