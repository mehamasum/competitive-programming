def isJollyJumper(array):
    # print(array)

    if array[0]==1:
        return 'Jolly'

    jumps = set()

    for i in range(2, array[0]+1):
        # print(str(i))
        diff = abs(array[i] - array[i-1])

        if 0 < diff < array[0]:
            jumps.add(diff)

    # print(jumps)

    if len(jumps) == array[0] - 1:
        return 'Jolly'
    return 'Not jolly'


while True:
    try:
        print(isJollyJumper([int(i) for i in input().split()]))
    except EOFError:
        break
