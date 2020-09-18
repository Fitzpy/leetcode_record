#include <bits/stdc++.h>

using namespace std;

class String {
public:
    String(const char *str);

    String(const String &s);

    String &operator=(const String &s);

    ~String();

private:
    char *data;
};

String::String(const char *str) {
    if (str == NULL) {
        data = new char[1];
        *data = '\0';
    } else {
        int len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
}

String::String(const String &s) {
    int len = strlen(s.data);
    if (len == 0) {
        data = new char[1];
        *data = '\0';
    } else {
        data = new char[len + 1];
        strcpy(data, s.data);
    }
}

String &String::operator=(const String &s) {
    //检查是否是自赋值
    if (this == &s) {
        return *this;
    }
    delete[]data;
    int len = strlen(s.data);
    data = new char[len + 1];
    strcpy(data, s.data);
    return *this;
}

String::~String() {
    delete[]data;
}

int main() {
    return 0;
}