#ifndef TAP_PACKAGE_H
#define TAP_PACKAGE_H
#include <iostream>

#include "remote.h"

using namespace std;
class Package {
public:
	enum PackageType {
		GIT = 0,
		TAR = 1,
		BIN = 2
	};
	Package(string name, string version, Repo* repo, PackageType type = BIN);
	Package(string name, string version, string description, Repo* repo, PackageType type = BIN);

	friend ostream& operator<<(ostream& os, const Package& pkg);
	int compareVersion(Package& pkg);
	bool samePackage(Package& pkg);
	bool samePackage(string name);
	string getName();
	string getVersion();
	string getDescription();
	Repo* getRepo();
	PackageType getType();
private:
	string name;
	string version;
	string description;
	Repo* repository;
	PackageType type;
};

#endif //TAP_PACKAGE_H