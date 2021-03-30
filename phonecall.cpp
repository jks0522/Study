#include <cstdio>

using namespace std;

const int MAX_TABLE_LENGTH = 10000;

void fillFrequencyTable(int data[], int n, int table[]) {
    for(int i = 0; i < MAX_TABLE_LENGTH; i++)
    {
        table[i] = 0;
    }
    for(int i = 0; i < n; i++)
    {      
        table[data[i]]++;
    }

}

int getFrequentNumber(int data[], int n) {
    int frequent_number = 0; // 가장 많이 등장한 번호를 담기 위한 변수

    int table[MAX_TABLE_LENGTH]; // 0~9999까지 숫자의 횟수를 카운트하는 히스토그램
    fillFrequencyTable(data, n, table); 

    for(int i = 0; i < MAX_TABLE_LENGTH; i++)
    {
        if(table[i] > table[frequent_number])
            frequent_number = i;
    }

    return frequent_number;
}

int main() {
    int n;

    scanf("%d", &n);
    int* data = new int[n];

    for (int i =0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    int answer = getFrequentNumber(data, n);

    printf("%04d", answer);

    delete[] data;
    
    return 0;
}