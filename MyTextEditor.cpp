#include <iostream>
#include <fstream>
#include <sstream>

void createFile();
void openFile();
void editFile();
void saveFile();
void displayFile();

int main(){
    int choice;
    do {
        std::cout << "1. Create a new file\n";
        std::cout << "2. Open an existing file\n";
        std::cout << "3. Edit a file.\n";
        std::cout << "4. Save changes to a file.\n";
        std::cout << "5. Display the content of the file.\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                createFile();
                break;
            case 2:
                openFile();
                break;
            case 3:
                editFile();
                break;
            case 4:
                saveFile();
                break;
            case 5:
                displayFile();
                break;
        }
    } while(choice != 6);

    return 0;
}

void createFile() {
    std::string filename;
    std::cout << "Enter name of file to create: :";
    std::cin >> filename;

    std::ofstream outfile(filename.c_str());

    if (outfile.is_open()) {
        std::cout << "File successfully created.\n";
        outfile.close();
    } else {
        std::cout << "Error creating file.\n";
    }
}