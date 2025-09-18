#include <curl/curl.h>
#include <iostream>
#include "classes/crypto.h"
#include "classes/manager.h"
#include "classes/package.h"

#define TEST true

using namespace std;

int main() {
	curl_global_init(CURL_GLOBAL_DEFAULT);
	Manager* m = new Manager();
	Repo r("https://gcc.gnu.org/onlinedocs/gcc/", "GCC");
	m->addRepo(r);
	m->getRepo("GCC")->download("Option-Summary.html", "/mnt/Drive2/Programming/OS/Tap/manifest");
	cout << sha256_string("Hi there") << endl;
	return 0;
}