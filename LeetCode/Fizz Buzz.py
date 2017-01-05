class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        str_list = [str(x) for x in range(1, n + 1)]
        x = 3
        while x <= n:
            str_list[x - 1] = "Fizz"
            x = x + 3
        x = 5
        while x <= n:
            str_list[x - 1] = "Buzz"
            x = x + 5
        x = 15
        while x <= n:
            str_list[x - 1] = "FizzBuzz"
            x = x + 15
        return str_list
