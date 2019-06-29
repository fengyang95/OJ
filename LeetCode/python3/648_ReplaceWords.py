# -*- coding: utf-8 -*-
# @Time    : 2019/6/29 17:12
# @Author  : Yuanpeng Li
# @FileName: 648_ReplaceWords.py
"""
648. Replace Words
Medium

453

110

Favorite

Share
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:

Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"


Note:

The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
"""
"""
Runtime: 132 ms, faster than 59.62% of Python3 online submissions for Replace Words.
Memory Usage: 35.4 MB, less than 14.24% of Python3 online submissions for Replace Words.
"""


class Node:
    def __init__(self):
        self.is_word = False
        self.chars = {}


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        node = self.root
        for c in word:
            if not c in node.chars:
                node.chars[c] = Node()
            node = node.chars[c]
        node.is_word = True

    def find_root(self, word):
        result = ''
        node = self.root
        for c in word:
            if c in node.chars:
                result += c
                node = node.chars[c]
                if node.is_word:
                    return result
            else:
                if node.is_word:
                    return result
                else:
                    return ''
        if node.is_word:
            return result
        else:
            return ''


class Solution:

    def replaceWords(self, dict: List[str], sentence: str) -> str:
        trie = Trie()
        for word in dict:
            trie.insert(word)
        res = []
        for word in sentence.split():
            # print('word:',word)
            root = trie.find_root(word)
            # print('root:',root)
            if root != '':
                res.append(root)
            else:
                res.append(word)
        # print(res)
        return ' '.join(res)
