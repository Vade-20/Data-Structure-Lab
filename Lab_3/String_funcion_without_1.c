#include <stdio.h>
#include <stdlib.h>

int lenght(char str[]){
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
    
}
char* concatenation(char a[],char b[]){
    int size_a = lenght(a);
    int size_b = lenght(b);
    char * c = (char * )malloc((size_a+size_b)*sizeof(char));
    for (int i = 0 ; i < size_a;i++){
        *(c+i) = a[i];
    }
    for (int j = 0 ; j < size_b;j++){
        *(c+j+size_a) = b[j];
    }
    return c;
}

void compare(char a[],char b[]){
    if (lenght(a) == lenght(b)){
        for (int i = 0 ; i<lenght(a);i++){
            if(a[i] != b[i]){
                printf("False");
                return;
            }
        }
        printf("True");
        return;
    }
    else{
        printf("False");
    }
}

void insert_sub(char str[], char a[], int pos){
    int char_len = lenght(str);
    int a_len = lenght(a);
    for (int i = char_len; i>char_len-a_len;i--){
        str[i+a_len] = str[i];
    }

    for (int i = 0 ; i < a_len ; i++){
        str[i+pos] = a[i];
    }
}

int find_first(char str[],char a[]){
    int str_len = lenght(str);
    int a_len = lenght(a);

    for (int i = 0 ; i < str_len; i++){
        int first = 0;
        if (str[i] == a[0]&& i+a_len <= str_len ){
            first = i;
            for (int j = 0 ; j < a_len ; j++){
                if (str[i+j] != a[j]){
                    break;
                }
            }
            return first;
        }
    }
}
void delete_sub(char str[],char a[]){
    int first = find_first(str,a);
    int a_len = lenght(a);
    for (int i = 0 ; i < lenght(str) ; i++){
        str[first+i] = str[first+i+a_len];
    }
}
int main(){
    char str_1[] = "Hello";
    char str_2[] = "World";
    printf("Length of %s : %d\n",str_1,lenght(str_1));
    char * str_3 = concatenation(str_1,str_2);
    printf("Concatenation of 2 string:");
    for(int i = 0 ; i < (lenght(str_1)+lenght(str_2));i++){
        printf("%c",*(str_3+i));
    }
    printf("\nThe two string %s and %s are equal:",str_1,str_2);
    compare(str_1,str_2);
    insert_sub(str_1,"World",2);
    printf("\n");
    for(int i = 0 ; i < lenght(str_1); i++){
        printf("%c",str_1[i]);
    }
    printf("\n");
    delete_sub(str_1,"World");
        for(int i = 0 ; i < lenght(str_1); i++){
        printf("%c",str_1[i]);
    }

}