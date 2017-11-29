#include <boost/asio.hpp>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

using namespace boost;
using namespace boost::asio;
class Client
{
    typedef ip::tcp::socket socket_type;
    typedef shared_ptr<socket_type> sock_ptr;
public:
    Client() :m_ep(ip::address::from_string("127.0.0.1"), 6688)
    {
        start();
    }
    void run()
    {
        m_io.run();
    }
private:
    void start()
    {
        sock_ptr sock(new socket_type(m_io));
        sock->async_connect(m_ep, bind(&Client::connect_handler, this, _1, sock));
    }
    void connect_handler(const boost::system::error_code& ec, sock_ptr sock)
    {
        if (ec)
        {return;}
        std::cout << "receive from:" << sock->remote_endpoint().address() << std::endl;
        sock->async_read_some(buffer(m_buf),
            bind(&Client::read_handler, this, _1));
    }
    void read_handler(const boost::system::error_code& ec)
    {
        if (ec)
        {return;}
        std::cout << m_buf << std::endl;
    }
private:
    io_service m_io;
    ip::tcp::endpoint m_ep;
    enum { max_length = 1024 };
    char m_buf[max_length];
};
int main()
{
    try
    {
        std::cout << "client start." << std::endl;
        Client cl;
        cl.run();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    getchar();
    return 0;
}