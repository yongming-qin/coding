#inclue "../common.h"

/**
 * @brief 
 * 
 * 
 * 
 */





class Mine {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        map<int,int> points;
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
        }
        
        vector<int> elements;
        for (auto it = points.begin(); it != points.end(); ++it) {
            elements.push_back(it->first);
        }
        sort(elements.begin(), elements.end());
        
        // Base cases
        int twoBack = 0;
        int oneBack = points[elements[0]];
        int here;
        
        for (int i = 1; i < elements.size(); ++i) {
            int currentElement = elements[i];
            if (currentElement == elements[i-1] + 1) {
                // The 2 elements are adjacent, cannot take both - apply normal recurrence
                here = max(oneBack, twoBack + points[currentElement]);
            } else {
                here += points[currentElement];
            }
            twoBack = oneBack; oneBack = here;
        }
        
        return here;
        
    }
};