#include <stdio.h>

// Write all player attributes with a struct
struct Player {
    int x;
    int y;
    int health;
    int gold;
    int key;
};

// Write a function to display the 5x5 grid
void gameMap(char map[5][5], struct Player player) {
    printf("\n");

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {

            if (player.x == row && player.y == col) {
                printf(" P ");
            } else {
                printf(" %c ", map[row][col]);
            }
        }

        printf("\n");
    }
}

int main() {

    // Create a 5x5 map with empty tiles
    char map[5][5] = {
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'}
    };

    // Inserting attribute information into the player struct
    struct Player player = {2, 2, 100, 0, 0};

    // Controls the game loop
    int gameRunning = 1;

    // Stores player's menu choice
    int choice;

    // Game title
    printf("=======================================================\n");
    printf("                    TREASURE HUNT\n");
    printf("=======================================================\n");

    printf("Welcome to the Adventure!\n");
    printf("Objective: Collect min. 50 gold to find the key,\n");
    printf("then open the Treasure Door\n");

    // Main game loop
    while (gameRunning) {

        // Display map
        gameMap(map, player);

        // Display key information
        char *keyInformation;

        if (player.key == 1) {
            keyInformation = "Yes";
        } else {
            keyInformation = "None";
        }

        // Display player information
        printf("\nPosition : (%d, %d)\n", player.x, player.y);
        printf("Health: %d | Gold: %d | Key: %s\n",
            player.health,
            player.gold,
            keyInformation);

        // Display the game menu
        printf("\nWhat would you like to do?\n");
        printf("1. Move North\n");
        printf("2. Move South\n");
        printf("3. Move West\n");
        printf("4. Move East\n");
        printf("5. Save\n");
        printf("6. Load\n");
        printf("7. History\n");
        printf("8. Quit\n");

        printf("\nYour choice: ");
        scanf("%d", &choice);

        // Process player's choice
        switch (choice) {

            case 1: // Move North
                if (player.x > 0) {
                    player.x--;
                } else {
                    printf("\nYou cannot move further North!\n");
                }
                break;

            case 2: // Move South
                if (player.x < 4) {
                    player.x++;
                } else {
                    printf("\nYou cannot move further South!\n");
                }
                break;

            case 3: // Move West
                if (player.y > 0) {
                    player.y--;
                } else {
                    printf("\nYou cannot move further West!\n");
                }
                break;

            case 4: // Move East
                if (player.y < 4) {
                    player.y++;
                } else {
                    printf("\nYou cannot move further East!\n");
                }
                break;

            case 5: // Save
                printf("\nSave feature is not implemented yet.\n");
                break;

            case 6: // Load
                printf("\nLoad feature is not implemented yet.\n");
                break;

            case 7: // History
                printf("\nHistory feature is not implemented yet.\n");
                break;

            case 8: // Quit
                gameRunning = 0;
                printf("\nThank you for playing!\n");
                break;

            default:
                printf("\nInvalid choice! Please select from 1 to 8.\n");
                break;
        }
    }

    return 0;
}