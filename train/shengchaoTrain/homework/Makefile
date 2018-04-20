all:
	g++ async_tcp_echo_server.cpp -o server -I /opt/boost/x86_64/1.62.0/include -L/opt/boost/x86_64/1.62.0/lib -lboost_system -pthread
	g++ blocking_tcp_echo_client.cpp -o client -I /opt/boost/x86_64/1.62.0/include -L/opt/boost/x86_64/1.62.0/lib -lboost_system -pthread

