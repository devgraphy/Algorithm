// 소수 찾기-> 소인수 분해
// 입력 1000
// 14! 넘어가면 int 타입 오버플로우 발생
// unsigned long long 1800해 까지 수용. 20! 넘어가면 ull 타입 오버 플로우 발생
#include <iostream>
#include <vector>
using namespace std;
vector<int> m;
int main(){
    int n;
    unsigned long long fact = 1;
    int chk = 0;
    cin >> n;
    for(int i = 2; i <= n; i++){
        fact*=i;
    }
    for(int i = 2; i <= n; i++){
        //소수 찾기
        chk = 0;
        for(int j = 2; j * j<= i; j++){
            if(i % j == 0){
                chk = 1;
                break;
            }
        }
        if(chk == 0){   //소수이면
            //cout << i << endl;
            m.push_back(0);
            cout << fact << endl;
            while(fact > 0){    // 더 이상 안 나눠질 때 까지
                if(fact % i == 0){
                    fact/=i;
                    m[m.size()-1]++;
                }
                else break;    // 해당 소수로 더 이상 안 나눠지면     
            }
        }
    }
    cout << n << "! = ";
    for(int i = 0; i < m.size(); i++){
        cout << m[i] << " ";
    }
}