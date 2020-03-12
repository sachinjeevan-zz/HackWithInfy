import re
t=int(input())
for j in range(t):
    S = input()
    a= re.finditer("(?=([a-z]+[0-9:]*[/]{1}[a-z0-9]*[\\\\]{1}[a-z]+))",S)
    c= [i.group(1) for i in a]
    d=len(c)
    if(d>0):
        for k in c:
            count=0
            for i in k[::-1]:
                if(i.islower()):
                    count+=1
                else:
                    break
            d+=(count-1)
    print(d)
        
