/* 모델링
문제: 전호번호부에서 한 번호가 다른 번호의 접두어인지 여부 판별
입력: 1<=phone_book<=1,000,000 / 1<=전화번호 길이<=20 / 전화번호 중복x
출력: 접두어 여부
알고리즘(2for - bruteforce):O(n^2) - 시간 초과!
--------------------<Improve time complexity>--------------------
알고리즘(문자열 배열의 정렬은 사전식 나열임을 이용):O(n)
--------------------<Approach in a different way>--------------------
알고리즘(해쉬 이용):O(n)
*/
/* 채점 결과
정확성: 83.3
효율성: 16.7
합계: 100.0 / 100.0
*/
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int sz = phone_book.size();
    int subsz;
    string str="";
    unordered_map<string, int> hash_map;
    for(int i = 0; i < sz; i++){
        subsz = phone_book[i].length();
        str="";
        for(int j = 0; j < subsz; j++){
            str+=phone_book[i][j];
            hash_map[str]++;
        }
    }
    for(int i = 0; i < sz; i++){
        if(hash_map[phone_book[i]] > 1 )
            return false;
    }
    return answer;
}