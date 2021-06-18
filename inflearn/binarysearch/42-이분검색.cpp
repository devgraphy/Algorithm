/* 모델링
1. 문제: 원소 N의 정렬되지 않은 배열이 주어지면, 정렬했을 때 M의 순서 출력
2. 알고리즘(이분 검색): *log(n)*
정렬
2개씩 나눠서 탐색

*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];
int main(){
    int n, m;
    int mid;
    cin >> n >> m;
    int pre = 0;
    int post = n-1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    while(pre <= post){         
        mid = (pre + post)/2;
        if(m == a[mid]){
            cout << mid + 1;
            return 0;
        }
        else if(m > a[mid])    pre = mid+1;
        else    post = mid; // mid-1 도 가능
    }

}