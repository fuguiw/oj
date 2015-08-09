/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
    bool findPath(UndirectedGraphNode* a, UndirectedGraphNode* b, set<int>& s) {
        if (a == b)
            return true;
        for (int i = 0; i < a->neighbors.size(); ++i) {
            if (s.find(a->neighbors[i]->label) == s.end()) {
                s.insert(a->neighbors[i]->label);
                if (findPath(a->neighbors[i], b, s))
                    return true;
            }
        }
        return false;
    }

public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        set<int> s;
        bool rnt = false;
        rnt = findPath(a, b, s);
        if (!rnt) {
            s.clear();
            rnt = findPath(b, a, s);
        }
        return rnt;
    }
};
