#include "../common.h"

/**
 * @brief 
 * 
 * 
 */





class MineImproved {
public:
    vector<int> parent;
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        // Union Find
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto &vec : allowedSwaps) {
            int p1 = find(vec[0]);
            int p2 = find(vec[1]);
            if (p1 != p2) parent[p2] = p1;
        }
        
        // Idea: if the position of source can move to the position of target
        // Components of Union Find
        map<int,set<int>> components; // parent id : children ids
        for (int i = 0; i < n; ++i) {
            components[find(i)].insert(i);
        }
        
        int ans = n;
        for (const auto &[k,v] : components) {
            multiset<int> targetSet;
            for (int idx : v) {
                targetSet.insert(target[idx]);            
            }
            for (int idx : v) {
                auto it = targetSet.find(source[idx]);
                if (it != targetSet.end()) {
                    targetSet.erase(it);
                    --ans;
                }
            }
        }

        return ans;
    }
    
    // find the parent and remap all nodes to the parent
    int find(int i) {
        while (parent[i] != i) {
            i = parent[i];
        }      
        return i;
    }
};





class Mine {
public:
    vector<int> parent;
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        // Union Find
        parent = vector<int>(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (auto &vec : allowedSwaps) {
            connect(vec[0], vec[1]);
        }
        
        // Idea: if the position of source can move to the position of target
        map<int,int> mTarget; // val : index
        for (int i = 0; i < n; ++i) {
            mTarget[target[i]] = i;
        }
        // Components of Union Find
        map<int,set<int>> components; // parent id : children ids
        for (int i = 0; i < n; ++i) {
            components[find(i)].insert(i);
        }
        
        int ans = n;
        for (auto [k,v] : components) {
            map<int,int> targetComponent; // target num : amount
            for (int idx : v) {
                targetComponent[target[idx]]++;            
            }
            for (int idx : v) {
                if (targetComponent.count(source[idx]) &&
                    targetComponent[source[idx]])
                {
                    --targetComponent[source[idx]];
                    --ans;
                }
            }
        }

        return ans;
    }
    
    // find the parent and remap all nodes to the parent
    int find(int i) {
        int iCopy = i;
        while (parent[i] != i) {
            i = parent[i];
        }
        //
        while (parent[iCopy] != iCopy) {
            int nI = parent[iCopy];
            parent[iCopy] = i; // parent id
            iCopy = nI;
        }
        //        
        return i;
    }
    
    // 
    void connect(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) {
            parent[pj] = pi;
        }
    }
};