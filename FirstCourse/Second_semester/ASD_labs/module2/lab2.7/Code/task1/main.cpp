#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Set
{ public:
    vector<int> set;
    Set(int k)
    {
        set.push_back(k); }
};
struct Edge
{
public:
    int v1; int v2; int weight; Edge(int f,int s, int w) {
        v1 = f;
        v2 = s;
        weight = w;
    }
    };
struct DisjointSets
{
public:
    int NumberSets = 0; vector <Set> components; DisjointSets(int num)
    {
        NumberSets = num;
        for(int i = 0; i < num; ++i)
            components.push_back(Set(i));
    }
    int Find(int vertex)
    {
        for(int i = 0; i < NumberSets; ++i)
        {
            for(int j = 0; j <components[i].set.size(); ++j)
                if (vertex == components[i].set[j]) return i; }
    } };
void Print(vector<Edge> res)
{
    cout << " U V Weight" << endl; for(Edge i : res)
        cout<<""<<i.v1+1<<" "<<i.v2+1<<" "<<i.weight<<endl;
}
vector<Edge> Kruskal(vector<Edge> graph, int size) {
    DisjointSets f(size);
    vector<Edge> res;
    for(int i = 0; i < graph.size(); ++i)

    {
        for(int j = 0; j < graph.size(); ++j)
            if(graph[i].weight < graph[j].weight) swap(graph[i], graph[j]);
    }
    int c = 1;
    for(Edge r : graph){
        int res1 = f.Find(r.v1); int res2 = f.Find(r.v2); if( res1 != res2){
            res.emplace_back(r);
            for(int i = 0; i < f.components[res2].set.size(); ++i)
                f.components[res1].set.emplace_back(f.components[res2].set[i]);
            f.components[res2].set.clear();
            cout << "Step " << c << ":" << endl;
            Print(res);
            c++; }
    }
    return res; }
int main() {
    int vert, v1, v2, weight, edge;
    cout << "Enter number of vertex and edges: ";
    cin >> vert >> edge;
    cout << "Enter first vertex, second vertex and weight of the edge: " << endl; vector<Edge> graph;
    for(int i = 0; i < edge; ++i){
        cin >> v1 >> v2 >> weight;
        graph.emplace_back(v1 - 1, v2 - 1, weight); }
    vector<Edge> res;
    res = Kruskal(graph, vert);
    cout << "Kruskal's MST: " << endl; Print(res);
    return 0;
}