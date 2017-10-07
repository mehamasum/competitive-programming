cost = {}
tol = 0

T = int(input())
for i in range(T):
    N = int(input())
    for j in range(N):
        tokens = input().split()
        cost[tokens[0]] = int(tokens[1])
    L = int(input())
    for k in range(L):
        line = input()
        size = len(line)
        for m in range(size):
            try:
                tol += cost[line[m]]
            except KeyError:
                tol += 0

    print("%d.%2d$" % ((tol / 100), (tol % 100)))
    cost.clear()
    tol = 0

