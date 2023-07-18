#include <stdio.h>
#include <string.h>

//defining data structure
typedef struct {
    char name[50];
    char description[100];
} Commodity;
//user registration and login
#define MAX_USERS 100

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS];
int numUsers = 0;

void registerUser(const char* username, const char* password) {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    
    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    users[numUsers++] = newUser;
    
    printf("Registration successful!\n");
}

int loginUser(const char* username, const char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i;  // Return the index of the logged-in user
        }
    }
    
    return -1;  // Return -1 if login fails
}
//implimenting commodity searching
#define MAX_COMMODITIES 100

Commodity commodities[MAX_COMMODITIES];
int numCommodities = 0;

void listCommodity(const char* name, const char* description) {
    if (numCommodities >= MAX_COMMODITIES) {
        printf("Maximum number of commodities reached.\n");
        return;
    }
    
    Commodity newCommodity;
    strcpy(newCommodity.name, name);
    strcpy(newCommodity.description, description);
    commodities[numCommodities++] = newCommodity;
    
    printf("Commodity listed successfully!\n");
}

void searchCommodity(const char* keyword) {
    printf("Search results:\n");
    for (int i = 0; i < numCommodities; i++) {
        if (strstr(commodities[i].name, keyword) != NULL || strstr(commodities[i].description, keyword) != NULL) {
            printf("- %s: %s\n", commodities[i].name, commodities[i].description);
        }
    }
}
//implement the main function

int main() {
    char command[10];

    while (1) {
        printf("\nAvailable commands: register, login, list, search, exit\n");
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "register") == 0) {
            char username[50];
            char password[50];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            registerUser(username, password);
        } 
        else if (strcmp(command, "login") == 0) {
            char username[50];
            char password[50];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            int userId = loginUser(username, password);
            if (userId != -1) {
                printf("Login successful! Welcome, %s.\n", users[userId].username);
            } else {
                printf("Invalid username or password.\n");
            }
        } 
        else if (strcmp(command, "list") == 0) {
            char name[50];
            char description[100];
            printf("Enter commodity name: ");
            scanf("%s", name);
            printf("Enter commodity description: ");
            scanf("%s", description);
            listCommodity(name, description);
        } 
        else if (strcmp(command, "search") == 0) {
            char keyword[50];
            printf("Enter search keyword: ");
            scanf("%s", keyword);
            searchCommodity(keyword);
        } 
        else if (strcmp(command, "exit") == 0) {
            break;
        } 
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

