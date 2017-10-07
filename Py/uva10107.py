vals = list()



while True:

    try:
        vals.append(int(input().strip()))
        vals.sort()

        #print(vals)
        #print(cnt)

        cnt = len(vals)

        if cnt % 2 == 1:
            #print('odd')
            print(vals[int((cnt+1)/2) -1])
        else:
            #print('even')
            v1 = vals[int(cnt/2) -1]
            v2 = vals[int(cnt/2)]
            print(int((v1+v2)/2))

    except EOFError:
        break