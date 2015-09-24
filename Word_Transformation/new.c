#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
map<string, vector<string> > graph;
map<string, char> vis;
 
int bfs(string s, string e) {
    vis.clear();
    queue<pair<string, int> > q;
    q.push(make_pair(s, 0));
    vis[s] = 1;
    while (q.size()) {
        pair<string, int> p = q.front();
        q.pop();
        if (!p.first.compare(e))
            return p.second;
        else
            for (int i = 0; i < graph[p.first].size(); ++i)
                if (vis[graph[p.first][i]] != 1) {
                    q.push(make_pair(graph[p.first][i], p.second + 1));
                    vis[graph[p.first][i]] = 1;
                }
    }
    return -1;
}
 
int diff(string s1, string s2) {
    if (s1.length() != s2.length())
        return -1;
    int out = 0;
    for (unsigned int i = 0; i < s1.length(); ++i)
        if (s1[i] != s2[i])
            ++out;
    return out;
}
 
int main() {
    int nCase;
    char line[256], s1[16], s2[16];
    scanf("%d", &nCase);
    while (nCase--) {
        // graph
        while (scanf("%s", line) == 1 && string("*").compare(line))
            graph[string(line)] = vector<string>();
        for (map<string, vector<string> >::iterator i = graph.begin(); i != graph.end(); ++i)
            for (map<string, vector<string> >::iterator j = i; j != graph.end(); ++j)
                if (diff(i->first, j->first) == 1) {
                    graph[i->first].push_back(j->first);
                    graph[j->first].push_back(i->first);
                }
        // cases
        gets(line);
        while (gets(line) && line[0]) {
            sscanf(line, "%s %s", s1, s2);
            printf("%s %s %d\n", s1, s2, bfs(string(s1), string(s2)));
        }
        if (nCase)
            printf("\n");
    }
    return 0;
}
