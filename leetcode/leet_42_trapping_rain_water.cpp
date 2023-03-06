

/**
 * @brief 
 * 
 * 
 */


class Mine {
public:
    int trap(vector<int>& height) {
        
        vector<int> leftMax(height.size(), 0); // no need to initialize
        int h = 0;
        for (int i = 0; i < height.size(); ++i) {
            leftMax[i] = h;
            h = max(h, height[i]);
        }
        
        vector<int> rightMax(height.size(), 0);
        h = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            rightMax[i] = h;
            h = max(h, height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            int m = min(leftMax[i], rightMax[i]);
            if (m > height[i]) ans += (m - height[i]);
        }
        return ans;        
    }
};