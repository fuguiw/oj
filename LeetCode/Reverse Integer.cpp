class Solution {
private:
	int doReverse(int x) {
		int ret = 0;
		while (x) {
			ret = ret * 10 + x % 10;
			x /= 10;
		}
		return ret;
	}
public:
    int reverse(int x) {
		if (x < 0) return -doReverse(-x);
		else return doReverse(x);
    }
};

