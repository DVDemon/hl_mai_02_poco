#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>
#include <iostream>

int main()
{
    //*
    Poco::Net::SocketAddress sa("echo.jsontest.com", 80);
    Poco::Net::StreamSocket socket(sa);
    Poco::Net::SocketStream str(socket);
    str << "GET http://echo.jsontest.com/title/ipsum/content/blah HTTP/1.0" << std::endl << std::endl;
    str.flush();
    socket.shutdownSend();
    Poco::StreamCopier::copyStream64(str, std::cout);
    //*/

    /*
    Poco::Net::SocketAddress sa("localhost", 8080);
    Poco::Net::StreamSocket socket(sa);
    Poco::Net::SocketStream str(socket);

    str << "GET /request?session_id=1001 HTTP/1.1\r\n\r\n";
    str.flush();
    socket.shutdownSend();
    Poco::StreamCopier::copyStream64(str, std::cout);
    //*/

    return 0;
}