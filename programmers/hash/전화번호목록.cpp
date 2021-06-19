/* 모델링
문제: 전호번호부에서 한 번호가 다른 번호의 접두어인지 여부 판별
입력: 1<=phone_book<=1,000,000 / 1<=전화번호 길이<=20 / 전화번호 중복x
출력: 접두어 여부
알고리즘(2for - bruteforce):O(n^2) - 시간 초과!
--------------------<Improve time complexity>--------------------
알고리즘(문자열 배열의 정렬은 사전식 나열임을 이용):O(n)
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
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int sz = phone_book.size();
    int subsz;
    sort(phone_book.begin(),phone_book.end());
    for(int i = 0; i < sz-1; i++){
        subsz = phone_book[i].length();
        if(phone_book[i] == phone_book[i+1].substr(0,subsz))
            return false;
    }
    return answer;
}