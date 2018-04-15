#include "server.hpp"
#include <iostream>

int main()
{
	http_server server;

	server.set_listening_port(5000);
	server.start_async();

	std::cout << "press any key to stop" << std::endl;
	std::cin.get();
}
