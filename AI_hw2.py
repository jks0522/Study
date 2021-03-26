from math import sqrt
from queue import PriorityQueue

start='806524731'
goal='123456780'

n=int(sqrt(len(goal))) # 보드 크기

class Node():
    def __init__(self,state,path):
        self.state=state
        self.path=path
        self.val=self.f()

    def f_mismatch(self):
        return sum(self.state[i]!=goal[i] for i in range(len(goal)))

    def f_manhattan(self):
        dist=0
        for i in range(len(goal)):
            r,c=i//n,i%n
            r1,c1=self.state.index(goal[i])//n,self.state.index(goal[i])%n
            dist+=abs(r1-r)+abs(c1-c)
        return dist

    def f(self):
        return len(self.path)+self.f_manhattan()

    def __lt__(self,other):
        return self.val<other.val

def print_puzzle(state):
    for i in range(n):
        print(state[n*i:n*(i+1)])
def Move(node):
    p=node.state
    i=p.index('0') # 빈 칸 위치
    child=[]
    if not (i%n==0): # 좌변이 아니면
        q=p[:i-1]+p[i]+p[i-1]+p[i+1:]
        child.append(Node(q,node.path+'L'))
    if not (i%n==n-1): # 우변이 아니면
        q=p[:i]+p[i+1]+p[i]+p[i+2:]
        child.append(Node(q,node.path+'R'))
    if i>=n: # 상변이 아니면
        q=p[:i-n]+p[i]+p[i-n+1:i]+p[i-n]+p[i+1:]
        child.append(Node(q,node.path+'U'))
    if i<n*n-n: # 하변이 아니면
        q=p[:i]+p[i+n]+p[i+1:i+n]+p[i]+p[i+n+1:]
        child.append(Node(q,node.path+'D'))
    return child


Q=PriorityQueue()
root=Node(start,'-') # 루트 노드
Q.put(root)
V=[root.state]
while not Q.empty():
    node=Q.get()
    if node.state==goal:
        break
    else:
        child=Move(node)
        for j in range(len(child)):
            if child[j].state not in V:
                Q.put(child[j])
                V.append(node.state)

q = start
count = 0
for position in node.path[0:]:
    i = q.index('0')
    if count==0:
        print("Initial state:")
    elif count == len(node.path)-1:
        print("Goal state:")
    else:
        print("Step: ", count)
    
    
    if(position == '-'):
        print_puzzle(start)
    elif(position == 'L'):
        q=q[:i-1]+q[i]+q[i-1]+q[i+1:]
        print_puzzle(q)
    elif(position == 'R'):
        q=q[:i]+q[i+1]+q[i]+q[i+2:]
        print_puzzle(q)
    elif(position == 'U'):
        q=q[:i-n]+q[i]+q[i-n+1:i]+q[i-n]+q[i+1:]
        print_puzzle(q)
    elif(position == 'D'):
        q=q[:i]+q[i+n]+q[i+1:i+n]+q[i]+q[i+n+1:]
        print_puzzle(q)
    count+=1
