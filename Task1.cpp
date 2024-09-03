#include <iostream>
#include <string>

class Game {
public:
    void start() {
        std::cout << "Welcome to the Adventure Game!\n";
        std::cout << "Your goal is to navigate through rooms and collect treasure.\n";
        playerScore = 0;
        currentRoom = 1;
        gameLoop();
    }

private:
    int playerScore;
    int currentRoom;

    void gameLoop() {
        while (true) {
            displayRoom();
            std::string action;
            std::cout << "What would you like to do? (move/search/exit): ";
            std::cin >> action;

            if (action == "move") {
                move();
            } else if (action == "search") {
                search();
            } else if (action == "exit") {
                std::cout << "Thanks for playing! Your final score is: " << playerScore << "\n";
                break;
            } else {
                std::cout << "Invalid action! Please choose again.\n";
            }
        }
    }

    void displayRoom() {
        std::cout << "You are in room " << currentRoom << ".\n";
    }

    void move() {
        std::cout << "Which direction would you like to go? (left/right/forward): ";
        std::string direction;
        std::cin >> direction;

        if (direction == "left" || direction == "right" || direction == "forward") {
            currentRoom++;
            std::cout << "You move to the next room.\n";
        } else {
            std::cout << "Invalid direction! You stay in the same room.\n";
        }
    }

    void search() {
        if (currentRoom % 3 == 0) { // Every third room has treasure
            std::cout << "You found treasure in this room! You gain 10 points.\n";
            playerScore += 10;
        } else {
            std::cout << "There is nothing to find in this room.\n";
        }
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}
