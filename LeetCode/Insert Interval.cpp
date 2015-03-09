#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator i, j;

        for (i = intervals.begin(); i != intervals.end(); i++) {
            if (i->end >= newInterval.start) {
                newInterval.start = min(newInterval.start, i->start);
                j = i;
                break;
            }
        }

        if (i == intervals.end())
            j = i;

        for (; i != intervals.end(); i++) {
            if (i->start > newInterval.end) {
                break;
            } else {
                    newInterval.end = max(newInterval.end, i->end);
            }
        }

        i = intervals.erase(j, i);
        intervals.insert(i, newInterval);

        return intervals;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<Interval> v;
    Interval i1(3,5);
    Interval i2(6,9);
    Interval i3(1,2);

    v.push_back(i1);
    /* v.push_back(i2); */

    v = sol.insert(v, i3);

    for (auto i : v)
        cout << i.start << " " << i.end << endl;

    return 0;
}
