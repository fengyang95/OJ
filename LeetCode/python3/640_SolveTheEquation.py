class Solution:
    def solveEquation(self, equation: str) -> str:
        left, right = equation.split('=')

        def parse(s):
            const = 0
            coef = 0
            flag = 1
            i=0
            while i<len(s):
                if s[i].isdigit():
                    curr_index = i
                    while (i < len(s) and s[i].isdigit()):
                        i += 1
                    num = int(s[curr_index:i])
                    if i < len(s) and s[i] == 'x':
                        coef += flag * num
                        i+=1
                    else:
                        const += flag * num
                elif s[i] == '+':
                    flag = 1
                    i+=1
                elif s[i] == '-':
                    flag = -1
                    i+=1
                elif s[i] == 'x':
                    coef += flag
                    i+=1

            return coef, const

        coef_left, const_left = parse(left)
        coef_right, const_right = parse(right)
        coef = coef_left - coef_right
        const = const_right - const_left
        if coef == 0:
            return 'Infinite solutions'
        else:
            return 'x=' + str((const // coef))

if __name__=='__main__':
    Solution().solveEquation("x+5-3+x=6+x-2")
