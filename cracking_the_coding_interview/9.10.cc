#include <iostream>
#include <vector>
using namespace std;

class Box {
    int getHeight(vector<int>& w, vector<int>& l, vector<int>& h, int n, int idx, vector<int>& hs)
    {
        if (hs[idx])
            return hs[idx];

        int curr_w = w[idx];
        int curr_l = l[idx];
        hs[idx] = h[idx];
        for (int i = 0; i < n; ++i)
        {
            if (w[i] < curr_w && l[i] < curr_l)
                hs[idx] = max(hs[idx], getHeight(w, l, h, n, i, hs) + h[idx]);
        }

        return hs[idx];
    }

public:
    int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
        int highest = 0;
        vector<int> hs(n, 0);
        for (int i = 0; i < n; ++i)
            highest = max(highest, getHeight(w, l, h, n, i, hs));
        return highest;
    }
};

int main(int argc, char *argv[])
{
    Box box;
    vector<int> w(500), l(500), h(500);
    for (int i = 0; i < 500; i++)
        w[i] = l[i] = h[i] = i;
    cout << box.getHeight(w, l, h, 500) << endl;
    return 0;
}
