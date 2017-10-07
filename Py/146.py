def nextPermutation(num):
    k, l = -1, 0
    for i in range(len(num) - 1):
        if num[i] < num[i + 1]:
            k = i

    if k == -1:
        num.reverse()
        return False

    for i in range(k + 1, len(num)):
        if num[i] > num[k]:
            l = i

    num[k], num[l] = num[l], num[k]
    num[k + 1::] = num[:k:-1]
    return True


while True:
    try:
        line = input()
        # line = ['a', 'b', 'b', 'a']
        # print(line)
        line = list(line)
        # print(line)

        if '#' in line:
            break
        else:
            ret = nextPermutation(line)
            if ret:
                print(''.join(line))
            else:
                print("No Successor")
    except EOFError:
        break
