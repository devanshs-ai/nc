class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        for(int i: arr){
            pq.push({abs(x-i), i});
        } 

        while(k>0 && !pq.empty()){
            int num = pq.top().second;
            pq.pop();
            res.push_back(num);
            k--;
        }

        sort(res.begin(), res.end());
        return res;
        
    }
};