#include <iostream>
#include <fstream>
#include <string>

void signUp() {
    std::string username, password;
    std::cout << "Sign Up\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::ofstream outFile("credentials.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << "\n";
        outFile.close();
        std::cout << "Sign up successful!\n";
    } else {
        std::cout << "Error opening file.\n";
    }
}

void signIn() {
    std::string username, password;
    std::cout << "Sign In\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::ifstream inFile("credentials.txt");
    if (inFile.is_open()) {
        std::string storedUsername, storedPassword;
        bool found = false;
        while (inFile >> storedUsername >> storedPassword) {
            if (username == storedUsername && password == storedPassword) {
                found = true;
                break;
            }
        }
        inFile.close();
        if (found) {
            std::cout << "Account Signed In Successfully!\n";
        } else {
            std::cout << "Invalid credentials.\n";
        }
    } else {
        std::cout << "Error opening file.\n";
    }
}

int main() {
    int choice;
    do {
        std::cout << "Welcome!\n";
        std::cout << "1. Sign Up\n";
        std::cout << "2. Sign In\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                signIn();
                break;
            case 3:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
            
