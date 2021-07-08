/* ----------<문제 정의>----------
문제: 스택 자료구조 이용해서 큐 기능 구현하기
제한사항: 스택 2개 이용
*/
/* ----------<알고리즘>----------
5 1
4 2
3 3
2 4
1 5
  ↑ 
큐에서의 순서

[push]: 
"pop, peek 연산이 호출될 때 까지 하나의 배열에 추가한다."
-> queue와 반대 상태
-> "pop할 때 순서를 뒤집기 위해 다른 스택에 이동한다."
-> "pop 호출하면 또 뒤집어?" -> NO -> pop을 호출할 때의 상태는 온전히 queue의 상태를 만든다.
-> push 할 때, target(queue와 같은 상태)의 모든 원소를 temp에 이동한다. 새로운 원소를 push 한 후 다시 target에 옮긴다.
=> 결국 push 할때만 temp 스택을 빌리고 다른 하나로 queue와 같은 상태를 유지한다.

[pop]: target의 원소를 pop 한다.
[peek]: target.top() 호출
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> temp;
    stack<int> target;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!target.empty()){
            temp.push(target.top());
            target.pop();
        }
        temp.push(x);
        while(!temp.empty()){
            target.push(temp.top());
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int a = target.top();
        target.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        return target.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return target.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */