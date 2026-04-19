#include <stdio.h>
#define LM 100005
 
inline int min(int x, int y) { return x < y ? x : y; }
int N, arr[LM], brr[LM], ans = LM * 2;
int cnt[4], order[4], check[4];
 
int calc() {
    int i, j, k = 0, pos[4][4] = { {0} }, cnt1 = 0, cnt2 = 0;
    for (i = 1; i <= 3; i++) {
        for (j = 0; j < cnt[order[i]]; j++) {
            brr[k++] = order[i];
        }
    }
 
    for (i = 0; i < N; i++) {
        pos[brr[i]][arr[i]]++;
    }
 
    for (i = 1; i < 3; i++) {
        for (j = i + 1; j <= 3; j++) {
            k = min(pos[i][j], pos[j][i]);
            cnt1 += k;
            cnt2 += pos[i][j] + pos[j][i] - (k * 2);
        }
    }
    return cnt1 + cnt2 / 3 * 2;
}
 
void DFS(int step) {
    if (step > 3) {
        ans = min(ans, calc());
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (check[i]) continue;
        check[i] = 1;
        order[step] = i;
        DFS(step + 1);
        check[i] = 0;
    }
}
 
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
 
 
    DFS(1);
    printf("%d\n", ans);
    return 0;
}