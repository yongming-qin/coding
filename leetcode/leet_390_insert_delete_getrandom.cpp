#include "../common.h"

/**
 * @brief 
 * 
 * 
 * 
 */


#include <random>

class RandomizedSet {
public:
    map<int,int> mapPosition; // value : position in data
    vector<int> data;
    random_device random_dev;
    mt19937 generator;
    
    RandomizedSet() {
        generator = mt19937(random_dev());
    }
    
    bool insert(int val) {
        if (mapPosition.count(val)) return false;
        data.push_back(val);
        mapPosition[val] = data.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mapPosition.count(val) == 0) return false;
        int pos = mapPosition[val];
        data[pos] = data.back();
        mapPosition[data[pos]] = pos;
        data.pop_back();
        mapPosition.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = data.size();
        uniform_int_distribution<int> uniformDist(0, n-1);
        int pos = uniformDist(random_dev);
        return data[pos];
    }
};

int main(int argc, char** argv) {

    set<int> data{1,2,3};
    auto pos = next(data.begin(), 2);
    cout << *pos << endl;
    return 0;

    // std::random_device r;
    // std::mt19937 generator(r());
    // std::uniform_int_distribution<int> uniformDist(0, 10);
    // int res = uniformDist(generator);
    // std::cout << res << std::endl;


    // //Your RandomizedSet object will be instantiated and called as such:
    // RandomizedSet* obj = new RandomizedSet();
    // int val = 1;
    // bool param_1 = obj->insert(val);
    // bool param_2 = obj->remove(val);
    // obj->insert(2);
    // int param_3 = obj->getRandom();

    // cout << param_1 << " " << param_2 << " " << param_3 << endl;
    // return 0;
}

 


 class YongmingTryRandomizedSet {
public:
    set<int> data;
    random_device random_dev;
    mt19937 generator;
    RandomizedSet() {
        generator = mt19937(random_dev());
    }
    
    bool insert(int val) {
        if (data.count(val)) return false;
        data.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (data.count(val)) {
            data.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        uniform_int_distribution<int> uniform(0, data.size() - 1);
        int pos = uniform(random_dev);
        return *next(data.begin(), pos);
        // Yongming. for non legacyRandomAccessIterator. this is linear time.
    }
};