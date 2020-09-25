#include <bits/stdc++.h>

using namespace std;

char *MyStrCpy(char *dst, char *src) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char *ret = dst;
    while ((*dst++ = *src++) != '\0');
    return ret;
}

int main() {
    char strSrc[] = "Hello World!";
    char strDest[20];
    MyStrCpy(strSrc, strDest);
    cout << "strDest: " << strDest << endl;
    return 0;
}