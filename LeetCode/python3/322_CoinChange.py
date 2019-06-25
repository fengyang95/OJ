# -*- coding: utf-8 -*-
# @Time    : 2019/6/25 22:06
# @Author  : Yuanpeng Li
# @FileName: 322_CoinChange.py
"""
322. Coin Change
Medium

1819

77

Favorite

Share
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.
"""

"""
Runtime: 1288 ms, faster than 63.17% of Python3 online submissions for Coin Change.
Memory Usage: 13.3 MB, less than 60.56% of Python3 online submissions for Coin Change.
"""


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if i >= coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        return dp[-1] if dp[-1] <= amount else -1


# 解法2
"""
Runtime: 1128 ms, faster than 75.84% of Python3 online submissions for Coin Change.
Memory Usage: 13.2 MB, less than 74.64% of Python3 online submissions for Coin Change.
"""
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp=[amount+1]*(amount+1)
        dp[0]=0
        for coin in coins:
            for curr in range(coin,amount+1):
                dp[curr]=min(dp[curr],dp[curr-coin]+1)
        return dp[-1] if dp[-1]<=amount else -1

#解法3 dfs early stop
"""
Runtime: 188 ms, faster than 95.19% of Python3 online submissions for Coin Change.
Memory Usage: 13.5 MB, less than 28.41% of Python3 online submissions for Coin Change.
"""


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins = sorted(coins, reverse=True)
        length = len(coins)
        self.res = amount + 1

        def dfs(begin, remain, count):
            if remain == 0:
                self.res = min(self.res, count)
            for i in range(begin, length):
                if coins[i] <= remain < coins[i] * (self.res - count):# 有希望比原来更好，才更新
                    dfs(i, remain - coins[i], count + 1)

        for beg in range(length):
            dfs(beg, amount, 0)
        print(self.res)
        return self.res if self.res <= amount else -1
