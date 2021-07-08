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
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int winsize;
    vector<int> a;
    MovingAverage(int size) {   // 사이즈 크기 입력
        winsize = size;
    }
    
    double next(int val) {   // 입력 인자에 대해서 슬라이딩 윈도우 크기만큼 평균값 계산
        a.push_back(val);
        
        if(a.size() >= winsize){
            double sum = 0;
            for(int i = 0; i < winsize;i++){
                sum += a[a.size()-i-1];
            }
            return sum/winsize;
        }
        else{
            double sum = 0;
            for(int i = 0; i < a.size();i++)
                sum += a[i];
            return sum/a.size();
        }
        
    }
};
