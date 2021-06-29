/* ----------<문제 정의>---------
문제: 배열에서 두 개의 원소의 합이 target과 일치하는 인덱스 찾기
입력: 2<=배열<=1만, -10^9<=target<=10^9
출력: 벡터(정답은 하나만 존재)(순서 상관없음)
*/
/* ----------<알고리즘>----------
2for bruteforce
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size();j++){
                if(nums[i] + nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};