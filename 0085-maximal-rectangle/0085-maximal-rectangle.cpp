class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxArea = 0;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 :  st.top();

                maxArea = max(maxArea, heights[ele]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 :  st.top();

            maxArea = max(maxArea, heights[ele]*(nse-pse-1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;
        vector<int>height(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};