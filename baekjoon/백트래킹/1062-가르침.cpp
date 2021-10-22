/* ----------<문제 정의>----------
문제: 한정단 문자로 최대한 많이 읽을 수 있는 단어의 개수 찾기
입력: 단어의 개수 N(최대 50), 가르치는 문자 K(최대 26, 최소 0), N개의 문자열
출력: 최대한 많이 읽을 수 있는 단어의 수
*/
/* ----------<참고 접근법>----------
a, n, t, i, c는 필수적으로 배워야 한다.
따라서 k가 5보다 작으면 학생들이 읽을 수 있는 단어는 0개이고,
5보다 크다면, 26개의 알파벳 중, a, n, t, i, c를 제외한 21개의 알파벳을 k-5개 만큼 골라 배워서 ***(1)
가장 많은 단어를 읽을 수 있는 경우를 출력하면 된다.***(2)
- 단어(word) 마다 각 알파벳이 chk에 존재하는지 확인하여 모두 존재하면 배운 문자로 읽을 수 있는 단어이다.
(?이때, 모든 알파벳에 대해 확인하므로 한 번도 등장하지 않은 알파벳 문자도 확인한다.)
따라서, 풀이의 핵심은 26개의 알파벳 중 k-5개 만큼 배울 글자들을 조합으로 경우의 수를 찾고,
해당 조합으로 주어진 단어들을 읽을 수 있는지 판단하고, 카운팅하는 것이다.
(?주어진 문자열의 문자가 chk에 표시되었는지를 확인한다. chk에 표시된 문자가 문자열에 포함되어있는 지를 확인하면 조합이 그 문자열에 모두 포함되어있는지를 확인하는 논리이기 때문에 올바른 접근이 아니다.***(3))
*/
/* ----------<모르는 것>----------
- 문자열 메서드 API
.substr(idx, idx 기준부터 길이)
두번 째 인자는 인덱스가 아니라 길이를 의미한다.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool chk[26];    // 알파벳 문자 조합만들기 위한 체크용 배열
vector<string> word;
int result;
int n, k;
int canRead(){
    int cnt = 0;
    for(int i = 0; i < word.size(); i++){       // ***(2)
        int j = 0;
        for(; j < word[i].length(); j++){
            if(!chk[word[i][j]-'a']) break;     // ***(3)
        }
        if(j == word[i].length())
            cnt++;
    }
    return cnt;
}
void combination(int idx, int cnt, int extra){  // ***(1)
    // basecase
    if(cnt == extra){
        result = max(result, canRead());
        return;
    }
    // 26개 문자열 조합
    for(int i = idx; i < 26; i++){
        if(chk[i]) continue;
        chk[i] = true;
        combination(i+1, cnt+1,extra);
        chk[i] = false;
    }
}
int main(){
    string strtmp;
    int strtmplen;
    cin >> n >> k;
    
    // 문자열마다 접두사 접미사 잘라서 word 벡터에 추가
    string tmp;
    for(int i = 0; i < n; i++){
        cin >> strtmp;
        strtmplen = strtmp.length()-4;
        //strtmp = strtmp.substr(4, strtmplen-4);
        tmp = "";
        for(int j = 4; j < 4 + strtmplen-4; j++){
            if(!chk[strtmp[j]-'a'])
                tmp+=strtmp[j];
        }
        word.push_back(tmp);
    }

    // 문제 제약 조건
    if(k < 5){
        cout << 0;
        return 0;
    }
    // a,n,t,i,c 문자 체크
    chk['a'-'a'] = true;
    chk['n'-'a'] = true;
    chk['t'-'a'] = true;
    chk['i'-'a'] = true;
    chk['c'-'a'] = true;
    // 5개 문자 외 k-5개 문자 추가하여 조합 만들기
    combination(0, 0, k-5);
    cout << result;
}