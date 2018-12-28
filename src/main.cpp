#include "server.hpp"
#include "opt.hpp"
#include <unistd.h>
#include <dlib/http_client/http_client.h>
#include <iostream>

void server(const opts_t& opt)
{
	http_server server;

	server.set_listening_port(opt.port.val);
	if (!opt.ip.val.empty())
		server.set_listening_ip(opt.ip.val);
	server.start_async();

	std::clog << "server sleeping" << std::endl;
	sleep(opt.server_sleep.val);
}

std::string client(const opts_t& opt)
{
	dlib::http_client client;
	std::string url = "http://127.0.0.1:" + std::to_string(opt.port.val) + "/";
	std::clog << "url: " << url << std::endl;

	return client.get_url(url);
}

int main(int argc, char* argv[])
try
{
	opts_t opt = getopt(argc, argv);

	std::async(std::launch::async, server, std::cref(opt));

	sleep(2);
	std::clog << "client sending request" << std::endl;
	std::cout << client(opt) << std::endl;
}
catch (const std::exception& e)
{
	std::cerr << "fatal: " << e.what() << std::endl;
	return 1;
}
