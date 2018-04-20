#include <boost/asio.hpp>
#include <iostream>
using namespace boost::asio;
int main()
{
    try
    {
        io_service io;
        ip::tcp::endpoint ep(ip::tcp::v4(), 6688);
        ip::tcp::acceptor acceptor(io, ep);
        while (1)
        {
            ip::tcp::socket sock(io);
            acceptor.accept(sock);
            std::cout << "client:" << sock.remote_endpoint().address() << std::endl;
            sock.write_some(buffer("hello asio"));
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() <<std::endl;
    }
    return 0;
}