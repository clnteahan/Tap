#include "remote.h"

Repo::Repo(string url) {
	this->url = url;
}

Repo::Repo(string url, string name) {
	this->url = url;
	this->name = name;
}

string Repo::getName() {
	return this->name;
}

string Repo::getUrl() {
	return this->url;
}

void Repo::setName(string name) {
	this->name = name;
}

int Repo::download(string pkg, string path) {
	return 0; // stub
}
