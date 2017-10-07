while True:
    try:
        args = input().split()

        S = int(args[0])
        line = [i for i in range(1, S+1)]

        V = int(args[1])

        if S==0 and V==0:
            break

        for i in range(V):
            serial = input().split()
            L = int(serial[0])
            R = int(serial[1])

            # print(str(L)+" "+str(R))

            for j in range(L-1, R):
                line[j] = -1
                j += 1

            # print(line)

            flag = False
            for j in range(L-1, -1, -1):
                # print(str(j)+" "+str(line[j]))
                if line[j]!= -1:
                    flag = True
                    print(line[j], end=" ")
                    break
            if not flag:
                print("*", end=" ")

            flag = False
            for j in range(R - 1, S, 1):
                if line[j] != -1:
                    flag = True
                    print(line[j])
                    break
            if not flag:
                print("*")

        print("-")
    except EOFError:
        break