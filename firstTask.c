#include <stdio.h>
#include <string.h>
#define ll long long

struct User {
    char userName[50];
    char passWord[50];
};

struct User users[100]; 
ll usersCnt = 0;

// Function to save user data to a file
void saveUserData() {
    FILE *file = fopen("userdata.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    for (ll i = 0; i < usersCnt; i++) {
        fprintf(file, "%s %s\n", users[i].userName, users[i].passWord);
    }

    fclose(file);
}

// Function to load user data from a file
void loadUserData() {
    FILE *file = fopen("userdata.txt", "r");
    if (file == NULL) {
        return; 
    }

    while (fscanf(file, "%s %s", users[usersCnt].userName, users[usersCnt].passWord) == 2) {
        usersCnt++;
    }

    fclose(file);
}

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

    saveUserData();

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
    loadUserData();

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
