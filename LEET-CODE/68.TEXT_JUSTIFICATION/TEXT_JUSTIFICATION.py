class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        l=[]
        s=""
        for i in words:
            if s=="":
                s+=i
            elif len(s)+len(i)+1<=maxWidth:
                s+=" "+i
            else:
                l.append(s)
                s=i
        l.append(s)
        for i in range(len(l)):
            if(len(l[i])<maxWidth):
                if(i==len(l)-1):
                    l[i]=l[i]+" "*(maxWidth-len(l[i]))
                elif (len(l[i].split())==1):
                    l[i]=l[i]+" "*(maxWidth-len(l[i]))
                else:
                    n=maxWidth-len(l[i])
                    s=l[i].split()
                    sp=(len(s)-1)
                    sn=n//sp
                    es=n%sp
                    newstr=""
                    for i in s:
                        if(es>0):
                            newstr+=i+" "*(sn+1)
                            es-=1
                        else:
                            newstr+=i+" "*sn
                    l[i]=newstr
        return l
                        

                    
      

    