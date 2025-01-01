char* removeDigit(char* number, char digit){
int n = strlen(number);
static char result[100];
int maxIndex = -1;
for(i=0;i<n;i++){
if(number[i]==digit){
char temp[100];
int k = 0;
for(j=0;j<n;j++){
if(j!=i){
temp[k++]=number[j];
}
}
temp[k] = ‘\0’;
if(maxIndex==-1 || strcmp(temp,result)>0){
strcpy(result,temp);
maxIndex=I;
}
}
}
return result;
}