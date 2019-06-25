# -*- coding: utf-8 -*-
# @Time    : 2019/6/16 11:10
# @Author  : Yuanpeng Li
# @FileName: 127_WordLadder.py
"""
127. Word Ladder
Medium

1459

810

Favorite

Share
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
"""
from collections import defaultdict


class Solution:
    # method A
    def ladderLength(self, beginWord, endWord, wordList):
        if not endWord or endWord not in wordList or not wordList:
            return 0

        def is_valid(word1,word2):
            if word1==word2 or len(word1)!=len(word2):
                return False
            diff_num=0
            for i in range(len(word1)):
                if word1[i]!=word2[i]:
                    diff_num+=1
                    if diff_num>1:
                        return False
            return True


        # BFS -> queue(node, level)
        queue = [(beginWord, 1)]
        vist = {beginWord: True}
        while queue:
            curtWord, level = queue.pop(0)
            for word in wordList:
                if is_valid(word,curtWord):
                    if word==endWord:
                        return level+1
                    if word not in vist:
                        vist[word]=True
                        queue.append([word,level+1])
        return 0
