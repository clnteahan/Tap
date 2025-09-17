#include <iostream>
#include "classes/package.h"
#include <curl/curl.h>

#define TEST true

using namespace std;

string getTapPath() {
	string tapPath = getenv("TAP_PATH");
	if (tapPath[tapPath.length() - 1] != '/') {
		tapPath +="/";
	}
	return tapPath;
}

int main() {
	curl_global_init(CURL_GLOBAL_DEFAULT);
	Repo* rep = new Repo("https://gcc.gnu.org/onlinedocs/gcc/", "GCC");
	cout << rep->download("Option-Summary.html", getTapPath() + "manifest") << endl;

	return 0;
}