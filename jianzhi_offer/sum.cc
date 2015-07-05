#include <iostream>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        int sum = n;
        sum && (sum += Sum_Solution(n - 1));
        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int n;
    while (cin >> n)
        cout << sol.Sum_Solution(n) << endl;
    return 0;
}
