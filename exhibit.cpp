#include "exhibit.h"
#include <fstream>
#include <sstream>
#include <algorithm>


Client::Client(int song_id, int client_id)
{
	this->song_list.push_back(song_id);
	this->client_id = client_id;
}

int Client::getClientID()
{
	return this->client_id;
}

void Client::addSong(int song_id)
{
	this->song_list.push_back(song_id);
}

int Client::getSongSize()
{
	return this->song_list.size();
}

vector<int> Client::getSongList()
{
	return this->song_list;
}

int main()
{
	string line;
	string token;
	int song_id;
	int client_id;
	int pos;
	vector<Client*> client_list;
	vector<vector<int> > distinct_list;
	ifstream myfile("exhibitA-input.csv");
	getline(myfile, line);
	while(getline(myfile, line))
	{
		pos = line.find("	");
		line.erase(0, pos+1);
		pos = line.find("	");
		token = line.substr(0, pos);
		istringstream iss(token);
		iss >> song_id;
		line.erase(0, pos+1);
		pos = line.find("	");
		token = line.substr(0, pos);
		istringstream iss2(token);
		iss2 >> client_id;
		line.erase(0, pos+1);
		pos = line.find(" ");
		token = line.substr(0, pos);
		if(!token.compare("10/08/2016"))
		{
			int i = 0;
			bool isValid = false;
			while(i<client_list.size())
			{
				if(client_list[i]->getClientID() == client_id)
				{
					isValid = true;
					break;
				}
				i++;
			}
			if(isValid)
			{	
				int k = 0;
				bool isAdded = false;
				while(k<client_list[i]->getSongSize())
				{
					if(client_list[i]->getSongList()[k] == song_id)
					{
						isAdded = true;
						break;
					}
					k++;
				}
				if(!isAdded)
				{
					client_list[i]->addSong(song_id);
				}
			}
			else
			{
				Client* new_client = new Client(song_id, client_id);
				client_list.push_back(new_client);
			}
		}
	}
	//int counter = 0;
	for(int j = 0; j<client_list.size(); j++)
	{
		bool isExist = false;
		int c = 0;
		while(c<distinct_list.size())
		{
			if(distinct_list[c][0] == client_list[j]->getSongSize())
			{
				isExist = true;
				break;
				distinct_list[c][1]++;
			}
			c++;
		}
		if(isExist)
		{
			distinct_list[c][1]++;
		}
		else
		{
			vector<int> temp;
			temp.push_back(client_list[j]->getSongSize());
			temp.push_back(1);
			distinct_list.push_back(temp);
		}
	}
	std::sort(distinct_list.begin(), distinct_list.end());
	int counter = 0;
	for(int j = 0; j<distinct_list.size(); j++)
	{
		cout<<distinct_list[j][0]<<"	"<<distinct_list[j][1]<<endl;
		counter = counter + distinct_list[j][1];
	}
}
