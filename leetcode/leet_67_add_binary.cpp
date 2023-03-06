#include "../common.h"
#include <bitset>
/**
 * @brief 
 * 
 */


class Mine1 {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        string ans;
        int carry = 0;
        int i = 1;
        while (i <= m || i <= n) {
            int aVal = (i <= m ? a[m-i] - '0' : 0);
            int bVal = (i <= n ? b[n-i] - '0' : 0);
            int sum = carry + aVal + bVal;
            if (sum >= 2) {
                carry = 1;
                sum -= 2;
            } else {
                carry = 0;
            }
            if (sum == 0) ans.push_back('0');
            else if (sum == 1) ans.push_back('1');
            // else {assert}
            ++i;
        }
        if (carry == 1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class BitManipulation {
public:
    string addBinary(string a, string b) {
        int x = stoi(a, nullptr, 2);
        int y = stoi(b, nullptr, 2);
        int answer, carry;
        while (y) {
            answer = x ^ y;
            carry = (x & y) << 1;
            x = answer;
            y = carry;
        }
        return bitset<32>(answer).to_string();
    }
    


};

int main() {
    BitManipulation bitmani = BitManipulation();
    string res = bitmani.addBinary("101", "100");
    string resNoLeadingZero = res.substr(res.find_first_not_of('0'));

    cout << res << " " << resNoLeadingZero << endl;



    string str = "000000";
    // Yongming Notice the differece from
    // str.erase(0, str.find_first_not_of('0'));
    // The below code will produce "0".
    str.erase(0, min(str.find_first_not_of('0'), str.size() - 1));
    cout << str << endl;


}