// 선택정렬(bruteforce): 매번 가장 큰 값을 차례대로 갖다 놓기-최악, 평균, 최선 모두 O(n^2)
 
#include <iostream>
using namespace std;
int a[101];
int main(){
    int n;
    int maxpos = 0;
    int temp;
    int rank = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        maxpos = i;
        for(int j = i+1; j < n;j++){
            if(a[maxpos] < a[j])
                maxpos = j;
        }
        temp = a[maxpos];
        a[maxpos] = a[i];
        a[i] = temp;
    }
    for(int i = 1; i < n; i++){
        if(a[i-1] > a[i])
            rank++;
        if(rank == 3){
            cout << a[i];
            break;      // 반복 출력 방지
        }
    }
}