class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nse(heights.size(), 0);

        stack<int> st;

        for(int i = heights.size()-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }

            nse[i] = st.empty() ? heights.size(): st.top();

            st.push(i);
        }

        stack<int> stt;
        st = stt;

        vector<int> pse(heights.size(), 0);
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int len = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * len);
        }

        return maxArea;
    }
};
