#pragma once

#include <dlib/server.h>

class http_server : public dlib::server_http
{
public:
	typedef dlib::server_http inherited;

	using inherited::inherited;

private:
	const std::string on_request(const dlib::incoming_things&, dlib::outgoing_things&);
};
