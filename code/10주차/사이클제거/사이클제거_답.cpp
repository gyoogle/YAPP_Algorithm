#include <vector>
#define N 5001
using namespace std;

int c[N], d[N], n, m, k;
vector<int> e[N];
pair<int, int> dfs(int i, int p) {
    int a=0, b=0, f=0;
    bool ok=true;
    d[i]=d[p]+1;
    for(int j : e[i]) if(j!=p) {
        if(!d[j]) {
            auto[x, y]=dfs(j, i);
            ok&=x==0 && y<2;
            a+=x, b+=y;
        }
        else if(d[j]<d[i])
            b++, f++, c[j]++;
    }
    if((ok || (a==0 && b-f-c[i]<2)) && a+b==m-n+1)
        k+=i;
    return {a+c[i], b-c[i]};
}
int solution(int nodes, vector<vector<int>> edges) {
    n=nodes; m=edges.size();
    for(const auto& x : edges)
        e[x[0]].push_back(x[1]),
        e[x[1]].push_back(x[0]);
    dfs(1, 1);
    return k;
}