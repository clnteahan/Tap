#include "package.h"
#include <sstream>
#include <vector>

Package::Package(string name, string version, Repo *repo, PackageType type) {
	this->name = name;
	this->version = version;
	this->repository = repo;
	this->type = type;
}

Package::Package(string name, string version, string description, Repo *repo, PackageType type) {
	this->name = name;
	this->version = version;
	this->description = description;
	this->repository = repo;
	this->type = type;
}

ostream& operator<<(ostream& os, const Package& pkg) {
	os << pkg.name << "#" << pkg.version << "@" << pkg.repository->getName() << ":" << pkg.type;
	return os;
}


std::vector<int> splitVersion(const std::string& version) {
	std::vector<int> parts;
	std::stringstream ss(version);
	std::string part;
	while (std::getline(ss, part, '.')) {
		parts.push_back(std::stoi(part));
	}
	return parts;
}

int Package::compareVersion(Package &pkg) {
	std::vector<int> parts1 = splitVersion(this->getVersion());
	std::vector<int> parts2 = splitVersion(pkg.getVersion());

	int n = std::max(parts1.size(), parts2.size());
	for (int i = 0; i < n; ++i) {
		int num1 = (i < parts1.size()) ? parts1[i] : 0;
		int num2 = (i < parts2.size()) ? parts2[i] : 0;
		if (num1 < num2) return -1;
		else if (num1 > num2) return 1;
	}
	return 0;
}

bool Package::samePackage(Package& pkg) {
	return this->samePackage(pkg.getName());
}

bool Package::samePackage(string name) {
	return name == this->getName();
}

string Package::getName() {
	return this->name;
}

string Package::getVersion() {
	return this->version;
}

string Package::getDescription() {
	return this->description;
}

Repo* Package::getRepo() {
	return this->repository;
}

Package::PackageType Package::getType() {
	return this->type;
}