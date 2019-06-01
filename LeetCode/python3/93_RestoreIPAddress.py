"""
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
"""
class Solution:
    def restoreIpAddresses(self, s: str):
        self.res = []

        def dfs(s, path):
            if len(s) > (4 - len(path)) * 3:
                return
            if len(s)==0 and len(path) == 4:
                self.res.append('.'.join(path))
                #print(path)
                return

            for i in range(1, 4):
                if i <= len(s):
                    ip = int(s[:i])
                    if str(ip) == s[:i] and ip < 256:
                        dfs(s[i:], path + [s[:i]])
                #print(path)

        if len(s) > 12:
            return self.res
        dfs(s, [])
        return self.res
