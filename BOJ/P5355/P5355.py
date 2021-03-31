t = int(input())

i = 0
while i < t:
    arr = input().split()

    result = 0
    for x in arr:
        if x == "@":
            result *= 3
        elif x == "%":
            result += 5
        elif x == "#":
            result -= 7
        else:
            result += float(x)
    print("%.2f" %result)
    i+=1