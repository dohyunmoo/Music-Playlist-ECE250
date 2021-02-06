#include <iostream>
#include <string>

#include "Playlist.hpp"

int main()
{
    std::string line;
    Playlist playlist;
    bool error;
    int size;

    while (!std::cin.eof()) {

        std::getline(std::cin, line);

        if (line == "exit\n") {
            break;
        }

        int divider = line.find(" ");
        std::string command = line.substr(0, divider);
        std::string content = line.substr(divider + 1);

        if (command == "m") {
            size = std::stoi(content);
            error = playlist.init(size);

            if (error) {
                std::cout << "success\n";
            }
            else {
                std::cout << "failure\n";
            }
        } else if (command == "i") {

            int pos = content.find(";");
            std::string song_name = content.substr(0, pos);
            std::string artist_name = content.substr(pos + 1);

            error = playlist.add_new_song(song_name, artist_name, size);

            if (error) {
                std::cout << "success\n";
            }
            else {
                std::cout << "can not insert " << song_name << ';' << artist_name << "\n";
            }
        } else if (command == "p") {

            int pos = std::stoi(content);
            if (pos <= size && pos > 0) {
                error = playlist.play(pos);
            }
            else {
                error = false;
            }

            if (!error) {
                std::cout << "can not play " << pos << "\n";
            }
        } else if (command == "e") {

            int pos = std::stoi(content);

            if (pos <= size && pos > 0) {
                error = playlist.erase(pos, size);
            }
            else {
                error = false;
            }

            if (error) {
                std::cout << "success\n";
            }
            else {
                std::cout << "can not erase " << pos << "\n";
            }
        }
    }
    return 0;
}