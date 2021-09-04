/* ----------<문제 정의>----------
문제: 조합 - 9개 입력 중 7개의 합이 100이 되는 조합 찾기
입력: 9개의 키(최대 100, 모두 다르다)
출력: 조합 하나의 경우의 수 오름차순 출력(여러 가지인 경우에는 아무거나 출력)
*/
/* ----------<접근법 도출>----------
방법1. next permutation 이용
✅방법2. dfs 방문(이분법 접근-원소를 방문, 비방문으로 조합을 구현)
*/
/* ----------<알고리즘>----------
dfs(1차원 배열 a, 선택 개수 cnt, 현재 인덱스 idx)
    if cnt == 8
        체크된 원소의 총합이 100인지 판단
        100 이면 모두 출력
        출력했음을 확인하는 변수 체크
        return;
    for (i = idx; i < 난쟁이 수; i++) 
        현재 체크
        dfs
        현재 체크아웃
        dfs


메모리: 2024KB
시간: 0ms
풀이시간: 37분
*/
/* ----------<개선 고려 사항>----------
1. 공간 측면-정렬을 위해 체크된 원소만으로 구성된 별도의 자료구조를 새로 생성해야하는가?
2. 조합 구현을 next_permutation으로 바꿔보기
*/
#define NUMDWARF 9
#include <iostream>
#include <vector> // 정렬을 위해 사용
#include <algorithm>
using namespace std;
int chk[NUMDWARF+1];
bool prt = false;
vector<int> c;
void dfs(int a[], int cnt, int idx){    // ☝ 1차원 배열 주소 파라미터 명시 방법 숙지
    if(cnt == 7){   // cnt가 초과되는 경우에 대해서는 for문에서 처리한다.
        int sum = 0;
        for(int i = 0; i < NUMDWARF; i++){
            if(chk[i] == 1){
                sum+=a[i];
            }
        }
        if(sum == 100){
            prt = true;
            for(int i = 0; i < NUMDWARF; i++){
                if(chk[i] == 1){
                    c.push_back(a[i]);  // 정렬을 위해 체크된 원소만으로 구성된 자료구조를 새로 만든다.
                }
            }
            sort(c.begin(), c.end());
            for(auto elem: c)
                cout << elem << '\n';
        }
        return;
    }
    for(int i = idx; i < NUMDWARF; i++){
        chk[i] = 1;
        dfs(a, cnt+1, i+1);
        if(prt == true)  return;
        chk[i] = 0;
        dfs(a, cnt, i+1);
        if(prt == true)  return;
    }
}
int main(){
    int a[10];
    // 9명 난쟁이 키 입력
    for(int i = 0; i < NUMDWARF; i++){
        cin >> a[i];
    }
    dfs(a, 0, 0);
}