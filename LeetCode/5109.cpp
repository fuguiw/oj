#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        map<string, string> parents;
        for (int i = 0; i < regions.size(); i++) {
            string parent = regions[i][0];
            for (int j = 1; j < regions[i].size(); j++) {
                parents[regions[i][j]] = parent;
            }
        }

        map<string, bool> visits;
        visits[region1] = true;
        while (parents.find(region1) != parents.end()) {
            region1 = parents[region1];
            visits[region1] = true;
        }

        while (parents.find(region2) != parents.end()) {
            if (visits[region2] == true) {
                return region2;
            }
            region2 = parents[region2];
        }

        return region1;
    }
};