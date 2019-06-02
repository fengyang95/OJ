def bfs(graph,begin,path,res,values,x_path,x_paths):
    if begin not in graph:
        x_paths.append(x_path)
        res.append(path+[values[begin-1]])
        return
    for end in graph[begin]:
        bfs(graph,end[0],path+[values[begin-1]],res,values,x_path+end[1],x_paths)


if __name__=='__main__':
    N,Q=input().split()
    N,Q=int(N),int(Q)
    values=[int(val) for val in input().split()]

    graph={}
    for _ in range(N-1):
        beg,end,x=input().split()
        beg,end=int(beg),int(end)
        if beg in graph:
            graph[beg].append((end,x))
        else:
            graph[beg]=[(end,x)]

    #print(graph)
    begins=[]
    for _ in range(Q):
        begin=int(input())
        begins.append(begin)
    for begin in begins:
        if begin not in graph:
            print(values[begin-1])
        else:
            res=[]
            x_paths=[]
            bfs(graph,begin,[],res,values,'',x_paths)
            max_val=0
            result={}
            for index,path in enumerate(res):
                curr_val=path[-1]
                x_path=x_paths[index]
                if x_path in result:
                    result[x_path]+=curr_val
                else:
                    result[x_path]=curr_val
            max_val=0
            for key in result.keys():
                val=result[key]
                max_val=max(max_val,val)
            print(max_val)


