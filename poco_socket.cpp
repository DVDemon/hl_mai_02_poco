#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    Poco::Net::SocketAddress sa("ptsv2.com", 80);
    Poco::Net::StreamSocket socket(sa);

    Poco::Net::SocketStream str(socket);
    str << "GET / HTTP/1.0\r\n" <<
           "Host: ptsv2.com\r\n" <<
           "\r\n" <<
           "\r\n";
    str.flush();

    Poco::StreamCopier::copyStream(str, std::cout);

    return 0;
}