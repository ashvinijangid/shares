#include <stdio.h>
#include <string.h> //for string length function
//modify theses for any character
int check_chr(char c) {
    if (c < 123 && c > 96) return 1; // small letter
    if (c > 64 && c < 91) return 1; // Capital letter
    return 0;
}


int check_symbol(char c) {
    if (c < 123 && c > 96 ) return 1; // small letter
    if (c > 64 && c < 91) return 1; // Capital letter
    if (c == 95) return 1; // underscore
    if (c < 58 && c > 48) return 1; // number
    return 0;
}
//-----------------------------------------


int isValid(char s[]) {
    ulong length = strlen(s);
    int ind1 = 0; // global index for email
    if (!check_chr(s[ind1])) return 0; //check if start with only char
    else { // if start with char then check remain
        for (; ind1 < length; ind1++) {
            if (s[ind1] == '@') break; //find first @
            else if (check_symbol(s[ind1])) continue; // check symbols
            else return 0;
        }
        if (!check_chr(s[++ind1])) return 0; // check if after @ there is no number or any other symbol other then char

        for (; ind1 < length; ind1++) {
            if (s[ind1] == '.') break; // find first dot
            else if (check_symbol(s[ind1])) continue; // check symbols
            else return 0;
        }

        if (!check_chr(s[++ind1])) return 0; // check if after . there is no number or any other symbol other then char
        for (; ind1 < length; ind1++) {
            if (s[ind1] == '.') break; // find second dot if dot is not then consume all remaining word
            else if (check_symbol(s[ind1])) continue; // check symbols
            else return 0;
        }
        if (ind1 == length) return 1; //check if all word consumed if true then email is valid and return 1
        if (!check_chr(s[++ind1])) return 0; // check if after . there is no number or any other symbol other then char

        // consume all remaining word
        for (; ind1 < length; ind1++) {
            if (check_symbol(s[ind1])) continue;
            else return 0;
        }
        return 1;
    }
}

int main() {
    char s1[] = "ashvinijangid@gmail.com\0", s2[] = "tami@jce.ac.uk\0";
    if (isValid(s1) == 1) printf("\nEmail 1 - valid.\n");
    else printf("\nEmail 1- wrong.\n");
    if (isValid(s2) == 1) printf("\nEmail 2 - valid.\n");
    else printf("\nEmail 2- wrong.\n");
}
