class Solution {
public:
    int magicTower(vector<int>& nums) {
      long long tot = 1;
      for (int i = 0; i < nums.size(); i++) {
        tot += nums[i];
      }
      if (tot <= 0) {
        return -1;
      }

      priority_queue<int> q;
      tot = 1;
      int ans = 0;
      for (int i = 0; i < nums.size(); i++) {
        tot += nums[i];
        if (nums[i] >= 0) {
          continue;
        }

        while (!q.empty() && tot <= 0) {
          int tmp = q.top();
          if (tmp > nums[i]) {
            ans++;
            break;
          }
          tot -= tmp;
          q.pop();
        }
        if (tot <= 0) {
          ans++;
        } else {
          q.push(nums[i]);
        }
      }
      return ans;
    }
};
