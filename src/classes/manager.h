#ifndef TAP_MANAGER_H
#define TAP_MANAGER_H
#include <vector>
#include "package.h"
#include "remote.h"

class Manager {
public:
	Manager();
	int addRepo(Repo repo);
	int removeRepo(string name);
	int update();
	int install(Package pkg);
	int remove(Package pkg);
	int search(string name);
	Package* getPackage(string name);
	Package* getPackage(size_t index);
	Repo* getRepo(string name);
	Repo* getRepo(size_t index);
	size_t getRepoCount();
	void refreshRepos();
	void updateTapPath();

private:
	vector<Repo> repos;
	vector<Package> packages;
	string tapPath;
};

#endif //TAP_MANAGER_H