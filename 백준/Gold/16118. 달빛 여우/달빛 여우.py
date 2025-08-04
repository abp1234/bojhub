import sys
import heapq

INF = int(1e9)

input = sys.stdin.readline
N, M = map(int, input().split())
tree = [[] for _ in range(N)]
for _ in range(M):
    a, b, d = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append((b, d * 2))
    tree[b].append((a, d * 2))


wolf = [INF] * N
wolf[0] = 0
pq = [(0, 0)]
while pq:
    cost, cur = heapq.heappop(pq)
    if wolf[cur] < cost:
        continue
    for next_node, w in tree[cur]:
        if wolf[next_node] > cost + w:
            wolf[next_node] = cost + w
            heapq.heappush(pq, (wolf[next_node], next_node))


fox = [[INF, INF] for _ in range(N)]
visited = [[False, False] for _ in range(N)]
fox[0][0] = 0
pq2 = [(0, 0, 0)] 

while pq2:
    cost, cur, state = heapq.heappop(pq2)
    if visited[cur][state]:
        continue
    visited[cur][state] = True

    for next_node, w in tree[cur]:
        nstate = 1 - state
        if state == 0:
            ncost = cost + w // 2
        else:
            ncost = cost + w * 2
        if fox[next_node][nstate] > ncost:
            fox[next_node][nstate] = ncost
            heapq.heappush(pq2, (ncost, next_node, nstate))

cnt = 0
for i in range(1, N):
    if wolf[i] < min(fox[i][0], fox[i][1]):
        cnt += 1

print(cnt)
