#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int x = 0;
        scanf("%d", &x);
        
        if(x == 0)
        {
            if(pq.empty())
                printf("0");
            else {
                printf("%d", pq.top());
                pq.pop();
            }
            printf("\n");
        } else {
            pq.push(x);
        }
    }
}