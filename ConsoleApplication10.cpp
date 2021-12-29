#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

vector<vector<int>> graph;
vector<int> used;
vector<int> path;


int dfs(int v, int start, int &count) {
    if (used[v]) {
        if (v == start) {
            for (int i = 0; i < path.size(); ++i)
            {
                cout << path[i] + 1 << " "; 
            }
            cout << v + 1 << endl; 
            count++;
        }
        return count;
    }

    used[v] = 1;

    path.push_back(v);
    for (int i = 0; i < graph[v].size(); ++i)
        if (graph[v][i] == 1)
            dfs(i, start, count);

    used[v] = 0;

    path.pop_back();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    graph.push_back({ 0, 1, 1, 0, 0 }); //1
    graph.push_back({ 0, 0, 1, 0, 1 }); //2
    graph.push_back({ 0, 0, 0, 1, 0 }); //3
    graph.push_back({ 0, 0, 0, 0, 1 }); //4
    graph.push_back({ 1, 0, 0, 0, 0 }); //5

    int count = 0;


    for (int i = 0; i < graph[0].size(); i++) {
        used.resize(graph[0].size(), 0);
        dfs(i, i, count);
    }
    cout <<"Всего вариантов обхода: " <<count;
    return 0;
}
