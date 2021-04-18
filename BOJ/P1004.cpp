#include <cstdio>

int main() {
    int t, x1, x2, y1, y2, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int count = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for(int j = 0; j < n; j++) {
            int c1, c2, r, d1, d2;
            scanf("%d %d %d", &c1, &c2, &r);
            d1 = (x1-c1)*(x1-c1) + (y1-c2)*(y1-c2);
            d2 = (x2-c1)*(x2-c1) + (y2-c2)*(y2-c2);
            if(d1 < r*r) {
                if(d2 > r*r)
                    count++;
            } else {
                if(d2 < r*r)
                    count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}