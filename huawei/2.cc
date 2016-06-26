#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

bool is_legal(const vector<int>& in, const vector<int>& out)
{
    stack<int> st;

    for (int i = 0, j = 0; j < in.size(); ) {
        if (!st.empty() && st.top() == out[j]) {
            st.pop();
            j++;
        } else {
            if (i == in.size())
                return false;

            st.push(in[i++]);
        }
    }

    return true;
}

void print_sequence(const vector<int>& out)
{
    cout << out[0];
    for (int i = 1; i < out.size(); i++)
        cout << " " << out[i];
    cout << endl;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];

    vector<int> out(in);
    sort(out.begin(), out.end());
    do {
        if (is_legal(in, out))
            print_sequence(out);
    } while (next_permutation(out.begin(), out.end()));

    return 0;
}
