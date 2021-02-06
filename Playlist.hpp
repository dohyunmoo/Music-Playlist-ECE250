#include <iostream>
#include "Song.hpp"

class Playlist {
public:
	Song* playlist;

	bool init(int n) {
		playlist = new Song[n];

		return true;
	}

	bool add_new_song(std::string sn, std::string an, int size) {
		
		int i = 0;
		while (i < size && playlist[i].present == true) {
			int j = 0;

			while (j < playlist[i].song_name.length() && j < sn.length() && std::tolower(playlist[i].song_name[j]) == std::tolower(sn[j])) {
				j++;
			}
			
			if (j == playlist[i].song_name.length() && j == sn.length()) {
				int k = 0;

				while (k < playlist[i].artist_name.length() && k < an.length() && std::tolower(playlist[i].artist_name[k]) == std::tolower(an[k])) {
					k++;
				}

				if (k == playlist[i].artist_name.length() && k == an.length()) {
					return false;
				}
			}

			i++;
		}

		if (i < size) {
			playlist[i].song_name = sn;
			playlist[i].artist_name = an;
			playlist[i].present = true;
		}
		else {
			return false;
		}

		return true;
	}

	bool play(int n) {

		if (playlist[n - 1].present == true) {
			std::cout << "played " << n << ' ' << playlist[n - 1].song_name << ';' << playlist[n - 1].artist_name << "\n";
			return true;
		}
		return false;
	}

	bool erase(int n, int size) {
		if (playlist[n - 1].present == true) {
			
			int i = n-1;
			while (i < size && playlist[i+1].present == true) {
				playlist[i].present = playlist[i+1].present;
				playlist[i].song_name = playlist[i+1].song_name;
				playlist[i].artist_name = playlist[i+1].artist_name;

				i++;
			}

			playlist[i].present = false;
			playlist[i].song_name = "";
			playlist[i].artist_name = "";

			return true;

		}
		return false;
	}

	~Playlist() {
		delete[] playlist;
		playlist = nullptr;
	}
};