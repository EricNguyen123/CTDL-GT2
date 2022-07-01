#include<iostream>
#include<queue>
using namespace std;
struct thanhphan
{
    int a;
    int b;
    string c;
};
struct Node
{
    int x;
    Node *right;
    Node *lift;
} typedef *Tree;
Tree Tao(int x)
{
    Tree res;
    res = new Node;
    res->x = x;
    res->lift = res->right = NULL;
    return res;
}
void dungCay(Tree &A, thanhphan b)
{
    if(A != NULL)
    {
        if(A->x == b.a)
        {
            if(b.c == "R")
            {
                A->right = Tao(b.b);
            }
            else{
                A->lift = Tao(b.b);
            }
        }
        dungCay(A->lift, b);
        dungCay(A->right, b);
    }
}
void in(Tree T)
{
    queue<Tree>q;
    q.push(T);
    Tree top;
    while(!q.empty())
    {
        top = q.front();
        cout << top->x << " ";
        q.pop();
        if(top->lift != NULL) q.push(top->lift);
        if(top->right != NULL) q.push(top->right);
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        thanhphan tp[n];
        for(int i = 0; i < n; i++)
        {
            cin >> tp[i].a >> tp[i].b >> tp[i].c;
        }
        Tree T;
        T = Tao(tp[0].a);
        dungCay(T, tp[0]);
        for(int i = 1; i < n; i++)
        {
            dungCay(T, tp[i]);
        }
        in(T);
        cout << endl;
    }
    return 0;
}