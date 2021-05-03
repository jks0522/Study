#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Player{
public:
    int index;  // 플레이어의 인덱스

    Player(int index) {
        this->index = index;
    }
};

/**
 * 게임에서 제외된 플레이어의 리스트를 반환하는 함수
 * 
 * n    플레이어의 수
 * m    사람을 제외해 나갈 간격
 * players  1~n까지의 순서가 부여된 플레이어들의 리스트
 * 
 * 플레이어를 제외된 순서대로 담고 있는 벡터를 반환
 */
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players) {
    // 현재 게임에서 제외된 플레이어들의 리스트
    vector<Player> deadPlayers;

    // 아직 게임에서 제외되지 않는 플레이어들의 리스트
    queue<Player> playerQueue;

    // 플레이어의 리스트를 받아서 playerQueue에 넣음
    for(int i = 0; i < n; i++) {
        playerQueue.push(players[i]);
    }

    // 모든 플레이어가 제외될 때까지 반복
    while(!playerQueue.empty()) {
        // m-1번째까지 무시
        for(int i = 0; i < m - 1; i++) {
            // 맨 앞에 있는 값을 뒤로 옮기는 과정
            playerQueue.push(playerQueue.front());
            playerQueue.pop();
        }
        // m번째에 사람을 제외
        deadPlayers.push_back(playerQueue.front());
        playerQueue.pop();
    }

    return deadPlayers; // 제외된 순서를 반환
}

void process(int caseIndex) {
    int n, m;   // n: 플레이어의 수, m: 사람을 제외해 나갈 간격
    cin >> n >> m;  // n과 m을 입력받음

    vector<Player> players; // 플레이어를 순서를 담을 벡터
    for(int i = 0; i < n; i++) {
        players.push_back(Player(i + 1));   // 1부터 n까지 벡터에 담음
    }

    // 플레이어가 제외된 순서를 받아서 deadPlayers 벡터에 대입
    vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

    // n명의 사람들의 번호를 제외 된 순서대로 출력
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            cout << " ";
        }

        Player p = deadPlayers[i];  // i 번째로 제외된 사람
        cout << p.index;    // i 번째로 제외된 사람의 번호
    }

    cout << endl;
}

int main() {
    int caseSize;   // 테스트케이스 수
    cin >> caseSize;    // 테스트케이스 입력
    
    // 테스트케이스의 수 만큼 반복
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);
    }
}