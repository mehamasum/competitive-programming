def submat(big, small):

    sizeBig = len(big)
    sizeSmall = len(small)

    cnt = 0

    for i in range(sizeBig-sizeSmall+1):
        for j in range(sizeBig-sizeSmall+1):

            match = True

            for m in range(sizeSmall):
                for n in range(sizeSmall):
                    if big[i+m][j+n]!=small[m][n]:
                        match = False
            if match:
                cnt += 1

    return cnt

def rotate(mat):
    size = len(mat)

    rev = list()
    temp = ""

    for j in range(0, size, 1):
        temp = ""
        for i in range(size-1, -1, -1):
            temp += mat[i][j]
        rev.append(temp)

    return rev


while True:
    try:
        args = input().split()

        N = int(args[0])

        n = int(args[1])

        if N==0 and n==0:
            break

        big = list()
        small = list()

        for i in range(N):
            big.append(input())

        for i in range(n):
            small.append(input())

        print(submat(big, small), end=" ")

        mat90 = rotate(small)
        print(submat(big, mat90), end=" ")

        mat180 = rotate(mat90)
        print(submat(big, mat180), end=" ")

        mat270 = rotate(mat180)
        print(submat(big, mat270))

        # print(rotate(small))
        # print(rotate(rotate(small)))
        # print(rotate(rotate(rotate(small))))


    except EOFError:
        break