#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
            return nullptr;

        map<int, UndirectedGraphNode *> m;
        queue<UndirectedGraphNode *> q;

        q.push(node);

        UndirectedGraphNode *ret = nullptr;
        while (!q.empty()) {
            UndirectedGraphNode *n = q.front();
            q.pop();

            UndirectedGraphNode *curr_node;
            if (m[n->label] == nullptr) {
                curr_node = new UndirectedGraphNode(n->label);
                m[curr_node->label] = curr_node;
            } else {
                curr_node = m[n->label];
            }

            if (ret == nullptr)
                ret = curr_node;

            for (auto p : n->neighbors) {
                UndirectedGraphNode *tmp;
                if (m[p->label] == nullptr) {
                    tmp = new UndirectedGraphNode(p->label);
                    q.push(p);
                    m[p->label] = tmp;
                } else {
                    tmp = m[p->label];
                }
                curr_node->neighbors.push_back(tmp);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(2);
    UndirectedGraphNode n3(3);

    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n3);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n3);

    UndirectedGraphNode *n = sol.cloneGraph(&n1);

    for (auto i : n->neighbors)
        cout << i->label << " "  << i->neighbors[0]->label << endl;


    return 0;
}
