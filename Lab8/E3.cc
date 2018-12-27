#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000

struct node
{
    int c;
    bool fg;
};

struct posit
{
    int x;
    int y;
};

node grid[MAX][MAX];
posit q[MAX];

int main()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < m; ++k)
            {
                scanf("%d", &grid[j][k].c);
                grid[j][k].fg = false;
            }

        int count = 0;
        posit c = {0, 0};
        while(true)
        {
            if(!grid[c.x][c.y].fg)
            {
                int qr = 0, qf = 0;
                q[qr].x = c.x;
                q[qr].y = c.y;
                qr++;
                grid[c.x][c.y].fg = true;
                while(qr != qf)
                {
                    posit nb;
                    nb.x = q[qf].x;
                    nb.y = q[qf].y;
                    ++qf;

                    posit l;
                    if(nb.y != 0) l = {nb.x, nb.y - 1};
                    else l = {nb.x, m - 1};
                    if(!grid[l.x][l.y].fg && grid[l.x][l.y].c == grid[nb.x][nb.y].c)
                    {
                        q[qr].x = l.x;
                        q[qr].y = l.y;
                        qr++;
                        grid[l.x][l.y].fg = true;
                    }

                    posit r;
                    if(nb.y != m - 1) r = {nb.x, nb.y + 1};
                    else r = {nb.x, 0};
                    if(!grid[r.x][r.y].fg && grid[r.x][r.y].c == grid[nb.x][nb.y].c)
                    {
                        q[qr].x = r.x;
                        q[qr].y = r.y;
                        qr++;
                        grid[r.x][r.y].fg = true;
                    }

                    if(nb.x != 0 && !grid[nb.x - 1][nb.y].fg && grid[nb.x - 1][nb.y].c == grid[nb.x][nb.y].c)
                    {
                        q[qr].x = nb.x - 1;
                        q[qr].y = nb.y;
                        qr++;
                        grid[nb.x - 1][nb.y].fg = true;

                    }

                    if(nb.x != n - 1 && !grid[nb.x + 1][nb.y].fg && grid[nb.x + 1][nb.y].c == grid[nb.x][nb.y].c)
                    {
                        q[qr].x = nb.x + 1;
                        q[qr].y = nb.y;
                        qr++;
                        grid[nb.x + 1][nb.y].fg = true;
                    }
                }
                ++count;
            }
            else
            {
                if(c.y != m - 1) ++c.y;
                else
                {
                    ++c.x;
                    c.y = 0;
                }
                if(c.x == n) break;
            }
        }
        printf("%d\n", count);
    }
    #ifdef DEBUG
    system("pause");
    #endif
}
