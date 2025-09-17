#include <iostream>
#include <string>
#include <vector>
#include "classes/package.h"
using namespace std;


class Test {
public:
	void passTest() {
		passed++;
	}
	void failTest(string testName) {
		testsFailed.push_back(testName);
		failed++;
	}
	void printResults() {
		cout << "Passed: " << this->passed << "/" << this->failed + this->passed << endl;
		cout << "Failed: " << this->failed << "/" << this->failed + this->passed << endl;
		for (auto &v : this->testsFailed) {
			cout << v << endl;
		}
	}
private:
	int passed = 0;
	int failed = 0;
	vector<string> testsFailed;
};

bool testExpected(int results, int expected, string testName, Test* t) {
	if (results == expected) {
		cout << testName << "  PASSED" << endl;
		t->passTest();
		return true;
	}
	cout << testName << " FAILED, expected (" << expected << "), got (" << results << ")" << endl;
	t->failTest(testName);
	return false;
}

bool versionTest(Test* t) {
	Package p1("gcc", "15.2.0", nullptr);
	Package p2("carbon", "16.0.0", nullptr);
	int results = p1.compareVersion(p2);

	return testExpected(results, -1, "VersionTest", t);
}

void testAll() {
	Test *t = new Test;
	// Add tests here
	versionTest(t);
	t->printResults();
	delete t;
}

int main(int argc, char *argv[]) {
	testAll();
}
