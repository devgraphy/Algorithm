/* ----------<문제 정의>----------
문제: 상수 시간에 최솟값을 push, pop, top, retrieve 를 지원하는 스택을 설계
최솟값은 최솟값대로 출력하고, 데이터의 LIFO 상태를 유지한다
-> LIFO인데 getMin은 그 당시 최솟값을 출력한다.
입력: -2^31 <= val <= 2^31 - 1
*/
/* ----------<시도한 알고리즘>----------
1. 스택 자료구조, 우선순위 큐 두 가지를 정의한다. (X)-> 최솟값 반환하고 최솟값을 pop 할 수 있어야 한다.

2. 잘못된 문제 정의
최솟값과 LIFO를 유지하는 스택 구현 -> getMin은 최솟값만 출력해주면 됨
MinStack을 호출할 때
최솟값을 반환하되 나머지는 LIFO 상태를 유지해야 한다.
Stack 자료구조 자체와 정렬하여 사용할 순 없음
 
stack에 일단 넣고 MinStack이 호출되면 PQ를 통해 최솟값을 받아서
최솟값이 나올 때까지 다른 stack에 push, 그 최솟값만 반환하고 PQ에서도 삭제, 이어서 push

3. minval 변수로 지속적인 최솟값 유지
pop해서 정보가 사라진 이후의 처리를 해주지 못한다.

*/
/* ----------<예외 케이스1>----------
알고리즘 3번의 경우,
스택이 비었을 때, 최솟값 정보를 초기화해주어야 한다.
아무것도 없는데 이전 최솟값을 유지한 상태이다.
*/
/* ----------<예외 케이스2>----------
알고리즘 3번의 경우,
pop하고 push 한 경우, 계속 minval 변수로만 비교하면 pop해서 사라진 최솟값 정보를 사용하게 된다.
pop하고 push 한경우, pop한게 최솟값이었다면 이전의 최솟값과 비교해주어야 한다.
따라서 별도의 변수 없이 top정보로만 해결할 수 있다.
top().second에서는 매 push마다 최솟값 정보를 가지도록 한다.
*/
/* ----------<알고리즘>----------
각 원소마다 최솟값이 달라질 수 있음. ->각 원소에 대해서 최솟값 정보를 가지도록 한다.
최솟값 비교는 top 정보와 비교한다. 왜냐하면 pop 후 push하는 경우에 대해서 최솟값을 동적으로 활용할 수 있어야 하기 때문이다. 
*/
/* ----------<새롭게 안 것>----------
pair 타입 stack 정의 방법: stack<int, int> (X) -> stack<pair<int,int>>
*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(make_pair(val,val));   
        }
        else{
            if(st.top().second > val)   //st.top().second : 현재까지의 최솟값 정보
                st.push(make_pair(val, val));
            else
                st.push(make_pair(val,st.top().second));
        }
    }  
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */