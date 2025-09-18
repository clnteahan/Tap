#include <cstring>
#include <iomanip>
#include <iostream>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <sstream>

#include "crypto.h"

using namespace std;
string to_hex(unsigned char val) {
	stringstream ss;
	ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(val);
	return ss.str();
}

string sha256_string(char* str) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	string out;
	EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr);
	EVP_DigestUpdate(mdctx, str, strlen(str));
	EVP_DigestFinal_ex(mdctx, hash, nullptr);
	EVP_MD_CTX_free(mdctx);
	int i = 0;
	for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		out += to_hex(hash[i]);
	}
	return out;
}

string sha256_string(string str) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	string out;
	EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, EVP_sha256(), nullptr);
	EVP_DigestUpdate(mdctx, str.c_str(), str.length());
	EVP_DigestFinal_ex(mdctx, hash, nullptr);
	EVP_MD_CTX_free(mdctx);
	int i = 0;
	for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		out += to_hex(hash[i]);
	}
	return out;
}