/* ----------<문제 정의>---------
문제: 배열에서 두 개의 원소의 합이 target과 일치하는 인덱스 찾기
입력: 2<=배열<=1만, -10^9<=target<=10^9 -> bruteforce로 구현하면 최악의 경우 시간초과
출력: 벡터(정답은 하나만 존재)(순서 상관없음)
*/
/* ----------<알고리즘>----------
요약: 정렬 후 2for bruteforce
우선 정렬 -> 정렬하면 인덱스 정보 잃는데 어떻게 하지? -> 그 숫자를 가진 인덱스 재탐색? -> 하나씩 존재하므로
target을 넘지 않는 숫자까지 2for bruteforce
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> temp;
        int bigidx;
        int src1, src2;
        temp = nums;
        sort(temp.begin(), temp.end());
        for(int i = temp.size()-1; i >= 0; i--){   // target과 가장 가까운 큰 수의 인덱스 찾기
            if(temp[i] < target){
                bigidx = i;
                break;
            }
        }
        for(int i = 0; i < bigidx;i++){
            for(int j = i+1; j <= bigidx; j++){
                if(temp[i] + temp[j] == target){
                    src1 = temp[i];
                    src2 = temp[j];
                    //cout << nums[i] << " : " << nums[j];
                }
            }
        }
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == src1 || nums[i] == src2)
                res.push_back(i);
            if(res.size() == 2)
                break;
        }
        return res;
    }
};