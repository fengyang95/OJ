import math
if __name__=='__main__':
    w,b=input().split()
    w,b=int(w),int(b)
    h=int((math.sqrt(1+8*(w+b))-1)/2)

    res=[0]
    cache={}
    for i in range(w+1):
        cache[i]={}
        for j in range(b+1):
            cache[i][j]={}
            for k in range(h+1):
                cache[i][j][k]=-1


    def dfs(w,b,h,res):
        if cache[w][b][h]!=-1:
            res[0]+=cache[w][b][h]
        if h==0:
            res[0]+=1
            cache[w][b][h]=res[0]
            return
        else:
            if h<=b:
                dfs(w,b-h,h-1,res)
            if h<=w:
                dfs(w-h,b,h-1,res)
    dfs(w,b,h,res)
    print(h)
    print(res[0])



