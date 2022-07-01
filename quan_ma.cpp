#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct ViTri{
    int x;
    int y;
};
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string st,en;
        cin >> st >> en;
        int a[9][9];
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                a[i][j] = 0;
            }
        }
        ViTri b, c;
        b.x = 1 + int(st[0] - 'a');
        b.y = int(st[1] - '0');
        c.x = 1 + int(en[0] - 'a');
        c.y = int(en[1] - '0');
        queue<ViTri>q=queue<ViTri>();
        q.push(b);
        while(!q.empty())
        {
            ViTri v = q.front();
            q.pop();
            if(v.x == c.x && v.y == c.y) break;
            ViTri u;
            if(v.x - 2 >= 1 && v.y - 1 >= 1)
            {
                u.x = v.x - 2;
                u.y = v.y - 1;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x - 2 >= 1 && v.y + 1 <= 8)
            {
                u.x = v.x - 2;
                u.y = v.y + 1;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x + 2 <= 8 && v.y - 1 >= 1)
            {
                u.x = v.x + 2;
                u.y = v.y - 1;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x + 2 <= 8 && v.y + 1 <= 8)
            {
                u.x = v.x + 2;
                u.y = v.y + 1;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x - 1 >=1 && v.y + 2 <= 8)
            {
                u.x = v.x - 1;
                u.y = v.y + 2;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x - 1 >= 1 && v.y - 2 >= 1)
            {
                u.x = v.x - 1;
                u.y = v.y - 2;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x + 1 <= 8 && v.y + 2 <= 8)
            {
                u.x = v.x + 1;
                u.y = v.y + 2;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
            if(v.x + 1 <= 8 && v.y - 2 >= 1)
            {
                u.x = v.x + 1;
                u.y = v.y - 2;
                q.push(u);
                if(a[u.y][u.x] == 0)
                {
                    a[u.y][u.x] = a[v.y][v.x] + 1;
                }
                else{
                    a[u.y][u.x] = min(a[u.y][u.x], a[v.y][v.x] + 1);
                }
            }
        }
        cout << a[c.y][c.x] << endl;
    }
    return 0;
}