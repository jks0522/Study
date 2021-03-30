arr = input().split()
a = int(arr[0])
b = int(arr[1])
c = int(arr[2])
d = int(input())

a = (a + d//3600) % 24
d %= 3600
b = (b + d//60)
if(b >= 60):
    a+=1
    a %= 24
b %= 60
d %= 60
c = (c + d)
if(c >= 60):
    b+=1
    if(b >= 60):
        a+=1
        a %= 24
    b %= 60
c %= 60


print(a, b, c)