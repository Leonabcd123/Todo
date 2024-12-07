#include <iostream>
#include <fstream>
#include <vector>
#include <limits>



int main() {
    std::fstream list;
    char user;
    std::string add;
    std::vector<std::string> todo;
    std::string line;
    bool running = true;

    std::cout << "Welcome To My To-Do List!\n";

    while (running){
        std::cout << "What Would You Like To Do?\n";
        std::cout << "1. Add (A)\n";
        std::cout << "2. View (V)\n";
        std::cout << "3. Quit (Q)\n";
        std::cin >> user;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        user = toupper(user);

        switch(user){
            
            case 'A':
                list.open("Todos.txt", std::ios::app);
                std::cout << "Type What You Want To Do: ";
                std::getline(std::cin, add);
                list << add << '\n';
                list.close();
                break;

            case 'V':
                todo.clear();
                list.open("Todos.txt");

                while (std::getline(list, line)) {

                    if (!line.empty()) {

                        todo.push_back(line);

                    }
                }

                list.close();

                for (int i = 0; i < todo.size(); i++) {

                    if (!todo[i].empty()) {

                        std::cout << i + 1 << ". " << todo[i] << '\n';
                    }

                    std::cout << "******************************\n";

                    }

                    list.close();
                    break;
            case 'Q':
                running = false;
                break;

            default:
                std::cout << "Please Enter A Valid Letter (A/V/Q)\n";
        }

    }

    std::cout << "Thanks For Using My To-Do List!\n";

    return 0;
}