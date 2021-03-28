#include <cstdio>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    queue<int> que;
    int n;
    scanf("%d", &n);
    
    for(int i =0; i < n; i++)
    {
        string s;
        cin >> s;
        
        if(s == "push")
        {
            int x;
            scanf("%d", &x);
            que.push(x);
        }
        else if(s == "front")
        {
            if(que.empty())
                printf("-1");
            else
                printf("%d", que.front());
            printf("\n");
        }
        else if(s == "back")
        {
            if(que.empty())
                printf("-1");
            else
                printf("%d", que.back());
            printf("\n");
        }
        else if(s == "pop")
        {
            if(que.empty())
                printf("-1");
            else
            {
                printf("%d", que.front());
                que.pop();
            }
            printf("\n");
        }
        else if(s == "size")
            printf("%d\n", que.size());
        else
        {
            if(que.empty())
                printf("1");
            else
                printf("0");
            printf("\n");
        }
    }
}