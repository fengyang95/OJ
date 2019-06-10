# -*- coding: utf-8 -*-
# @Time    : 2019/6/10 10:08
# @Author  : Yuanpeng Li
# @FileName: 49_GroupAnagrams.py
"""
49. Group Anagrams
Medium

1657

110

Favorite

Share
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
"""
"""
Runtime: 116 ms, faster than 80.98% of Python3 online submissions for Group Anagrams.
Memory Usage: 15.8 MB, less than 86.65% of Python3 online submissions for Group Anagrams.
"""


class Solution:
    def groupAnagrams(self, strs):
        res=[]
        d={}
        for s in strs:
            key=''.join(sorted(s))
            if key in d.keys():
                d[key].append(s)
            else:
                d[key]=[s]
        for item in d.items():
            res.append(item[1])
        return res

