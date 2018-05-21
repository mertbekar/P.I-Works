#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Client
{
	public:
		Client(int song_id, int client_id);
		int getClientID();
		void addSong(int song_id);
		int getSongSize();
		vector<int> getSongList();
	private:
		vector<int> song_list;
		int client_id;
};