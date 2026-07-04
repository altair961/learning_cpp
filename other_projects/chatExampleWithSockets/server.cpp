#include <unistd.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define ERROR_S "SERVER ERROR: "
#define DEFAULT_PORT 1601

int main(int argc, char const* argv[]) {
	int client;
	int server;

	struct sockaddr_in server_address;

	client = socket(AF_INET, SOCK_STREAM, 0);

	if(client < 0) {
		std::cout << ERROR_S << "establishing socket error.\n";
		exit(0);
	}

	std::cout << "SERVER: Server socket was successfully created.\n";
	
	server_address.sin_port = htons(DEFAULT_PORT);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	int ret = bind(client, reinterpret_cast<sockaddr*>(&server_address),
		sizeof(server_address));
	
	if(ret < 0) {
		std::cout 
			<< ERROR_S 
			<< "binding failed.\n";
		return -1;
	}

	int size = sizeof(server_address);

	std::cout << "SERVER :" << "Listening clients...\n";
}