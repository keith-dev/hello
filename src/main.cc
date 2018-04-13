#include <dlib/server.h>
#include <iostream>

class http_server : public dlib::server_http
{
public:
	using dlib::server_http;

private:
	const string dlib::server_http::on_request(const dlib::incoming_things&, dlib::outgoing_things&) { return std::string(); }
};

int main()
{
	std::cout << "hello" << std::endl;
	http_server();
}
