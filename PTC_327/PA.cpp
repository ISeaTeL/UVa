#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <list>
#include <cctype>
using namespace std;

char ch[100000];

int main() {

    string str = "";
    list<string> L;
    bool done = false;
    while (gets(ch) != NULL) {
        int len = strlen(ch);
        for (int i = 0; i < len; i++) {
            if ((ch[i] >= 'A' && ch[i] <= 'Z')||(ch[i] >= 'a' && ch[i] <= 'z')) {
                str += ch[i];
            }
            else {
                int id = -1;
                list<string>::iterator iter = L.begin();
                for(int i = 0; iter != L.end(); iter++, i++) {
                    if (*iter == str) {
                        id = i;
                        break;
                    }
                }
                if (id == -1) {
                    L.push_front(str);
                    printf("%s", str.c_str());
                    str = "";
                }
                else {
                    printf("%d", id+1);
                    L.erase(iter);
                    L.push_front(str);
                    str = "";
                }

                if (ch[i] == '0') {
                    done = true;
                    break;
                }
                putchar(ch[i]);
            }
        }
        if (done) {
            break;
        }
        putchar(10);
    }
    return 0;
}
