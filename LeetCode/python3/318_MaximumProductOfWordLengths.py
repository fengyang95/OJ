"""
318. Maximum Product of Word Lengths
Medium

514

47

Favorite

Share
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
"""
"""
Runtime: 1924 ms, faster than 7.93% of Python3 online submissions for Maximum Product of Word Lengths.
Memory Usage: 14 MB, less than 28.14% of Python3 online submissions for Maximum Product of Word Lengths.
"""
from collections import defaultdict
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        stats=defaultdict(set)
        for i,word in enumerate(words):
            for a in word:
                    stats[a].add(i)
        res=0
        for i in range(len(words)-1):
            for j in range(i+1,len(words)):
                word0,word1=words[i],words[j]
                valid=True
                for a in word0:
                    if i in stats[a] and j in stats[a]:
                        valid=False
                        break
                if valid is True:
                    res=max(res,len(word0)*len(word1))
        return res


# 位运算存储状态
"""
Runtime: 396 ms, faster than 66.52% of Python3 online submissions for Maximum Product of Word Lengths.
Memory Usage: 13.4 MB, less than 62.39% of Python3 online submissions for Maximum Product of Word Lengths
"""

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        stats = []
        for word in words:
            tmp = 0
            for a in word:
                tmp = tmp | (1 << ord(a) - ord('a'))
            stats.append(tmp)
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if stats[i] & stats[j] == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        return res

