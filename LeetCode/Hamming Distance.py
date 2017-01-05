class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z = x ^ y
        dis = 0
        while z:
            dis = dis + 1
            z = z & (z - 1)
        return dis

sol = Solution()
print sol.hammingDistance(1, 4)
