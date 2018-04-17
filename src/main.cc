#include "server.hpp"
#include "opt.hpp"
#include <iostream>

int main(int argc, char* argv[])
try
{
	opts_t opt = getopt(argc, argv);

	http_server server;
	server.set_listening_port(opt.port.val);
	if (!opt.ip.val.empty())
		server.set_listening_ip(opt.ip.val);
	server.start_async();

	std::cout << "press any key to stop" << std::endl;
	std::cin.get();
}
catch (const std::exception& e)
{
	std::cerr << "fatal: " << e.what() << std::endl;
}
