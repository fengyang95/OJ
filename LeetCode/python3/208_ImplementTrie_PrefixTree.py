# -*- coding: utf-8 -*-
# @Time    : 2019/6/28 19:37
# @Author  : Yuanpeng Li
# @FileName: 208_ImplementTrie_PrefixTree.py
"""
208. Implement Trie (Prefix Tree)
Medium

1634

33

Favorite

Share
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
"""
"""
Runtime: 140 ms, faster than 79.82% of Python3 online submissions for Implement Trie (Prefix Tree).
Memory Usage: 29.6 MB, less than 46.08% of Python3 online submissions for Implement Trie (Prefix Tree).
"""


class Node:
    def __init__(self):
        self.chars = {}
        self.is_word = False

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        if not word:
            return
        curr_node = self.root

        for c in word:
            if c not in curr_node.chars:
                curr_node.chars[c] = Node()
            curr_node = curr_node.chars[c]
        curr_node.is_word = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        if not word:
            return True
        curr_node = self.root
        for c in word:
            if c not in curr_node.chars:
                return False
            else:
                curr_node = curr_node.chars[c]
        return curr_node.is_word

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        if not prefix:
            return True
        curr_node = self.root
        for c in prefix:
            if c not in curr_node.chars:
                return False
            else:
                curr_node = curr_node.chars[c]
        return True

# Your Trie object will be instantiated and called as such:
if __name__=='__main__':
    word='appe'
    prefix='app'
    obj = Trie()
    obj.insert(word)
    param_2 = obj.search(word)
    param_3 = obj.startsWith(prefix)
