

/**
 * @brief Given a 2D integer array statements of size n x n that represents
 * the statements made by n people about each other.
 * Return the maximum number of people who can be good based on the statements made
 * by the n people.
 */


class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        
        int n = statements.size();
        vector<bool> people; // true: good. false: bad
        int ans = 0; // maximum number of people who can be good
        int nGood = 0;
        dfs(statements, 0, people, nGood, ans);
        return ans;
        
    }
    
    
    void dfs(vector<vector<int>>& statements, int idx,
             vector<bool> &people, int &nGood, int &ans)
    {
        if (idx == statements.size()) {
            if (valid(statements, people)) {
                ans = max(nGood, ans);
            }
            return;
        }
        // good
        people.push_back(true); nGood ++;
        dfs(statements, idx + 1, people, nGood, ans);
        people.pop_back(); nGood--;
        // bad
        people.push_back(false);
        dfs(statements, idx + 1, people, nGood, ans);
        people.pop_back();
    }
    
    bool valid(vector<vector<int>> &statements, vector<bool> &people) {
        for (int i = 0; i < people.size(); ++i) {
            if (people[i] == true) {
                for (int j = 0; j < people.size(); ++j) {
                    if (statements[i][j] == 0 && people[j] == true) return false;
                    if (statements[i][j] == 1 && people[j] == false) return false;
                }
            }
        }
        return true;
    }
};