class Solution {
public:
    int helperfunc(vector<int>& nums, int k){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += ceil((double)nums[i]/k);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i = 0; i < piles.size(); i++){
            low = min(low, piles[i]);
            high = max(high, piles[i]);
        }

        int ans = 0;

        while(low<=high){
            int mid = (low+high)/2;
            int hours = helperfunc(piles, mid);

            if(hours<=h){
                ans = hours;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};
