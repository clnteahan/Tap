#include "manager.h"

 Manager::Manager() {
	 updateTapPath();
 }


int Manager::addRepo(Repo repo) {
	for (auto& r : this->repos) {
		if (r.getName() == repo.getName()) {
			return -1; // Remote already exists
		}
	}
	this->repos.push_back(repo);
	return 0; // Success
}

int Manager::removeRepo(string name) {
	for (auto it = this->repos.begin(); it != this->repos.end(); ++it) {
		if (it->getName() == name) {
			this->repos.erase(it);
			return 0; // Success
		}
	}
	return -1; // Remote not found
}

int Manager::update() {
	// Placeholder for update logic
	return 0; // Success
}

int Manager::install(Package pkg) {
	for (auto& p : this->packages) {
		if (p.samePackage(pkg) && p.compareVersion(pkg) <= 0) {
			return -1; // Package already installed
		}
	}
	this->packages.push_back(pkg);
	return 0; // Success
}

int Manager::remove(Package pkg) {
	for (auto it = this->packages.begin(); it != this->packages.end(); ++it) {
		if (it->samePackage(pkg)) {
			this->packages.erase(it);
			return 0; // Success
		}
	}
	return -1; // Package not found
}

int Manager::search(string name) {
	for (size_t i = 0; i < this->packages.size(); i++) {
		if (this->packages[i].samePackage(name)) {
			return static_cast<int>(i); // Return index of found package
		}
	}
	return -1; // Package not found
}

Package* Manager::getPackage(string name) {
	for (auto& pkg : this->packages) {
		if (pkg.samePackage(name)) {
			return &pkg; // Return pointer to found package
		}
	}
	return nullptr; // Package not found
}

Package* Manager::getPackage(size_t index) {
	if (index < this->packages.size()) {
		return &this->packages[index]; // Return pointer to package at index
	}
	return nullptr; // Index out of bounds
}

size_t Manager::getRepoCount() {
	return this->repos.size();
}

Repo* Manager::getRepo(string name) {
	for (auto& repo : this->repos) {
		if (repo.getName() == name) {
			return &repo; // Return pointer to found repo
		}
	}
	return nullptr; // Repository not found
}
Repo* Manager::getRepo(size_t index) {
	if (index < this->getRepoCount()) {
		return &this->repos[index]; // Return pointer to repo at index
	}
	return nullptr; // Index out of bounds
}

void Manager::updateTapPath() {
	string tpath = getenv("TAP_PATH");
	if (tpath[tpath.length() - 1] != '/') {
		tpath +="/";
	}
	this->tapPath = tpath;
}

void Manager::refreshRepos() {
	for (size_t i = 0; i < this->getRepoCount(); i++) {
		this->getRepo(i)->downloadManifest(this->tapPath);
	}
}