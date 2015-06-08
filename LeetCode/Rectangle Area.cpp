#include <iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);

        int area = 0;
        if (right > left && top > bottom)
            area = -(right - left) * (top - bottom);

        area += (D - B) * (C - A) + (H - F) * (G - E);

        return area;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    cout << sol.computeArea(-2, -2, 2, 2, 3, 3, 4, 4) << endl;
    return 0;
}
