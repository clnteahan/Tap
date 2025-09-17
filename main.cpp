#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include "package.h"

#define TEST true

using namespace std;
string manifestPath = "/mnt/Drive2/Programming/OS/Tap/manifest";

size_t response(void *buffer, size_t size, size_t nmemb, void *userp) {
	fstream manifest;
	manifest.open(manifestPath, ios::out);
	for (int i = 0; i < size * nmemb; i++) {
		std::cout << static_cast<char *>(buffer)[i];
		manifest << static_cast<char *>(buffer)[i];
	}
	cout << endl;
	return size * nmemb;
}

int main() {
	/*curl_global_init(CURL_GLOBAL_DEFAULT);
	auto handle = curl_easy_init();
	curl_easy_setopt(handle, CURLOPT_URL, "https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html");
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, response);
	auto success = curl_easy_perform(handle);
	curl_easy_cleanup(handle);
	curl_global_cleanup();
	cout << EXIT_SUCCESS << endl;*/


	return 0;
}