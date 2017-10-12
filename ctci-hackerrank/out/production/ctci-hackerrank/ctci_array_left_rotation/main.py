def array_left_rotation(a, n, k):
    first = a[k::1]
    first.extend(a[0:k:1])
    return first

n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
answer = array_left_rotation(a, n, k)
print(*answer, sep=' ')
