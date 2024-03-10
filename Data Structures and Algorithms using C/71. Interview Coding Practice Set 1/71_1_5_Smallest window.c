#include <stdio.h>
#include <string.h>
#include <limits.h>  
#include <stdlib.h> 

#define MAX_CHARS 256

char* smallestWindow(char* str, char* pat) {
    int len1 = strlen(str);
    int len2 = strlen(pat);

    if (len1 < len2) {
        return "-1";
    }

    int hash_pat[MAX_CHARS] = {0};
    int hash_str[MAX_CHARS] = {0};

    for (int i = 0; i < len2; i++) {
        hash_pat[pat[i]]++;
    }

    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    for (int j = 0; j < len1; j++) {
        hash_str[str[j]]++;

        if (hash_pat[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]]) {
            count++;
        }

        if (count == len2) {
            while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0) {
                if (hash_str[str[start]] > hash_pat[str[start]]) {
                    hash_str[str[start]]--;
                }
                start++;
            }

            int window_len = j - start + 1;
            if (min_len > window_len) {
                min_len = window_len;
                start_index = start;
            }
        }
    }

    if (start_index == -1) {
        return "-1";
    }

    char* result = (char*)malloc((min_len + 1) * sizeof(char));
    strncpy(result, str + start_index, min_len);
    result[min_len] = '\0';
    return result;
}

int main() {
    char S[100001], P[100001];
    scanf("%s", S);
    scanf("%s", P);
    char* result = smallestWindow(S, P);
    printf("%s\n", result);
    return 0;
}
