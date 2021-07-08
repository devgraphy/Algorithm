/* ----------<문제 정의>----------
문제: 슬라이딩 윈도우 크기만큼만 평균값 계산
입력: 최대 1000개의 integer stream (size), 최대 1만번 (call)
출력: next 함수에서 평균값 계산하여 리턴
*/
/* ----------<알고리즘:o(size*call)>----------
 [MovingAverage(int size)]: 전역변수에 입력값 전달
 [double next(int val)]
    1.크기만큼 이전의 정보를 기억하고 있어야 하므로 벡터에 값을 추가한다.
    2. 벡터의 크기가 winsize와 같은지를 기준으로 계산에 사용하는 원소의 개수가 달라지므로 분기하여 처리한다.
        winsize보다 작으면
        winsize보다 크거나 같으면

        (winsize가 바뀔때 마다 sum을 새로 계산해주기 때문에 초기화를 해줘야 한다.)
        (intger stream이 최대 1000개 이고, 1만번 이상 불릴 수 있다.)
        (1만 *1천 = 천만  -> 시간 초과X 예상) => Accepted!

Runtime: 36 ms, faster than 15.84% of C++ online submissions for Moving Average from Data Stream.
Memory Usage: 14 MB, less than 14.78% of C++ online submissions for Moving Average from Data Stream.
*/
/* -----<생각 던지기>-----
next호출할 때마다 매번 window 크기만큼 매번 계산을 다시 해야할까?
- 이미 window 사이즈보다 넘치는 경우는 기존 기존 sum에 새로운 val을 추가하고 이전 winsize의 크기 안에 들어오는 원소 중 가장 먼저 들어온 원소를 빼주면 되지 않을까?
- 이미 window 사이즈만큼 안 차있는 경우에는 기존 sum에 그냥 더해주면 된다.
=> math를 이용하여 sliding window를 구현하자.
*/
/* ----------<시간개선 알고리즘:o(call)>----------
math

1. 벡터에 값 추가
2. double 타입의 sum 정의(실수로 표현하려면 반드시 연산자 중 하나는 실수 타입이어야 한다.)
3. 벡터 크기가 window size보다 크면(윈도우가 한 칸 이동하면서 합산에서 제외해야하는 원소가 발생한다)
    현재 원소부터 window 크기를 지정했을 때, 바로 직전의 원소를 sum에서 빼고, 새로오 들어온 값을 더해준다.
4. 작거나 같으면
    sum에 새로운 원소만 더한다.

Runtime: 20 ms, faster than 88.73% of C++ online submissions for Moving Average from Data Stream.
Memory Usage: 14 MB, less than 14.78% of C++ online submissions for Moving Average from Data Stream.
*/
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int winsize;
    vector<int> a;
    double sum = 0;
    MovingAverage(int size) {
        winsize = size;
    }

    double next(int val) {
        a.push_back(val);
        if(a.size() > winsize){ // window 크기보다 크면 기존 원소 하나를 버린다.
            sum += a[a.size()-1] - a[a.size()-winsize-1];
            return sum / winsize;
        }
        else{   // 작거나 같으면 sum에 새로운 val을 추가하여 계산한다.
            sum+=a[a.size()-1];
            return sum / a.size();
        }
    }
};