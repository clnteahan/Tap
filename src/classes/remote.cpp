#include "remote.h"
#include <fstream>
#include <curl/curl.h>

using namespace std;
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

string downloadPath;

size_t response(void *buffer, size_t size, size_t nmemb, void *userp) {
	fstream manifest;
	manifest.open(downloadPath, ios::out);
	for (int i = 0; i < size * nmemb; i++) {
		manifest << static_cast<char *>(buffer)[i];
	}
	return size * nmemb;
}

int Repo::downloadManifest(string path) {
	downloadPath = path + "repos/" + this->getName() + "manifest";
	auto handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, (this->getUrl() + "maifest").c_str());
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, response);
	auto success = curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	curl_global_cleanup();
	return success; // stub
}

int Repo::download(string pkg, string path) {
	downloadPath = path;
	auto handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, (this->getUrl() + pkg).c_str());
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, response);
	auto success = curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	curl_global_cleanup();
	return success; // stub
}
