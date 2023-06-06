class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.strip()
        i=0
        sign=1
        ns=""
        if len(s)==0:
            return s
        else:
            for j in range(len(s)):
                if s[j].isdigit():
                    ns+=s[j]
                elif s[j]=='-':
                    sign=-1
                elif s[j]=='+':
                    sign=1
                else:
                    break
        if len(s)!=0:
            return max(-2**31,min(sign*int(ns),2**31-1))
        else:
            return 0
        
                    

        