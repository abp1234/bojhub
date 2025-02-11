v = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

while True:
    cnt = 0
    s = input()
    if s == '#':
        break
    for ch in s:
        if ch in v:
            cnt += 1
    print(cnt)
