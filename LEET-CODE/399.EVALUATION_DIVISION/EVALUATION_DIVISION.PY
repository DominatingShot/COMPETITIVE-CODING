#Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
#Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]


def calcEquation( equations , values, queries ):
    d={}
    for i in range(len(equations)):
        a,b=equations[i][0],equations[i][1]
        if a not in d:
            d[a]={}
        if b not in d:
            d[b]={}
        d[a][b]=values[i]
        d[b][a]=1/values[i]
        print(d)
equationb = [["a","b"],["b","c"]]
values = [2.0,3.0]
queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
calcEquation(equationb,values,queries) 
            

    


        
        
