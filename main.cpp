#include <bits/stdc++.h>

using namespace std;
/*
2
10
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 1 1 0 0 1 1 0 0
0 0 1 1 0 0 1 1 0 0
0 0 0 1 1 1 1 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
20
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 */
int T, n;
int mp[105][105];
int sum[105];
int d1[] = {0, 2, 3, 2, 2, 2, 2, 4, 0, 0};
int d2[] = {0, 4, 6, 2, 2, 2, 2, 6, 0, 0};
int d3[] = {0, 4, 4, 2, 4, 2, 4, 4, 0, 0};
int d4[] = {0, 2, 3, 4, 4, 7, 2, 2, 0, 0};
int d5[] = {0, 2, 6, 2, 5, 2, 4, 4, 0, 0};
int d6[] = {0, 4, 2, 2, 5, 4, 4, 4, 0, 0};
int d7[] = {0, 6, 6, 2, 2, 2, 2, 2, 0, 0};
int d8[] = {0, 4, 4, 4, 4, 4, 4, 4, 0, 0};
int d9[] = {0, 4, 4, 4, 5, 2, 2, 4, 0, 0};


int check0() {
    for (int i = n / 10 * 5; i <= n / 10 * 5 + n / 10 * 2 - 1; i++) {
        int num = 0;
        for (int j = 1; j <= n; j++) {
            if (mp[j][i] == 1) num++;
        }
        if (num != n / 10 * 2) return 0;
    }
    return 1;
}

int check1() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d1[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check2() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d2[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check3() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d3[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check4() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d4[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check5() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d5[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check6() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d6[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check7() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d7[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check8() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d8[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}

int check9() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n / 10; j++) {
            v.push_back(d9[i] * n / 10);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sum[i+1] != v[i]) return 0;
    }
    return 1;
}


int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(sum,0,sizeof(sum));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &mp[i][j]);
                sum[i] += mp[i][j];
            }
        }
/*       for (int i=1 ;i<=n ;i++) {
            printf("%d ",sum[i]);
        }
        printf("\n");*/
        if (check0()) printf("0\n");
        else if (check1()) printf("1\n");
        else if (check2()) printf("2\n");
        else if (check3()) printf("3\n");
        else if (check4()) printf("4\n");
        else if (check5()) printf("5\n");
        else if (check6()) printf("6\n");
        else if (check7()) printf("7\n");
        else if (check8()) printf("8\n");
        else  printf("9\n");
    }
    return 0;
}