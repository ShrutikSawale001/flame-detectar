#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Structure to represent an obstacle
struct Obstacle {
    std::string name;
    int flammabilityLevel; // 1-5, where 1 is low and 5 is high
    int distanceFromPump;  // in meters
};

// Function to calculate the seniority of an obstacle
int calculateSeniority(const Obstacle& obstacle) {
    return obstacle.flammabilityLevel * obstacle.distanceFromPump;
}

// Function to compare two obstacles based on their seniority
bool compareObstacles(const Obstacle& a, const Obstacle& b) {
    return calculateSeniority(a) > calculateSeniority(b);
}

// Function to display the menu
void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Add an obstacle\n";
    std::cout << "2. Display obstacles\n";
    std::cout << "3. Sort obstacles by seniority\n";
    std::cout << "4. Exit\n";
}

int main() {
    std::vector<Obstacle> obstacles;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Obstacle obstacle;
                std::cout << "Enter obstacle name: ";
                std::cin.ignore(); // Clear the input buffer
                std::getline(std::cin, obstacle.name);
                std::cout << "Enter flammability level (1-5): ";
                std::cin >> obstacle.flammabilityLevel;
                std::cout << "Enter distance from pump (in meters): ";
                std::cin >> obstacle.distanceFromPump;
                obstacles.push_back(obstacle);
                break;
            }
            case 2: {
                if (obstacles.empty()) {
                    std::cout << "No obstacles added.\n";
                } else {
                    std::cout << "Obstacles:\n";
                    for (const auto& obstacle : obstacles) {
                        std::cout << obstacle.name << ": Flammability Level = "
                                << obstacle.flammabilityLevel
                                << ", Distance from Pump = "
                                << obstacle.distanceFromPump << " meters\n";
                    }
                }
                break;
            }
            case 3: {
                if (obstacles.empty()) {
                    std::cout << "No obstacles added.\n";
                } else {
                    std::sort(obstacles.begin(), obstacles.end(), compareObstacles);
                    std::cout << "Obstacles sorted by seniority:\n";
                    for (const auto& obstacle : obstacles) {
                        std::cout << obstacle.name << ": Flammability Level = "
                                << obstacle.flammabilityLevel
                                << ", Distance from Pump = "
                                << obstacle.distanceFromPump << " meters\n";
                    }
                }
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
