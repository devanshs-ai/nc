class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mpp.find(key)==mpp.end()){
            return "";
        }

        vector<pair<int, string>>& nums = mpp[key];

        int high = nums.size()-1;
        int low = 0;
        string ans = "";
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid].first<=timestamp){
                ans = nums[mid].second;
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};
