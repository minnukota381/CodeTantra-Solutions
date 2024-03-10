#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 300
#define MAX_LENGTH 50

int adj[26][26], inDegree[26];
int visited[26], isCycle;

void dfs(int u) {
    visited[u] = 1;
    for (int v = 0; v < 26; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                dfs(v);
            } else if (visited[v] == 1) {
                isCycle = 1; 
                return;
            }
        }
    }
    visited[u] = 2;
}
int main() {
    int N, K;
    char words[MAX_WORDS][MAX_LENGTH + 1];
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%s", words[i]);
    }
    memset(adj, 0, sizeof(adj));
    memset(inDegree, 0, sizeof(inDegree));

    for (int i = 0; i < N - 1; i++) {
        char *word1 = words[i];
        char *word2 = words[i + 1];
        int j = 0;
        while (word1[j] && word2[j] && word1[j] == word2[j]) {
            j++;
        }
        if (word1[j] && word2[j]) {
            adj[word1[j] - 'a'][word2[j] - 'a'] = 1;
            inDegree[word2[j] - 'a']++;
        }
    }
    memset(visited, 0, sizeof(visited));
    isCycle = 0;
    for (int i = 0; i < 26; i++) {
        if (!visited[i] && inDegree[i] > 0) {
            dfs(i);
        }
    }
    if (isCycle) {
        printf("0\n");
    } else {
        printf("1\n");
    }
    return 0;
}
