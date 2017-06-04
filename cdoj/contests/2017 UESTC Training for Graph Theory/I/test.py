#!/usr/bin/env python3
s = input()
out = []
t = 1
for i in range(0, len(s) - t + 1):
    out.append(int(s[i : i + t], 2))
    #print(int(s[i : i + t], 2))

for i in range(len(s) - t + 1, len(s)):
    out.append(int(s[i : ] + s[0 : t - (len(s) - i)], 2))
    #print(int(s[i : ] + s[0 : len(s) - i], 2))
    #print(s[i : ] + s[0 : t - (len(s) - i)])
    
    



out.sort()
for i in range(0, pow(2, t)):
    if out[i] != i:
        print(out)
        print(s)
        print(i)
        break
#print(out)
#print(s)