#include <vector>
#include <iostream>
#include <algorithm>
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

bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> v;
        Interval interval;
        int s, e, cnt;

        cnt = intervals.size();
        if (cnt == 0)
            return v;

        sort(intervals.begin(), intervals.end(), cmp);

        s = intervals[0].start;
        e = intervals[0].end;
        for (int i = 0; i < cnt; i++) {
            if (intervals[i].start > e) {
                interval.start = s;
                interval.end = e;
                v.push_back(interval);
                s = intervals[i].start;
                e = intervals[i].end;

            } else {
                e = max(e, intervals[i].end);
            }

            if (i == cnt - 1) {
                interval.start = s;
                interval.end = e;
                v.push_back(interval);
            }

        }

        return v;
    }
};

int main(int argc, char *argv[])
{
    Interval i;
    vector<Interval> v;
    Solution sol;

    i.start = 1;
    i.end = 3;
    v.push_back(i);
    i.start = 2;
    i.end = 6;
    v.push_back(i);
    i.start = 8;
    i.end = 10;
    v.push_back(i);
    i.start = 9;
    i.end = 18;
    v.push_back(i);
    v = sol.merge(v);
    for (int i = 0; i < v.size(); i++)
        cout << v[i].start << " " << v[i].end << endl;
    return 0;
}
