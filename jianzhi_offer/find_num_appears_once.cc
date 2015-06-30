class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        *num1 = *num2 = 0;

        if (data.size() < 2)
            return ;

        int x = 0;
        for (int num : data)
            x ^= num;

        int pos = 0;
        for (int i = 0; i < 32; i++) {
            if (x & (1 << i)) {
                pos = i;
                break;
            }
        }

        for (int num : data) {
            if (num & (1 << pos))
                *num1 ^= num;
            else
                *num2 ^= num;
        }
    }
};
