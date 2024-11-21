#include <stdio.h>
#define INF 999999
#define V 4

int tsp(int graph[V][V], int mask, int pos, int dp[V][1 << V]) {
    if (mask == (1 << V) - 1) return graph[pos][0];

    if (dp[pos][mask] != -1) return dp[pos][mask];

    int ans = INF;
    for (int city = 0; city < V; city++) {
        if (!(mask & (1 << city))) {
            int cost = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            ans = (cost < ans) ? cost : ans;
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    int dp[V][1 << V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (1 << V); j++) dp[i][j] = -1;
    }

    printf("Minimum cost of TSP: %d\n", tsp(graph, 1, 0, dp));
    return 0;
}
