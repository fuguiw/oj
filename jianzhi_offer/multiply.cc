class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> pre(len);
        vector<int> post(len);
        vector<int> product(len, 1);

        pre[0] = A[0];
        for (int i = 1; i < len; ++i)
            pre[i] = pre[i - 1] * A[i];
        post[len - 1] = A[len - 1];
        for (int i = len - 2; i >= 0; --i)
            post[i] = post[i + 1] * A[i];

        for (int i = 0; i < len; ++i)
        {
            if (i > 0)
                product[i] *= pre[i - 1];
            if (i < len - 1)
                product[i] *= post[i + 1];
        }
        return product;
    }
};
