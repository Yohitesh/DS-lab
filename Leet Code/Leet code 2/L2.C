void backspace(const char* s, char* result) {
int index = 0;
for (int i = 0; s[i] != '\0'; i++) {
if (s[i] != '#') {
result[index++] = s[i];
} else if (index > 0) {
index--;
}
}
result[index] = '\0';
}
bool backspaceCompare(char* s, char* t) {
char resultS[1000];
char resultT[1000];
backspace(s, resultS);
backspace(t, resultT);
return strcmp(resultS, resultT) == 0;
}
