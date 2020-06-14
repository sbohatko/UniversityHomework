#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100, INF = 10000000;

struct Edge
{
public:
    int v1; int v2; int weight; Edge(int a,int b, int c){
        v1 = a;
        v2 = b; weight = c;
    }
};
int n, u, v;
vector <int> included, g[MAXN], w[MAXN]; vector <bool> used(MAXN, false);
vector <Edge> res;
void Print(vector<Edge> res)
{
    cout << " U V Weight" << endl;
    for(Edge i : res)
        cout<<""<<i.v1+1<<" " <<i.v2+1<<" "<<i.weight<<endl; }
void Prim() {
    int c = 0;
    used[0] = true; included.push_back(0);
    for (int i = 1; i < n; i++) {
        int minWeight = INF, minTop;
        for (int j = 0; j < included.size(); j++) {
            int cur = included[j];
            for (int k = 0; k < g[cur].size(); k++) {
                int next = g[cur][k];
                if (!used[next] && w[cur][k] < minWeight)
                {
                    minWeight = w[cur][k]; u = cur;
                    v = next;
                    minTop = next;
                }
            }
        }
        res.emplace_back(u, v, minWeight); used[minTop] = true; included.push_back(minTop);
        cout << "Step " << c << ":" << endl; Print(res);
        c++;
    }
}
int main(){
    int m, v1, v2,
            weight;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    cout << "Enter first vertex, second vertex and edge weight:" << endl;
    for (int i = 0; i < m; i++){
     cin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        g[v1].push_back(v2);
        w[v1].push_back(weight);
        g[v2].push_back(v1);
        w[v2].push_back(weight);
    }
    Prim();
    cout << "Prim's MST:" << endl; Print(res);
}
