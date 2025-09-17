#ifndef TAP_MANAGER_H
#define TAP_MANAGER_H
#include <vector>
#include "package.h"
#include "remote.h"

class Manager {
public:
	int addRepo(Repo repo);
	int removeRepo(string name);
	int update();
	int install(Package pkg);
	int remove(Package pkg);
	int search(string name);
	Package* getPackage(string name);
	Package* getPackage(int index);

private:
	vector<Repo> repos;
	vector<Package> packages;
};

#endif //TAP_MANAGER_H