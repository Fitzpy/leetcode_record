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

void *MemCpy(char *dst, char *src, int size) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char *pdst = dst;
    char *psrc = src;
    if ((src < dst) && src + size > dst) {
        pdst += size - 1;
        psrc += size - 1;
        while (size--) {
            *pdst-- = *psrc--;
        }
    } else {
        while (size--) {
            *pdst++ = *psrc++;
        }
    }
    return dst;
}

int main() {
    char strSrc[] = "Hello World!";
    char strDest[20];
    MyStrCpy(strDest,strSrc);
    cout << "strDest: " << strDest << endl;
    return 0;
}