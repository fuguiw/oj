class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(), numbers.end());
        int zero_cnt = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == 0) {
                ++zero_cnt;
            } else {
                if (i > 0 && numbers[i - 1] != 0 && numbers[i] != numbers[i - 1] + 1) {
                    int dis = numbers[i] - numbers[i - 1];
                    zero_cnt -= (dis - 1);
                    if (zero_cnt < 0 || dis == 0)
                        return false;
                } 
            }
        }
        return true;
    }
};
