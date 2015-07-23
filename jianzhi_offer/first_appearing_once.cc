#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if (map.find(ch) == map.end())
            map[ch] = ++idx;
        else
            map[ch] = -1;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int i = numeric_limits<int>::max();
        char rnt;
        for (auto it : map)
        {
            if (it.second != -1 && it.second < i)
            {
                i = it.second;
                rnt = it.first;
            }
        }
        if (i != numeric_limits<int>::max())
            return rnt;
        else
            return '#';
    }

private:
    unordered_map<char, int> map;
    int idx = 0;
};

int main()
{
    Solution sol;
    string s("google");
    for (char c : s)
    {
        sol.Insert(c);
        cout << sol.FirstAppearingOnce() << endl;
    }
    return 0;
}
