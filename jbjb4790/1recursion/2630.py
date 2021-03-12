import sys
import math

white = 0
blue = 0

def possible(x: int, y: int, n: int) -> bool: #x:첫x좌표 y:첫y좌표 n:한변길이
    for i in range(x,x+n):
        for j in range(y,y+n):
            if paper[i][j] != paper[x][y]:
                return False
    return True

def DFS(x: int, y: int, n: int):
    global white
    global blue
    if possible(x,y,n):
        if paper[x][y] == 0:
            white += 1
        else:
            blue += 1
        return
    
    DFS(x,y,n//2)
    DFS(x+n//2,y,n//2)
    DFS(x,y+n//2,n//2)
    DFS(x+n//2,y+n//2,n//2)


n = int(sys.stdin.readline())
paper = []
for _ in range(n):
    paper.append(list(sys.stdin.readline().split()))
DFS(0,0,n)
print(white)
print(blue)

