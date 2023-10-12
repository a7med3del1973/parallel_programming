#include <stdio.h>
#include <string.h>
int main() {
 char userName[50]; 
char password[50];

    printf("\n Enter your username : ");
    scanf("%s", userName); 
    printf("\n Enter your password : ");
    scanf("%s", password);

    if (strcmp(userName, "Ahmed") == 0) { 
        if (strcmp(password, "1973") == 0) {
            printf("Login Successfully \n");
        } else {
            printf("\n Wrong Password \n"); 
        }
    } else {
        printf("\n User Doesn't Exist \n"); 
    }

    getchar(); 

    return 0;
}