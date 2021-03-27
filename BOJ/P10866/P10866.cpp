#include <cstdio>
#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    deque<int> deq;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(s == "push_back")
        {
            int x;
            scanf("%d", &x);
            deq.push_back(x);
        } else if(s == "push_front") {
            int x;
            scanf("%d", &x);
            deq.push_front(x);
        } else if(s == "front") {
            if(deq.empty())
                printf("-1\n");
            else
                printf("%d\n", deq.front());
        } else if(s == "back") {
            if(deq.empty())
                printf("-1\n");     
            else      
                printf("%d\n", deq.back());
        } else if(s == "size") {
            printf("%d\n", deq.size());
        } else if(s == "pop_front") {
            if(deq.empty())
                printf("-1\n");
            else {
                printf("%d\n", deq.front());
                deq.pop_front();
            }
        } else if(s == "pop_back") {
            if(deq.empty())
                printf("-1\n");
            else {
                printf("%d\n", deq.back());
                deq.pop_back();
            }
        } else if(s == "empty") {
            if(deq.empty())
                printf("1\n");
            else
                printf("0\n");
        }
    }

    return 0;
}