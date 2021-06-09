// map
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    string str;
    map<char, int> m;
    cin >> str;
    int max = -2147000000;

    for(int i = 0; i < str.length(); i++){
        m[str[i]]++;
    }
    auto max_it = m.begin();
    for(auto it = m.begin(); it != m.end(); ++it){
        if(max <= it->second){
            max = it->second;
            if(max == it->second){
                if(max_it->first < it->first)
                    max_it = it;
            }
        }
    }    
    cout << max_it->first;
}