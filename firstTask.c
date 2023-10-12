#include <stdio.h>
#include <string.h>
#define ll long long

struct User {
    char userName[50];
    char passWord[50];
};

struct User users[100];
ll usersCnt = 0;

void userRegister() {
    if (usersCnt >= 100) {
        printf("This form is full... Contact the owner for more information.\n");
        return;
    }

    printf("\nEnter your username: ");
    scanf("%s", users[usersCnt].userName);
    printf("\nEnter your password: ");
    scanf("%s", users[usersCnt].passWord);
    usersCnt++;

    printf("Registered successfully\n");
}

void userLogin() {
    char username[50];
    char password[50];
    printf("\nEnter your username: ");
    scanf("%s", username);
    printf("\nEnter your password: ");
    scanf("%s", password);

    for (ll i = 0; i < usersCnt; i++) {
        if (strcmp(users[i].userName, username) == 0 && strcmp(users[i].passWord, password) == 0) {
            printf("Login Successfully\n");
            return;
        }
    }
    printf("Something went wrong, try again\n");
}

int main() {
    printf("Welcome, sir\nPress 1 to register\nPress 2 to login\n");
    ll choesed = 0;
    scanf("%lld", &choesed);

    if (choesed == 1) {
        userRegister();
    } else if (choesed == 2) {
        userLogin();
    }

    getchar();
    return 0;
}
