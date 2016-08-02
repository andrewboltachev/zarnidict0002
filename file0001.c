#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#define FILENAME "/home/andrey/docs/zarnidict0001/dicts/chm-rus/marirus.dsl"
#define LENGTH 1000

#define run_test(fn_name)\
    printf("%s\n", #fn_name);\
    fn_name();

struct Article {
    char * name;
};

struct Header {
    char * s;
};

struct Body {
    struct Article * articles[1]; // http://stackoverflow.com/a/247040
};

struct Dictionary {
    struct Header * header;
    struct Body * body;
};


void f1() {
//printf("%d\n", 42);
    assert(0 == 1 - 1);
}

void f2() {
    assert(0 == 1 - 2);
}

int main() {
    setlocale(LC_CTYPE,"ru_RU.UTF-8");   // put your locale here
    char ** lines;
    FILE *fp;
    fp = fopen(FILENAME, "r");
    wchar_t s[LENGTH];
    /*while (fgetws(s, LENGTH, fp) != NULL) {
        wprintf(L"%s", s);
    }*/
    wint_t wc;
    /*do {
        wc = fgetwc(fp);
        fputwc(wc, stdout);
    } while (wc != WEOF);
    */
    fclose(fp);
    run_test(f1);
    return 0;
}
