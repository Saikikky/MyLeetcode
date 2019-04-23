//
//  main.cpp
//  BFS_OIL
//
//  Created by 王晨懿 on 16/5/18.
//  Copyright © 2016年 王晨懿. All rights reserved.
//

#include <iostream>
using namespace std;
#include <queue>


struct Node{
    int x;
    int y;
};

int m, n;
char oil[102][102];
int dis[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
bool visit[102][102];
queue <Node> q;
int block = 0;

void bfs(int i, int j);
bool isRight(Node now);


int main()
{

    string str;
    while (true)
    {
        block = 0;

        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        
        for (int i = 0; i < m; ++i)
        {
            cin >> str;
            for (int j = 0; j < n; ++j)
            {
                oil[i][j] = str[j];
                visit[i][j] = false;
            }
        }
        

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visit[i][j] && oil[i][j] == '@')
                {
                    bfs(i, j);
                    ++block;
                }
            }
        }
        cout << block << endl;
    }
}

    
void bfs(int i, int j)
{
    Node now;
    now.x = i;
    now.y = j;
    q.push(now);
        
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        
//        visit[now.x][now.y] = true;
        
        for (int k = 0; k < 8; ++k)
        {
            Node next;
            next.x = now.x + dis[k][0];
            next.y = now.y + dis[k][1];
            if (isRight(next))
            {
                q.push(next);
                visit[next.x][next.y] = true;
            }
        }
    }
}


bool isRight(Node now)
{
    if (now.x < 0 || now.x >= m || now.y < 0 || now.y >= n)
        return false;
    if (visit[now.x][now.y])
        return false;
    if (oil[now.x][now.y] == '*')
        return false;
    return true;
}

