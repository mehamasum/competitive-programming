T = int(input())
for t in range(T):
    N = int(input())
    line = input()
    line = line.split()
    #print(line)

    small = 0
    tall = 0

    for n in range(N-1):
        h1 = int(line[n])
        h2 = int(line[n + 1])
        if h1 > h2:
            tall += 1
        elif h1 < h2:
            small += 1
    print("Case " + str(t+1) + ": "+ str(small) + " " + str(tall) )
