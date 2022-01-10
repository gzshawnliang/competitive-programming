import queue
import sys
import math
import random  
import datetime
# catch up and win

k = int(input())  # representing after how many turns the sus man will make another move

mapData=[]
mapData.append("************")

for i in range(10):
    s = input()  # the map
    mapData.append("*"+s+"*")

mapData.append("************")

for x in mapData:
    print (x,file=sys.stderr)

def hash(point):
    return point[0]*10+point[1]

def getDir(point):
    dir=[]
    x=point[0]
    y=point[1]
    if mapData[y-1][x] !='*':
        dir.append((x,y-1,'U'))

    if mapData[y+1][x] !='*':
        dir.append((x,y+1,'D'))

    if mapData[y][x-1] !='*':
        dir.append((x-1,y,'L'))

    if mapData[y][x+1] !='*':
        dir.append((x+1,y,'R'))
    return dir

P=()   
E=()
neighbours={}
for y in range(1, 11):
    for x in range(1, 11):
        if mapData[y][x]=='P' :
            P=(x,y)
        elif mapData[y][x]=='E' :
            E=(x,y)
        elif mapData[y][x]=='*' :
            continue
        neighbours[(x,y)]=getDir((x,y))

def runShortestPath(start,target):
    distance=[1000000]*12*12
    S=hash(start)
    distance[S]=0
    q = queue.Queue()
    q.put(start)
    while not q.empty():
        now=q.get()
        # print (now,file=sys.stderr)
        if (now[0],now[1]) in neighbours :
            for nei in neighbours[(now[0],now[1])]:
                v=hash((nei[0],nei[1]))
                u=hash(now)
                if distance[v] > distance[u]+1:
                    distance[v] =distance[u]+1
                    q.put((nei[0],nei[1]))
    return distance[hash(target)]

# print (runShortestPath((2,2),(7,6)),file=sys.stderr)
random.seed(datetime.datetime.now())
# game loop
while True:
    ene_y,ene_x = map(int, input().split())  # the sus man's coordinate
    ene_y = ene_y+1
    ene_x = ene_x+1

    E=(ene_x,ene_y)
    print (P,file=sys.stderr)
    print (E,file=sys.stderr)
    dir=getDir(P)
    print (dir,file=sys.stderr)
    if len(dir) == 1:
        print(dir[0][2])
        P=(dir[0][0],dir[0][1])
    else :
        result=[]
        for d in dir:
            dist=runShortestPath(d,E)
            result.append((dist,d))
        
        result.sort(key=lambda tup: tup[0])
        print (result,file=sys.stderr)
        if result[0][0]==result[1][0]:
            # selectResult= result[0]
            # if abs(P[0]-E[0]) > abs(P[1]-E[1]) :
            #     print("-----------------",file=sys.stderr)
            #     selectResult= result[1]
            selectResult= random.choice([result[0],result[1]])
            # print("||||||||||||||||||||||",file=sys.stderr)
            print(selectResult[1][2])
            P=(selectResult[1][0],selectResult[1][1])
            # print(result[random.randint(0,1)][1][2])
        else:
            # print("*************",file=sys.stderr)
            print(result[0][1][2])
            P=(result[0][1][0],result[0][1][1])

        


