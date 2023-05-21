def shortestbridge(grid):
    x=len(grid)
    y=len(grid[0])
    bool=False
    s=set()
    for i in range(x):
        for j in range(y):
            if grid[i][j]==1:
                dfs(grid,i,j,s)
                bool=True
                break
        if bool:
            break
    q=[]
    for i in s:
        q.append(i)
    di=[[0,1],[0,-1],[1,0],[-1,0]]
    level=0
    while len(q)!=0:
        size=len(q)
        for i in range(size):
            curr=q.pop()
            curri= curr//y
            currj= curr%y
            for j in di:
                newi=curri+j[0]
                newj=currj+j[1]
                neighbor=newi*y+newj
                if newi>=0 and newi<x and newj>=0 and newj<y and neighbor not in s:
                    if grid[newi][newj]==1:
                        return level
                    q.append(neighbor)
                    s.add(neighbor)
        level+=1
    return -1
def dfs(grid,i,j,s):
    int x = len(grid)
    int y = len(grid[0])
    if i<0 or i>=x or j<0 or j>=y or grid[i][j]!=1 or (i*y+j) in s:
        return
    s.add(i*y+j)
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    for d in dir:
        ni=i+d[0]
        nj=j+d[1]
        dfs(grid,ni,nj,s)
        

                    



    
                