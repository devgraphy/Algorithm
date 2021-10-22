/* ----------<���� ����>----------
����: ������ ���ڷ� �ִ��� ���� ���� �� �ִ� �ܾ��� ���� ã��
�Է�: �ܾ��� ���� N(�ִ� 50), ����ġ�� ���� K(�ִ� 26, �ּ� 0), N���� ���ڿ�
���: �ִ��� ���� ���� �� �ִ� �ܾ��� ��
*/
/* ----------<���� ���ٹ�>----------
a, n, t, i, c�� �ʼ������� ����� �Ѵ�.
���� k�� 5���� ������ �л����� ���� �� �ִ� �ܾ�� 0���̰�,
5���� ũ�ٸ�, 26���� ���ĺ� ��, a, n, t, i, c�� ������ 21���� ���ĺ��� k-5�� ��ŭ ��� ����� ***(1)
���� ���� �ܾ ���� �� �ִ� ��츦 ����ϸ� �ȴ�.***(2)
- �ܾ�(word) ���� �� ���ĺ��� chk�� �����ϴ��� Ȯ���Ͽ� ��� �����ϸ� ��� ���ڷ� ���� �� �ִ� �ܾ��̴�.
(?�̶�, ��� ���ĺ��� ���� Ȯ���ϹǷ� �� ���� �������� ���� ���ĺ� ���ڵ� Ȯ���Ѵ�.)
����, Ǯ���� �ٽ��� 26���� ���ĺ� �� k-5�� ��ŭ ��� ���ڵ��� �������� ����� ���� ã��,
�ش� �������� �־��� �ܾ���� ���� �� �ִ��� �Ǵ��ϰ�, ī�����ϴ� ���̴�.
(?�־��� ���ڿ��� ���ڰ� chk�� ǥ�õǾ������� Ȯ���Ѵ�. chk�� ǥ�õ� ���ڰ� ���ڿ��� ���ԵǾ��ִ� ���� Ȯ���ϸ� ������ �� ���ڿ��� ��� ���ԵǾ��ִ����� Ȯ���ϴ� ���̱� ������ �ùٸ� ������ �ƴϴ�.***(3))
*/
/* ----------<�𸣴� ��>----------
- ���ڿ� �޼��� API
.substr(idx, idx ���غ��� ����)
�ι� ° ���ڴ� �ε����� �ƴ϶� ���̸� �ǹ��Ѵ�.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool chk[26];    // ���ĺ� ���� ���ո���� ���� üũ�� �迭
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
    // 26�� ���ڿ� ����
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
    
    // ���ڿ����� ���λ� ���̻� �߶� word ���Ϳ� �߰�
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

    // ���� ���� ����
    if(k < 5){
        cout << 0;
        return 0;
    }
    // a,n,t,i,c ���� üũ
    chk['a'-'a'] = true;
    chk['n'-'a'] = true;
    chk['t'-'a'] = true;
    chk['i'-'a'] = true;
    chk['c'-'a'] = true;
    // 5�� ���� �� k-5�� ���� �߰��Ͽ� ���� �����
    combination(0, 0, k-5);
    cout << result;
}