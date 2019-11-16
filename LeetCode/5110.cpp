#include <vector>
#include <string>
using namespace std;

class Solution {

    void find(vector<string> ws, map<string, int>& m, vector<vector<string>> ss, int i, vector<string> &result)
    {
        if (i == ws.size()) {
            string str;
            for (int j = 0; j < ws.size(); j++) {
                str += ws[j];
                if (j != ws.size() - 1) {
                    str += " ";
                }
            }
            result.push_back(str);
            return;
        }

        if (m.find(ws[i]) == m.end()) {
            find(ws, m, ss, i + 1, result);
            return;
        }

        cout << ws[i] << endl;
        int index = m[ws[i]];
        for (int j = 0; j < ss[index].size(); j++) {
            ws[i] = ss[index][j];
            find(ws, m, ss, i + 1, result);
        }
    }
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<vector<string>> ss;
        for (int i = 0; i < synonyms.size(); i++) {
            string w1 = synonyms[i][0];
            string w2 = synonyms[i][1];

            bool f = false;
            for (int j = 0; j < ss.size(); j++) {
                for (int k = 0; k < ss[j].size(); k++) {
                    if (ss[j][k] == w1) {
                        ss[j].push_back(w2);
                        f = true;
                        break;
                    }
                    if (ss[j][k] == w2) {
                        ss[j].push_back(w1);
                        f = true;
                        break;
                    }
                }
            }
            if (!f) {
                ss.push_back(synonyms[i]);
            }
        }

        map<string, int> m;
        for (int i = 0; i < ss.size(); i++) {
            sort(ss[i].begin(), ss[i].end());
            for (int j = 0; j < ss[i].size(); j++) {
                m[ss[i][j]] = i;
            }
        }

        vector<string> ws;
        int begin, end;
        for (begin = 0, end = 0; end < text.size(); end++) {
            if (text[end] == ' ') {
                if (begin != end) {
                    ws.push_back(text.substr(begin, end - begin));
                }
                begin = end + 1;
            }
        }
        if (begin != end) {
            ws.push_back(text.substr(begin, end - begin));
        }

        vector<string> result;
        find(ws, m, ss, 0, result);
        return result;
    }
};
