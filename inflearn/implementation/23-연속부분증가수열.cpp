// no use data structure
// 18-층간소음과 비슷한 이슈(boundary value)가 발생할 수 있음 -> 매번 최댓값 갱신하여 해결: o(n)
#include <iostream>
using namespace std;
int main(){
    int n, a, b;
    int max = 1;
    int temp = 1;   //높아지는 지점 전의 수도 길이에 포함
    cin >> n;
    cin >> a;
    for(int i = 0; i < n-1; i++){
        cin >> b;
        if(a <= b){
            //cout << b << " ";
            temp++;
            if(max < temp)
                max = temp;
        }
        else temp = 1;
        a = b;
    }
    cout << max;
}