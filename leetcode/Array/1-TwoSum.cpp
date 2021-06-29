/* ----------<문제 정의>---------
문제: 배열에서 두 개의 원소의 합이 target과 일치하는 인덱스 찾기
입력: 2<=배열<=1만, -10^9<=target<=10^9
출력: 벡터(정답은 하나만 존재)(순서 상관없음)
*/
/* ----------<알고리즘>----------
2for bruteforce

Runtime: 436 ms, faster than 10.46% of C++ online submissions for Two Sum.
Memory Usage: 10.1 MB, less than 59.89% of C++ online submissions for Two Sum.
*/
/* ----------<시간개선 알고리즘>----------
2 pass hash map

Runtime: 24 ms, faster than 35.12% of C++ online submissions for Two Sum.
Memory Usage: 12.1 MB, less than 7.52% of C++ online submissions for Two Sum.
*/
/* ----------<궁금한 것>----------
map 원소 출력-> iterator 사용
*/
/* ----------<새롭게 안 것>----------
map은 동일한 key에 대해 나중에 들어온 값만 유지한다.
*/
/* ----------<예외 케이스>----------
문제에서는 동일한 값은 허용하지만 유일한 답이 존재한다.
입력 배열:[3,5], target = 6 일 때, 원소3을 map에서 조회할 때 동일한 3을 사용하여 의도치 않게 조건에 부합할 수 있는 경우가 발생한다.
그래서 3에 해당하는 6의 보수를 찾을 땐, 기존3의 인덱스와 다른지를 확인해야 한다.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size();i++){
            map[nums[i]] = i;
        }
        /*
        for(unordered_map<int,int>::iterator iter = map.begin(); iter != map.end(); iter++)
            cout << iter->first << " " << iter->second << endl;
        */
        for(int i = 0; i < nums.size();i++){
            int complement = target-nums[i];
            if((map.end() != map.find(complement)) && map[complement]!= i){
                res.push_back(map[complement]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }  
};