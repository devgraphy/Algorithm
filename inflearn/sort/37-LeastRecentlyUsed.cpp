// cache hit(포인트 찾은 후 버블 후 맨 앞에 삽입), cache miss(버블 후 맨 앞에 삽입)
#include <iostream>
using namespace std;
int a[12];
int main(){
    int s, n, job, hit_p;
    int hit = -1;
    cin >> s >> n;
    for(int i = 0; i < n; i++){
        cin >> job;
        hit_p = s-1;            // 정렬 구간 포인터. 기본적으로 맨 끝에 세팅
        for(int j = 0; j < s; j++){
            if(a[j] == job){    // hit 찾기
                hit_p = j;
            }             
        }
        for(int k = hit_p-1; k >= 0; k--){  // hit면 hit 찾은 점까지. miss면 끝까지
            a[k+1] = a[k];
        }
        a[0] = job;
        // for(int i = 0; i < s; i++)
        //     cout << a[i] << " ";
        // cout << endl;
    }
    for(int i = 0; i < s; i++)
        cout << a[i] << " ";
}