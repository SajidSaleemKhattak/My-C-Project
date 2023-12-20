#include <iostream>
#include <vector>
#include <stdexcept> // for std::runtime_error
#include <limits>    // for std::numeric_limits

struct UserData {
    std::string username;
    std::string password;
    std::string name;
    double money;
};

std::vector<UserData> userDatabase;

void showMainMenu();
void handleLogin();
void handleCreateAccount();
void showUserMenu(const UserData& user);
void sendMoney(const UserData& sender, const std::string& recipient, double amount);
void requestMoney(const UserData& requester, const std::string& sender, double amount);

int main() {
    showMainMenu();
    return 0;
}

void showMainMenu() {
    int choice;
    std::cout << "1) Create Account\n2) Log-in\n3) Exit\nChoose an option: ";

    try {
        std::cin >> choice;

        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input. Please enter a number.");
        }

        switch (choice) {
            case 1:
                handleCreateAccount();
                break;
            case 2:
                handleLogin();
                break;
            case 3:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice\n";
                showMainMenu();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        showMainMenu();
    }
}

void handleLogin() {
    try {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input for username.");
        }

        std::cout << "Enter password: ";
        std::cin >> password;
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input for password.");
        }

        if (username == "sajidsaleem" && password == "sajid09@") {
            UserData currentUser;
            currentUser.username = "sajidsaleem";
            currentUser.name = "Sajid Saleem";
            currentUser.money = 1000.0;

            showUserMenu(currentUser);
        } else {
            std::cout << "Wrong credentials\n";
            showMainMenu();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        showMainMenu();
    }
}

void handleCreateAccount() {
    try {
        std::string username, password;
        std::cout << "Enter username: ";
        std::cin >> username;
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input for username.");
        }

        std::cout << "Enter password: ";
        std::cin >> password;
        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input for password.");
        }

        if (username == "sajidsaleem" && password == "sajid09@") {
            std::cout << "Account already exists\n";
            showMainMenu();
        } else {
            UserData newUser;
            newUser.username = username;
            newUser.password = password;
            newUser.name = "New User";
            newUser.money = 0.0;
            userDatabase.push_back(newUser);

            std::cout << "Account created successfully\n";
            showMainMenu();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        showMainMenu();
    }
}

void showUserMenu(const UserData& user) {
    try {
        int choice;
        std::cout << "\nWelcome, " << user.name << "!\n";
        std::cout << "Money: " << user.money << "\n";
        std::cout << "1) Send Money\n2) Request Money\n3) Back\n4) Exit\nChoose an option: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input. Please enter a number.");
        }

        switch (choice) {
            case 1: {
                std::string recipient;
                double amount;
                std::cout << "Enter recipient username: ";
                std::cin >> recipient;

                if (std::cin.fail()) {
                    throw std::runtime_error("Invalid input for recipient username.");
                }

                std::cout << "Enter amount: ";
                std::cin >> amount;

                if (std::cin.fail()) {
                    throw std::runtime_error("Invalid input for amount.");
                }

                sendMoney(user, recipient, amount);
                break;
            }
            case 2: {
                std::string sender;
                double amount;
                std::cout << "Enter sender username: ";
                std::cin >> sender;

                if (std::cin.fail()) {
                    throw std::runtime_error("Invalid input for sender username.");
                }

                std::cout << "Enter amount: ";
                std::cin >> amount;

                if (std::cin.fail()) {
                    throw std::runtime_error("Invalid input for amount.");
                }

                requestMoney(user, sender, amount);
                break;
            }
            case 3:
                showMainMenu();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice\n";
                showUserMenu(user);
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        showUserMenu(user);
    }
}

void sendMoney(const UserData& sender, const std::string& recipient, double amount) {
    // Implement sending money logic here
    std::cout << "Money sent successfully\n";
    showUserMenu(sender);
}

void requestMoney(const UserData& requester, const std::string& sender, double amount) {
    // Implement money request logic here
    std::cout << "Money request sent successfully\n";
    showUserMenu(requester);
}

