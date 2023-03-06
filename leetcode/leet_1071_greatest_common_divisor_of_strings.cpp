#include "../common.h"


class Mine {
public:
    string gcdOfStrings(string str1, string str2) {
        int e1 = str1.size();
        int e2 = str2.size();
        if (e1 == 0 || e2 == 0) return "";
        
        while (e1 != 0 && e2 != 0) {
            if (e1 >= e2) {
                if (!minus(str1, e1, str2, e2)) return "";
            } else {
                if (!minus(str2, e2, str1, e1)) return "";
            }
        }
        if (e1 == 0) return string(str2, 0, e2);
        else if (e2 == 0) return string(str1, 0, e1);       
        else return ""; 
    }
    
    // e1 change, e2 does not change
    bool minus(string &str1, int &e1, string &str2, int e2)
    {
        // !! the difference between e2-- and --e2
        while (e2--) {
            e1--;
            if (str1[e1] != str2[e2]) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    string gcdOfString(const string& s1, const string& s2) {
        return (s1 + s2 == s2 + s1)
            ? s1.substr(0, gcd(size(s1), size(s2))) : "";
    }
};


class Solution2 {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() < str2.size()) return gcdOfStrings(str2, str1);
        if (str2.empty()) return str1;
        if (str1.substr(0, str2.size()) != str2) return "";
        // from str2.size() till end
        return gcdOfStrings(str1.substr(str2.size()), str2);
    }



};