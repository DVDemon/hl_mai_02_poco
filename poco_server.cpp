#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/Net/SocketAddress.h>
#include <iostream>

int main([[maybe_unused]]int argc, [[maybe_unused]]char **argv)
{
    Poco::Net::ServerSocket srv(8080); // does bind + listen
    while (true)
    {
        
        Poco::Net::StreamSocket ss = srv.acceptConnection();
        Poco::Net::SocketStream str(ss);
        std::cout << "Connected:" << ss.address().toString() << std::endl;
        str << "HTTP/10 200 OK\r\n"
            << "Content-type: text/html\r\n\r\n"
            << "<html><head><title>My 1st Web Server</title></head><body>Hello world!</body></html>\r\n"
            << std::flush;
    }
}