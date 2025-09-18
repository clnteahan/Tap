#ifndef TAP_REMOTE_H
#define TAP_REMOTE_H
#include <string>

using namespace std;
class Repo {
public:
	explicit Repo(string url);
	Repo(string url, string name);
	string getUrl();
	string getName();
	void setName(string name);
	int downloadManifest(string path);
	int download(string pkg, string path);
private:
	string url;
	string name;
};

#endif //TAP_REMOTE_H