/* ----------<문제 정의>----------
문제: 최댓값, 최솟값 찾기
입력: n(최대 100개), n개의 문자열
출력: 최솟값의 이름, 최댓값의 이름
*/
/* ----------<접근법>----------
한 라인에 이름 일 월 연도가 공백을 기준으로 들어온다.
한 문자열에서 이름 일 월 연도의 위치가 다르다.
벡터의 배열 또는 배열의 배열로 정의한다.
연도부터 비교해야하므로 비트 연산자의 동작 방식을 알고 있어야 한다.
연도가 같은 경우 다른 경우를 구분해야 한다.
    또 월이 같은 경우 다른 경우를 구분해야 한다.
for n
    for 4
        최솟값 비교(일, 월, 연도 모두 작다면)
        최댓값 비교(일, 월, 연도 모두 크다면)
*/
/* ----------<모르는 것>----------
배열의 벡터 선언 방법
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    int arr[100][4];
    string maxname;
    string minname;
    int maxidx=0;
    int minidx=0;
    int maxbirth[3]={-1,-1,1900};
    int minbirth[3]={40,13,2020};
    cin >> n;
    int tempdd;
    int tempmm;
    int tempyy;
    string tempname;
    for(int i = 0; i < n; i++){
        // 한 라인의 정보 입력 받기
        cin >> tempname >> tempdd >> tempmm >> tempyy;
        // 나이가 많은 사람 갱신
        //cout << tempname << tempdd << tempmm << tempyy << endl;
        if(tempyy == minbirth[2]){
            if(tempmm == minbirth[1]){   // 월까지 같은 경우
                if(tempdd < minbirth[0]){
                    minbirth[0] = tempdd;
                    minbirth[1] = tempmm;
                    minbirth[2] = tempyy;
                    minname = tempname;
                }
            }
            else if(tempmm < minbirth[1]){
                minbirth[0] = tempdd;
                minbirth[1] = tempmm;
                minbirth[2] = tempyy;
                minname = tempname;
            }
            
        }
        else if(tempyy < minbirth[2]){
            minbirth[0] = tempdd;
            minbirth[1] = tempmm;
            minbirth[2] = tempyy;
            minname = tempname;
        }
        // 나이가 적은 사람 갱신
        if(tempyy == maxbirth[2]){
            if(tempmm == maxbirth[1]){   // 월까지 같은 경우
                if(tempdd > maxbirth[0]){
                    maxbirth[0] = tempdd;
                    maxbirth[1] = tempmm;
                    maxbirth[2] = tempyy;
                    maxname = tempname;
                }
            }
            else if(tempmm > maxbirth[1]){
                maxbirth[0] = tempdd;
                maxbirth[1] = tempmm;
                maxbirth[2] = tempyy;
                maxname = tempname;
            }
            
        }
        else if(tempyy > minbirth[2]){
            maxbirth[0] = tempdd;
            maxbirth[1] = tempmm;
            maxbirth[2] = tempyy;
            maxname = tempname;
        }
            
    }
    cout << maxname << '\n' << minname;
}