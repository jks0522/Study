#include <cstdio>
#include <vector>

using namespace std;

class TicketTable {
public:
    vector<bool> used;  // 다른 사람에게 지급된 상태인지를 저장하기 위한 벡터
    int length; // 행운권 번호의 개수

    TicketTable(int length) {
        this->length = length;
        this->used.assign(length, false);   // used 벡터를 length크기만큼 false로 초기화
    }

    /**
     * 사용자의 회원 번호로 지급받게 될 행운의 번호를 계산하는 메소드
     */
    int findEmptyIndexByUserId(int userId) {
        int index = userId % length;    // 처음확인해볼 행운권 번호
        while (this->isEmpty(index) == true) {
            // 아무에게도 지급되지 않은 번호를 찾을 때 까지 행운권 번호 +1씩 증가
            index = (index + 1) % length;
        }
        return index;   // 당첨된 행운권 번호를 반환
    }

    /**
     * 해당 행운권 번호가 이미 사용 중인지 여부를 반환하는 메소드
     */
    bool isEmpty(int ticketIndex) {
        return this->used[ticketIndex];
    }

    /**
     * 티켓 사용 여부를 갱신하기 위한 메소드
     */
    void setUsed(int index, bool status) {
        this->used[index] = status;
    }
};

/**
 * 회원들에게 행운권을 지급하는 함수
 * n    전체 티켓의 수
 * m    요청 고객의 수
 * vector<int>& dis     회원들의 회원번호를 저장한 벡터
 * 
 * 회원들이 순서대로 지급받게 될 행운권 번호를 담고 있는 벡터를 반환
 */
vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
    vector<int> tickets;    // 지급된 행운권 번호를 담을 벡터
    TicketTable table = TicketTable(n);     // TicketTable 객체 선언

    for(int i = 0; i < m; i++) {
        int userId = ids[i];    // i 번쨰 회원의 아이디
        int ticketIndex = table.findEmptyIndexByUserId(userId); // 해당 회원에게 지급될 행운권 번호를 받아옴
        tickets.push_back(ticketIndex); // 벡터의 뒤에 해당 값을 집어넣는다
        table.setUsed(ticketIndex, true);   // 해당 인덱스를 이미 지급한것으로 표시하기 위해 setUsed 메소드 사용
    }

    return tickets;
}

int main() {
    // n: 전체 티켓의 수
    // m: 요청 고객의 수
    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> ids(m); // 회원번호를 담을 벡터
    for (int i = 0; i < m; ++i) {
        scanf("%d", &ids[i]);   // 한명씩 회원번호 입력
    }

    vector<int> tickets = getTicketNumbers(n, m, ids);  // 지급된 행운권 번호를 담은 벡터
    for(int i = 0; i < tickets.size(); ++i) {
        printf("%d\n", tickets[i]); // 행운권 번호를 한줄씩 출력함
    }

    return 0;
}