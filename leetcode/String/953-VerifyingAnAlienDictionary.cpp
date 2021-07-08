/* ----------<문제 정의>----------
문제: 사전식 나열이 아닌 order에서 정의한 알파벳 순서를 기준으로 words의 문자열 순서가 올바르게 정렬되었는지 판단
입력: 1<=words[i].length<=20(문자열 길이 20), 1<=words.length <=100(문자열 최대 100개)
출력: 정렬 여부 (true/false)
*/
/* ----------<알고리즘>----------
- order의 문자 순서로 문자열 정렬이 올바른지 판단해야 한다.
- order 문자들의 우선순위를 설정해야 한다. -> hash에 각 문자에 대해 우선순위를 저장해준다.

1. order를 순회하면서 각 문자를 키로 hash에 저장하고 값은 인덱스로 저장한다.
2. while (여러 문자열 중 가장 짧은 길이) - 모든 문자열 같은 인덱스에 대해 동시에 탐색
        for words.size()-2
            words의 앞에 문자가 작거나 같으면 계속 진행
            그렇지 않으면
                return false;
    (모든 문자에 대해서 정렬 순서를 위반하지 않았으므로)
    return true;
*/
/* -----<궁금한 것>-----
1. 어떻게 여러 문자를 동시에 비교하지?
->순회하면서 인접한 것끼리 비교!
*/
/* -----<예외 케이스>-----
1. 가장 작은 문자열 길이로 하면 그것보다 길이가 긴 문자열들 간의 나머지 문자비교를 하지 못하게 된다. -> 최댓값으로 바꿔준다.
비교하다가 길이가 더 짧으면 우선순위가 앞서는 것이다.
2. ["word","world","row"]
"worldabcefghijkmnpqstuvxyz"
Output: true, Expected: false
*/
class Solution {
public:
    int answer = 2; // 0: 실패 1: 성공 2: 결정되지 않음
    unordered_map<char, int> map;
    int minval = INT_MAX;
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.length(); i++)
            map[order[i]] = i;  // order식 순서 정의
        // words 문자열 중 최소 길이 값 찾기
        for(int i = 0; i < words.size(); i++){
            if(minval > words[i].length())
                minval = words[i].length();
        }
        // 가장 짧은 문자열 길이에 한해 같은 인덱스 동시에 비교
        for(int i = 0 ; i < minval; i++){
            for(int j = 0; j < words.size()-1; j++){
                // 인접한 문자열 끼리 같은 인덱스 동시에 비교
                if(words[j][i]=='\0' || words[j+1][i]=='\0'){
                    if(words[j][i]=='\0')
                        answer = 1;
                    else if(words[j+1][i]=='\0'){
                        answer = 0;
                        break;
                    }
                }
                if(map[words[j][i]] > map[words[j+1][i]]){
                    cout << words[j][i] << " " << words[j+1][i];
                    answer = 0;
                    break;
                }
                else if(map[words[j][i]] < map[words[j+1][i]]){
                    cout << words[j][i] << " " << words[j+1][i];
                    answer = 1;
                    break;
                }
                else        // 만약 계속 같다면? => 정상이라 판단한다. 그래서 answer의 초기값을 true로 한다.
                    continue;
                    
            }
            if(answer == 0 || answer == 1)   // true/false 결정되면 나간다. 결정안 된 경우에는 계속 진행해야 한다.
                break;
        }
        if(answer == 0)
            return false;
        else
            return true;
    }
};