import re
import numpy as np


goal_x = 0
goal_y = 0
start_x = 0
start_y = 0

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]
path = []
p = []
pathLen = 9999
sum = 0
tag = np.zeros((15, 15), dtype=int)


def getMaze():
    # 读取文件
    file = open("/Users/saikikky/Desktop/DB.pl", "r")
    list_data = file.readlines()
    maze = np.ones((15,15),dtype = int)#设置迷宫大小
    list_all = []

    for row in list_data:
        if row.startswith("s("):
            list_all.append(row)
        if row.startswith("goalState"):
            list_goal = re.findall(r"\d+\.?\d*",row)
        if row.startswith("startState"):
            list_start = re.findall(r"\d+\.?\d*",row)

    for data in list_all:
        x = data[2:3]
        y = data[4:5]
        maze[int(x)][int(y)] = 0 #将可以走的路标记为0
    # test[int(list_goal[0])][int(list_goal[1])] = 3
    # test[int(list_start[0])][int(list_start[1])] = 2
    global goal_x, goal_y, start_x, start_y #声明全局变量
    goal_x = int(list_goal[0]) #目标点横坐标
    goal_y = int(list_goal[1]) #目标点纵坐标
    start_x = int(list_start[0]) #起始点横坐标
    start_y = int(list_start[1]) #起始点纵坐标
    return maze

def dfs(maze, startx, starty):
    if startx == goal_x and starty == goal_y:
        global sum, pathLen, path
        sum = sum + 1
        if len(p) < pathLen:
            pathLen = len(p)

            while len(path) > 0:
                path.pop()

            for i in p:
                path.append(i)
            print("len")
            print(len(path))
        return
    else:
        for i in range(4):
            nextx = startx + direction[i][0]
            nexty = starty + direction[i][1]
            if check(maze, nextx, nexty):
                tag[nextx][nexty] = 1
                p.append([nextx, nexty])
                dfs(maze, nextx, nexty)
                tag[nextx][nexty] = 0
                p.pop()



def check(maze, x, y):
    return x >= 0 and y >= 0 and x < len(maze) and y < len(maze[0]) and maze[x][y] == 0 and tag[x][y] == 0



if __name__ == "__main__":
    maze = getMaze()
    print(start_x)
    print(start_y)
    print(goal_x)
    print(goal_y)
    # maze[start_x][start_y] = 2
    # maze[goal_x][goal_y] = 2
    p.append([start_x, start_y])
    dfs(maze, start_x, start_y)
    print(sum)
    print(pathLen)
    print("len")
    for i in path:
        print(i, end="")
