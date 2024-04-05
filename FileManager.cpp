//Basic File Manager in C++
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

void listDirectoryContents(const std::string &path) {
    for(const auto& entry: fs::directory_iterator(path)) {
        std::cout << entry.path().filename().string() << std::endl;

    }
}

void viewFile(const std::string& filePath){
    std::ifstream file(filePath);
    if(file.is_open()) {
        std::string line;
        while(std::getline(file,line)){
            std::cout << line << std::endl;
        }
        file.close();
    } else{
        std::cerr <<"Unable to open file: "<< filePath << std:: endl;
    }
}

void createDirectory(const std::string& dirPath) {
    if(!fs::create_directory(dirPath)){
        std::cerr << "Failed to create directory: " << dirPath << std::endl;

    }
}

void copyFile(const std::string& source, const std::string& destination){
    fs::copy(source,destination, fs::copy_options::overwrite_existing);
}

void moveFile(const std::string& source,const std:: string& destination){
    fs::rename(source, destination);
}


int main(){
    std::string command;

    std::cout<< "********************Welcome to Basic File Manager!*********************"<<std::endl;

    while(true){
        std::cout<< "Enter a command(list,view<filename>,create <dirname>, copy <source> <destination>, move <source> <destination>, exit): ";
        std::getline(std::cin,command);

        std::istringstream iss(command);
        std::string action;
        iss >> action;

        if(action == "list"){
            std::string path;
            iss >> path;
            listDirectoryContents(path);
        } else if (action == "view"){
            std::string filename;
            iss >>filename;
            viewFile(filename);
        } else if (action == "create"){
            std::string dirname;
            iss >>dirname;
            createDirectory(dirname);
        } else if (action == "copy"){
            std::string source, destination;
            iss >> source>>destination;
            copyFile( source,destination);
        } else if (action == "move"){
            std::string  source, destination;
            iss >> source>>destination;
            moveFile( source,destination);
        } else if (action == "exist"){
            break;
        } else {
            std::cerr << "Invalid command!" << std::endl;
        }
    }

    std::cout <<"Existing Basic File manager. goodbye!" << std::endl;
    return 0;
}