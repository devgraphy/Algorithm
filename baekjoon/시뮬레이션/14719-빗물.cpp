/* ----------<문제 정의>----------
문제: 블록 사이 빗물의 총량
입력: H, W, W개의 열마다 블록 높이
출력: 빗물 총량
*/
/* ----------<참고 접근법>----------
양 끝단을 제외한 각 위치를 기준으로 왼쪽 중 가장 큰 값과 오른 쪽 중 가장 큰 값을 구한다.
두 값 중 작은 값을 선택하여 그 값에서 자기 높이를 빼면 빗물의 양이 된다. 
*/
/* ----------<알고리즘>----------
빗물 정보 입력
양 끝단을 제외하고 양 옆으로 가장 큰 값을 찾는다.
두 값을 비교하여 작은 값을 선택한다.
해당 위치의 높이값을 빼어 빗물 총량 변수에 더한다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int h, w, maxleft = -1, maxright = -1;
    int result = 0;
    int arr[501];
    cin >> h >> w;
    for(int i = 0; i < w; i++)
        cin >> arr[i];
    for(int i = 1; i < w-1; i++){
        maxleft = -1;
        maxright = -1;
        for(int j = i-1; j >= 0; j--){
            if(maxleft < arr[j])
                maxleft = arr[j];
        }
        for(int j = i+1; j < w; j++){
            if(maxright < arr[j])
                maxright = arr[j];
        }
        if(min(maxleft, maxright)-arr[i] < 0) continue; // 자기보다 높은 것이 없는 경우 양 옆이 -1 되는 예외를 처리해야 한다.
        result = result + min(maxleft, maxright)-arr[i];
    }
    cout << result;
}
