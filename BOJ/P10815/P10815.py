n = input()
a = set(input().split())

m = input()
b = input().split()

for index in b:
    if(index in a):
        print(1, end=' ')
    else:
        print(0, end=' ')
