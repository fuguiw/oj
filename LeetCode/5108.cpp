#include <string>
using namespace std;

class Solution {
public:
    string encode(int num) {
        string result;

        int i;
        for (i = 0; i < 32; i++) {
            int tmp = 1 << i;
            if (num < tmp) {
                break;
            }
            num -= tmp;
        }

        for (i -= 1; i >= 0; i--) {
            int tmp = 1 << i;
            if (num >= tmp) {
                num -= tmp;
                result += "1";
            } else {
                result += "0";
            }
        }

        return result;
    }
};