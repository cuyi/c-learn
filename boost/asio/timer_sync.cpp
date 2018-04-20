#include <iostream>
#include <boost/asio.hpp>

int main(void)
{
    boost::asio::io_context io;
    
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    t.wait();
    
    std::cout << "Hello, world!" << std::endl;
    
    return 0;
}
