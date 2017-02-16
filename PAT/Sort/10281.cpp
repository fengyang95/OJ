/*accept*/
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 100001;
struct NODE {
    int no;
    char name[10];
    int score;
}node[maxn];
int c;
int cmp1(NODE a, NODE b) {
    if(c == 1)
        return a.no < b.no;
    else if(c == 2)
        return strcmp(a.name, b.name) <= 0;
    else
        return a.score <= b.score;
}
int main() {
    int n;
    scanf("%d%d", &n, &c);
    for(int i = 0; i < n; i++) {
        scanf("%d %s %d", &node[i].no, node[i].name, &node[i].score);
    }
    sort(node, node + n, cmp1);
    for(int i = 0; i < n; i++) {
        printf("%06d %s %d\n", node[i].no, node[i].name, node[i].score);
    }
    return 0;
}