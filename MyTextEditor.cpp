#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

void createFile();
std::string openFile(std::string fileName);
std::string editFile();
void saveFile(std::string fileName, std::string fileContents);
void displayFile(std::string fileContents);

int main(){
    int choice;
    std::string fileContents;
    std::string fileName;
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
                std::cout << "Enter name of file to open: ";
                std::cin >> fileName;
                fileContents = openFile(fileName);
                break;
            case 3:
                fileContents += editFile();
                break;
            case 4:
                saveFile(fileName, fileContents);
                break;
            case 5:
                displayFile(fileContents);
                break;
        }
    } while(choice != 6);

    return 0;
}

void createFile() {
    std::string filename;
    std::cout << "Enter name of file to create: :";
    std::cin >> filename;

    std::ofstream ofs(filename.c_str());

    if (ofs.is_open()) {
        std::cout << "File successfully created.\n";
        ofs.close();
    } else {
        std::cout << "Error creating file.\n";
    }
}

std::string openFile(std::string fileName) {
    std::cout << "Enter name of file to open: ";
    std::cin >> fileName;
    std::string fileContents = "";

    std::ifstream ifs(fileName.c_str());

    if (!ifs) {
        std::cout << "Error opening file.\n";
    } else {
        std::cout << "File opened successfully.\n";
    }

    std::string line;
    while (std::getline(ifs, line)) {
        fileContents += line;
    }

    ifs.close();
    return fileContents;
}

std::string editFile() {
    int exit = 0;
    std::string text = "";
    std::string temp;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore any leftover newline character

    do {
        std::cout << "Enter text\n";
        getline(std::cin, temp);
        text += temp + "\n";
        std::cout << "Enter 1 to exit, 0 to continue: ";
        std::cin >> exit;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ignore the newline character after the exit input
    } while(exit != 1);

    return text;
}

void saveFile(std::string fileName, std::string fileContents) {
    std::ofstream ofs(fileName.c_str());
    ofs << fileContents;
}

void displayFile(std::string fileContents) {
    std::cout << fileContents << std::endl;
}
