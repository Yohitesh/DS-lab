char* removeDuplicates(char* s) {
 int n = strlen(s);
 char* stack = (char*)malloc(sizeof(char) * (n + 1));
 if (!stack) return NULL;
 int i = 0;
 for (int j = 0; j < n; j++) {
 char c = s[j];
 if (i && stack[i - 1] == c) {
 i--;
 } else {
 stack[i++] = c;
 }
 }
 stack[i] = '\0';
 return stack;
}