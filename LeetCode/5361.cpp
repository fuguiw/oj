#include <cmath>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        for (int i = y1; i <= y2; i++) {
            for (int j = x1; j <= x2; j++) {
                double dis = sqrt(pow(i - y_center, 2) + pow(j - x_center, 2));
                if (dis <= double(radius)) {
                    return true;
                }
            }
        }
        return false;
    }
};