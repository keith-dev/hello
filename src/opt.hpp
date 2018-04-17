#pragma once

#include <string>

template <typename T> struct opt {
	opt(T def = T()) : val(def) {}

	T val;
	bool expect;
};

struct opts_t {
	opts_t(int port) : port(port) {}
	opts_t(int port, std::string ip) : port(port), ip(ip) {}

	opt<int> port;
	opt<std::string> ip;
};

opts_t getopt(int argc, char* argv[]);
