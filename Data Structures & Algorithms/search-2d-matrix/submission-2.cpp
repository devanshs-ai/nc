class Solution {
public:
    bool binarySearch(vector<int>&ans, int target){
        int low = 0;
        int high = ans.size() - 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(ans[mid]==target){
                return true;
            }
            else if(ans[mid]>target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0]<=target && matrix[i][matrix[0].size()-1]>=target){
                if(binarySearch(matrix[i], target)){
                    return true;
                };
            }
        }
        return false;
    }
};
