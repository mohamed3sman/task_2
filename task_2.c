#include <stdio.h>
#include <string.h>

// Define a union to hold either an integer or a character array
union Flag {
    int active;
    char status[10];
};

// Define a struct to hold user information along with the flag
struct User {
    char username[50];
    char password[50];
    union Flag userFlag;
};

// Function to register a new user
void registerUser() {
    struct User newUser;

    printf("Enter a username: ");
    scanf("%s", newUser.username);

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    printf("Set user flag (true/1 or false/0): ");
    scanf("%s", newUser.userFlag.status);

    // Here you can save the user information to a file or database
    // For simplicity, let's just print them for now
    printf("Registration successful! Username: %s, Password: %s, Flag: %s\n",
           newUser.username, newUser.password, newUser.userFlag.status);
}

// Function to login
void loginUser() {
    struct User enteredUser;
    struct User storedUser;

    // In a real system, you'd read these from a file or database
    strcpy(storedUser.username, "exampleUser");
    strcpy(storedUser.password, "examplePassword");
    storedUser.userFlag.active = 1; // Set a default value for demonstration purposes

    printf("Enter your username: ");
    scanf("%s", enteredUser.username);

    printf("Enter your password: ");
    scanf("%s", enteredUser.password);

    // Check if the entered credentials match the stored ones and the user is active
    if (strcmp(enteredUser.username, storedUser.username) == 0 &&
        strcmp(enteredUser.password, storedUser.password) == 0 &&
        storedUser.userFlag.active) {
        printf("Login successful!\n");
    } else {
        printf("Login failed. Incorrect username, password, or user inactive.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}