class Solution {
public:
    // 2 1 2


    int largestRectangleArea(vector<int>& heights) {
       stack<int> st;
       int res = 0, n = heights.size();

       for (int i = 0;i <= n;i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int top = st.top();
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                int area = heights[top] * width;
                res = max(area, res);
            }
            st.push(i);
       }
       return res;
    }
};
