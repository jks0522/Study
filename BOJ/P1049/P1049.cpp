#include <cstdio>

int main()
{
    int n, m;
    int packMin, pieceMin;
    int result = 0;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        int pack, piece;
        scanf("%d %d", &pack, &piece);
        if(i == 0)
        {
            packMin = pack;
            pieceMin = piece;
        } else {
            if(packMin > pack)
                packMin = pack;
            if(pieceMin > piece)
                pieceMin = piece;
        }
    }

    if(packMin < pieceMin*6)
    {
        result = (n / 6) * packMin + (n % 6) * pieceMin;
        int result2 = (n / 6 + 1) * packMin;
        if(result2 < result)
            result = result2;
    } else {
        result = n * pieceMin;
    }

    printf("%d", result);
}