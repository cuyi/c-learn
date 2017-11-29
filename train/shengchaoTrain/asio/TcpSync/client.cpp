#include <boost/asio.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace boost::asio;
int main()
{
    try
    {
        io_service io;
        ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 6688);
        ip::tcp::socket sock(io);
        sock.connect(ep);
        char str[1024];
        sock.read_some(buffer(str));
        std::cout << "receive from" << sock.remote_endpoint().address() << std::endl;
        std::cout << str << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "exception: [" << e.what() << "]" <<std::endl;
    }
    getchar();
    return 0;
}
