global count
global hanoi_move
hanoi_move = []
count = 0

def Hanoi(n, a, b): #원판뭉치를 a에서 b로 옮김
    global count
    if n == 1:
        # print('{0} {1}'.format(a, b))
        hanoi_move.append((a, b))
        count += 1
        return
    num = [1, 2, 3]
    num.remove(a)
    num.remove(b)
    c = num[0]
    Hanoi(n-1, a, c)
    hanoi_move.append((a, b))
    count += 1
    Hanoi(n-1, c, b)
    
n = int(input())
Hanoi(n, 1, 3)
print(count)
for a, b in hanoi_move:
    print('{0} {1}'.format(a, b))