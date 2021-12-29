#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, s = (1 << 20);
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        string str;
        int x;
        cin >> str;
        if(str != "all" && str != "empty")
            cin >> x;

        if(str == "add")
            s |= (1 << (x - 1));
        else if(str == "remove")
            s &= ~(1 << (x - 1));
        else if(str == "check")
        {
            if(s & (1 << (x - 1)))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(str == "toggle")
            s ^= (1 << (x - 1));
        else if(str == "all")
            s = (1 << 20) - 1;
        else
            s = (1 << 20);
    }

    return 0;
}