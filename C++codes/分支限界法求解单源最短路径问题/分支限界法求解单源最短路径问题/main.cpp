#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define    MAXN 100
#define INF 0x3f3f3f3f

int a[MAXN][MAXN];    //存储图
int dist[MAXN], vis[MAXN];    //dist[]点到当前点的距离, vis[]用来判断是否走过当前路径
vector<int> pre[MAXN];    //存储前驱结点
vector<int> ans; //用于存储结果路径
int n, m, s, t;    //n个结点，m条边，s是源点, t为目标点

struct NodeType {
    int vno;
    int length;
    bool operator<(const NodeType& e) const
    {
        return length > e.length;    //length越小越优先出队
    }
};

void Init()
{
    int x, y, len;
    cout << "请依次输入结点个数、边数、源点、目标点" << endl;
    cin >> n >> m >> s >> t;
    memset(dist, INF, sizeof(dist));
    memset(a, INF, sizeof(a));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++)    //建图--有向图
    {
        cin >> x >> y >> len;
        a[x][y] = len;
    }
}

void bfs()
{
    NodeType e, e1;
    queue<NodeType> pqu;
    e.vno = s;
    e.length = 0;
    pqu.push(e);
    dist[s] = 0;

    while (!pqu.empty())
    {
        e = pqu.front();
        pqu.pop();
        for (int j = 0; j < n; j++)
        {
            if (a[e.vno][j] < INF && e.length + a[e.vno][j] < dist[j] && !vis[j])
            {    //剪枝：e.vno到顶点j有边并且路径长度更短
                dist[j] = e.length + a[e.vno][j];
                pre[j].clear();
                pre[j].push_back(e.vno);
                e1.vno = j;    //建立相邻点j的结点e1
                e1.length = dist[j];
                pqu.push(e1);
            }
            else if (a[e.vno][j] < INF && e.length + a[e.vno][j] == dist[j] && !vis[j])
            {
                pre[j].push_back(e.vno);
                e1.vno = j;    //建立相邻点j的结点e1
                e1.length = dist[j];
                pqu.push(e1);
            }
        }

    }

}

void OutPutPath(int i)
{
    for (int j = 0; j < pre[i].size(); j++)
    {
        ans.push_back(pre[i][j]);
        if (pre[i][j] == s)
        {
            for (int k = ans.size() - 1; k >= 0; k--)
            {
                cout << ans[k] << " ";
            }
            cout << "\n";
        }
        OutPutPath(pre[i][j]);    //往下一层
        ans.pop_back();    //删除上个元素
    }
}

void OutPut()
{
    cout << "点" << s << "到" << t << "的最短距离是" << dist[t] << endl;
    cout << "路径为：";
    OutPutPath(t);
}

int main()
{
    Init();
    bfs();
    ans.push_back(t);
    OutPut();
    return 0;
}
/*
6 8 0 5
0 2 10
0 4 30
0 5 60
2 3 50
4 3 20
4 5 60
3 5 10
1 2 4
*/

/*
7 11 0 6
0 1 2
0 2 8
0 3 5
1 2 3
1 4 3
2 5 4
3 5 6
3 6 9
4 5 5
4 6 7
5 6 2
*/