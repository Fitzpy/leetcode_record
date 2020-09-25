#include <bits/stdc++.h>

using namespace std;


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

char *MyStrCpy(char *dst, char *src) {
    if (dst == NULL || src == NULL) {
        return NULL;
    }
    char *pdst = dst;
    char *psrc = src;
    int len = strlen(src)+1; //¥¶¿Ì'\0'
    if (src < dst && src + len > dst) {
        pdst += len - 1;
        psrc += len - 1;
        while (len--) {
            *pdst-- = *psrc--;
        }
    } else {
        while ((*pdst++ = *psrc++) != '\0');
    }
    return pdst;
}


int main() {
    char strSrc[] = "Hello World!";
    char strDest[20];
    strcpy(strDest, strSrc);
    cout << "strDest: " << strDest << endl;
    return 0;
}