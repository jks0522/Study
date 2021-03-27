#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b))
            return a > b;
        else
            return abs(a)>abs(b);
    }
};

int main()
{
    int n = 0;
    priority_queue<int, vector<int>, cmp> pq;

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