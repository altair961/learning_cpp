#include <unistd.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

int main(int argc, char const* argv[]) {
	int client;
	int server;

	struct sockaddr_in server_address;

	client = socket(AF_INET, SOCK_STREAM, 0);

	std::cout << "dsfhbsdjvhb" << std::endl;
}

