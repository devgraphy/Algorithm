/* ----------<문제 정의>----------
문제: 중복을 허용하지 않는 조합 문제
입력: 좌표 개수 n(최대 10만), n 개의 x,y 좌표
출력: x축 또는 y축에 평행한 직선의 개수
*/
/* ----------<시간 초과 접근법>----------
브루트포스로 중복 허용하지 않는 조합을 구현하면 O(N^2)이 되어 시간 제한 초과
*/
/* ----------<참고 접근법>----------
x축과 y축에 평행한 선이 만들어지는 조건을 이용한다.
x좌표와 x좌표의 개수, y좌표와 y좌표의 개수를 각각 저장하는 맵을 구현하여
동일한 좌표가 2개 이상인 점의 개수를 세준다.
*/
#include <iostream>
#include <map>
using namespace std;
int main(){
    int n, x, y, cnt = 0;
    map<int, int> mx;
    map<int, int> my;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        mx[x]++;
        my[y]++;
    }
    map<int, int>::iterator it;
    // 동일한 x좌표 개수 세기
    for(it = mx.begin(); it != mx.end(); it++){
        if(it->second >= 2) cnt++;   //nC2가 아니라?
    }
    // 동일한 y좌표 개수 세기
    for(it = my.begin(); it != my.end(); it++){
        if(it->second >= 2) cnt++;    //nC2가 아니라?
    }
    cout << cnt;
}