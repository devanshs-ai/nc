class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> mpp;
        vector<int> res;

        for(int i = 0; i < numbers.size();i++){
            int num = numbers[i];
            int rem = target-num;

            if(mpp.find(rem)!=mpp.end()){
                res.push_back(mpp[rem]+1);
                res.push_back(i+1);
            }
            mpp[num] = i;
        }
        return res;
    }
};
