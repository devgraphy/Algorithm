/* ----------<문제 정의>----------
문제: 스택에서 최댓값을 찾아 삭제하는 popMax를 구현한다.
*/
/* ----------<알고리즘>----------
MinStack과 반대로 한다.
popMax(): 최댓값을 찾아 그 원소만 빼고 다시 원래의 스택에 넣는다.
*/
/* ----------<예외 케이스>----------
1. popMax: 가장 상단의 최댓값 원소를 하나만 제거해줘야 하는데, 반복문을 빠져나가지 않으면 최댓값과 같은 원소를 모두 제거하게 된다.
2. 
    Input: ["MaxStack","push","push","popMax","peekMax"] [[],[5],[1],[],[]]
    Output: [null,null,null,5,5]
    Expected: [null,null,null,5,1]
    => 삭제된 원소 위로 최댓값이 갱신되지 않았다.
    
    peekMax: popMax로 최댓값이 사라졌을 경우에 peekMax의 값도 바뀐다.
    제거된 원소 바로 아래 원소의 최댓값 정보와 그 제거된 원소 위에 쌓이는 원소들의 값을 비교해서 원래 스택에 넣는다.
*/
class MaxStack {
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> st;  // 두 번째 파라미터는 가장 현재까지의 최댓값 정보를 유지한다.
    stack<pair<int, int>> temp_st;
    MaxStack(){
    }
    void push(int x) {
        if(st.empty())
            st.push(make_pair(x,x));
        else{
            if(st.top().second < x)
                st.push(make_pair(x, x));
            else
                st.push(make_pair(x, st.top().second));
        }
    }
    
    int pop() {
        int a = st.top().first;
        st.pop();
        cout <<st.size();
        return a;
    }
    
    int top() {
        return st.top().first;
    }
    
    int peekMax() {
        cout << st.top().first << " " << st.top().second << endl;
        return st.top().second;
    }
    
    int popMax() {  
        int maxval = st.top().second;
        while(!st.empty()){
            if(st.top().first != maxval){
                temp_st.push(make_pair(st.top().first,st.top().second));
                st.pop();       
            }
            else{
                st.pop();
                break;  // 동일한 최댓값 모두 pop하는 것을 방지
            }
        }
        while(!temp_st.empty()){
                if(st.empty()){ // 원래 스택이 비어있을 땐, 새로 쌓이는 것과 같으므로 동일하게 초기화
                    st.push(make_pair(temp_st.top().first, temp_st.top().first));

                }
                else{           // 기존 스택과 비교하며 쌓아간다.
                    if(temp_st.top().first > st.top().second)
                        st.push(make_pair(temp_st.top().first, temp_st.top().first));
                    else
                        st.push(make_pair(temp_st.top().first, st.top().second));
            }           
            temp_st.pop();
        }
        return maxval;
    }
};
