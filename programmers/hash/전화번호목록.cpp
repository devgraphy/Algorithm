/* 모델링
문제: 전호번호부에서 한 번호가 다른 번호의 접두어인지 여부 판별
입력: 1<=phone_book<=1,000,000 / 1<=전화번호 길이<=20 / 전화번호 중복x
출력: 접두어 여부
알고리즘(2for - bruteforce):O(n^2) - 시간 초과!
*/
/* 채점 결과
정확성: 83.3
효율성: 8.3
합계: 91.7 / 100.0
*/
#include <string>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int sz = phone_book.size();
    int subsz;
    for(int i = 0; i < sz-1; i++){
        for(int j = i+1; j < sz; j++){
            if(phone_book[i].length() > phone_book[j].length()){
                subsz = phone_book[j].length();
                if(phone_book[i].substr(0,subsz) == phone_book[j])
                    answer = false;
            }
            else if(phone_book[i].length() < phone_book[j].length()){
                subsz = phone_book[i].length();
                if(phone_book[j].substr(0,subsz) == phone_book[i])
                    answer = false;   
            }
            else{
                if(phone_book[j] == phone_book[i])
                    answer = false;
            }
            if(answer==false)
                break;
        }
        if(answer==false)
                break;
    }
    return answer;
}