#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;

/*
* 가위,바위,보에서 두 값을 받아 첫번째 값이 두번째 값을 상대한 결과를 숫자로 리턴해주는 함수
* c1	본인이 낸 손 모양
* c2	상대가 낸 손 모양
* c1이 c2를 이겼을 경우 2, 무승부일 경우 1, 졌을 경우 0을 리턴
*/
int match(char c1, char c2)
{
	if (c1 == 'R')	// c1이 주먹(R)을 냈을 때
	{
		if (c2 == 'S')	// c2가 가위(S)를 내면 c1의 승
			return 2;
		else if (c2 =='R')	// c2가 바위(R)를 내면 무승부
			return 1;
	}
	else if (c1 == 'S')	// c1이 가위를 냈을 때
	{
		if (c2 == 'P')	// c2가 보(P)를 내면 c1의 승
			return 2;
		else if (c2 == 'S')	// C2가 가위를 내면 무승부
			return 1;
	}
	else // c1이 보를 냈을 때
	{
		if (c2 == 'R')	// c2가 주먹을 내면 c1의 승
			return 2;
		else if (c2 == 'P')	// c2가 보를 내면 무승부
			return 1;
	}

	return 0;	// 나머지는 c1이 c2에게 졌을 경우이므로 0을 리턴
}

int main(void)
{
    int r, n;	// r: 라운드의 수, n: 전남이가 상대할 친구들의 수
    int score = 0, high = 0;	// score: 전남이의 총 점수를 담을 변수, high: 전남이가 얻을 수 있는 최고 점수를 담을 변수
	char* jnu;	// 전남이가 낸 모양을 담을 문자열의 포인터
	string* friends;	// 친구들이 낸 모양을 담을 문자열의 포인터
	
    cin >> r;	// 라운드의 수를 입력받아 r에 저장
	jnu = new char[r];	// 길이가 r인 문자 배열을 jnu에 할당
	cin >> jnu;	// 전남이가 낸 모양을 문자열로 받아 jnu에 저장
	cin >> n;	// 친구들의 수를 입력받아 n에 저장
    friends = new string[n];	//길이가 n인 string 배열을 friends에 할당
	for (int i = 0; i < n; i++) // 친구의 수 n만큼 반복
	{
		cin >> friends[i];	// 친구가 낸 모양을 문자열로 받아 friends에 저장
	}
    
    clock_t start = clock();	// 입력을 다 받은 후 시작 시간 저장

	// 전남이의 총 점수를 구하기 위한 반복문
	// 한 명당 r라운드 까지 match함수를 통해 결과를 score에 저장. 총 n명을 다 상대할 때까지 반복.
    for (int i =0; i < n; i++)	
    {
        for(int j= 0; j < r; j++)
        {
            score += match(jnu[j], friends[i].at(j));	// i번째 친구의 j번째 라운드에 낸 모양과 대결
        }
    }

	// 문제의 가정을 통해 전남이가 얻을 수 있는 최고 점수를 얻기 위한 반복문
	// 라운드 별로 n명의 친구들과 주먹, 가위, 보로 겨룬 결과를 각각 rock, scissors, paper에 저장함
	// 세 값중 가장 큰값을 high변수에 더해나감
	for (int i = 0; i < r; i++)	// r개의 라운드를 모두 할 때까지 반복
	{
		int rock = 0;	// 주먹을 냈을 때 전남이가 얻는 점수를 저장하는 변수
		int scissors = 0;	// 가위를 냈을 때 전남이가 얻는 점수를 저장하는 변수
		int paper = 0;	// 보를 냈을 때 전남이가 얻는 점수를 저장하는 변수
		for(int j = 0; j < n; j++)	// 한 라운드마다 친구의 수만큼 가위바위보를 겨룸
		{
			rock += match('R', friends[j].at(i));	// i라운드에 n명을 상대로 주먹을 냈을 때 얻는 점수의 합을 rock에 저장
			scissors += match('S', friends[j].at(i));	// i라운드에 n명을 상대로 가위를 냈을 때 얻는 점수의 합을 scissors에 저장
			paper += match('P', friends[j].at(i));	// i라운드에 n명을 상대로 보를 냈을 때 얻는 점수의 합을 paper에 저장
		}
		high += max(max(rock, scissors), paper);	// 세 값중 가장 큰 값이 라운드 최고 점수이므로 high에 더함
	}

	cout << score << endl;	// 전남이의 총 점수를 출력
	cout << high << endl;	// 전남이가 얻을 수 있는 최고 점수를 출력

	clock_t end = clock();	// 출력이 다 끝난 후 시간 저장

	cout << "실행시간: " <<(double)(end - start) / CLOCKS_PER_SEC<<"초";	// end와 start의 차이를 CLOCKS_PER_SEC로 나누어서 실행시간을 초단위로 출력

}