def number_needed(a, b):
    freq = list()
    for i in range(26):
        freq.append(0)
    for c in a:
        freq[ord(c)-97] += 1
    for c in b:
        freq[ord(c)-97] -= 1
    cnt = 0
    for i in range(26):
        cnt += abs(freq[i])
    return cnt

a = input().strip()
b = input().strip()

print(number_needed(a, b))
