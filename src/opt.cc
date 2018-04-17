#include "opt.hpp"
#include <algorithm>
#include <string>
#include <string.h>

opts_t getopt(int argc, char* argv[])
{
	opts_t opts(8080);

	std::for_each(argv + 1, argv + argc, [&](const char* arg) {
		if (!strcmp(arg, "-p") || !strcmp(arg, "--port")) {
			opts.port.expect = true;
			return;
		}
		if (opts.port.expect) {
			opts.port.val = atoi(arg);
			opts.port.expect = false;
			return;
		}
		if (!strcmp(arg, "-a") || !strcmp(arg, "--addr")) {
			opts.ip.expect = true;
			return;
		}
		if (opts.ip.expect) {
			opts.ip.val = arg;
			opts.ip.expect = false;
			return;
		}
	});

	return opts;
}
