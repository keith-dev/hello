#include <dlib/server.h>
#include <iostream>

class http_server : public dlib::server_http
{
public:
	typedef dlib::server_http inherited;

	using inherited::inherited;

private:
	const std::string on_request(const dlib::incoming_things&, dlib::outgoing_things&) { return std::string(); }
};

int main()
{
	std::cout << "hello" << std::endl;
	http_server();
}
