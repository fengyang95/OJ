# -*- coding: utf-8 -*-
# @Time    : 2019/6/29 16:43
# @Author  : Yuanpeng Li
# @FileName: 211_AddAndSearchWord_DataStructureDesign.py
"""
211. Add and Search Word - Data structure design
Medium

860

54

Favorite

Share
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
"""

"""
Runtime: 296 ms, faster than 66.95% of Python3 online submissions for Add and Search Word - Data structure design.
Memory Usage: 27.3 MB, less than 31.52% of Python3 online submissions for Add and Search Word - Data structure design.
"""


class Node:
    def __init__(self):
        self.is_word = False
        self.chars = {}


class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        curr_node = self.root
        for c in word:
            if c not in curr_node.chars:
                curr_node.chars[c] = Node()
            curr_node = curr_node.chars[c]
        curr_node.is_word = True

    def search_helper(self, word, node) -> bool:
        if not word:
            return node.is_word
        for i, c in enumerate(word):
            if c == '.':
                for ch in node.chars:
                    if self.search_helper(word[i + 1:], node.chars[ch]):
                        return True
                # 之前这里忘记返回False！！
                return False
            elif c in node.chars:
                node = node.chars[c]
            else:
                return False
        return node.is_word

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.search_helper(word, self.root)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
