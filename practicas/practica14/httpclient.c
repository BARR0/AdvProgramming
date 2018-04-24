#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    char *serverName = argv[1];
    struct hostent *serverIP = gethostbyname(serverName);
    struct sockaddr_in server;
    int my_socket;
    char *msg = "GET index.html HTTP/1.0\r\n Host: 10.43.53.108 \r\n";
    char buffer[1000];

    printf("The hostname address is %s.\n", serverIP->h_name);
    memcpy(&server.sin_addr, serverIP->h_addr_list[0], serverIP->h_length);
    server.sin_port = htons(443);
    server.sin_family = AF_INET;
    my_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(my_socket, (struct sockaddr *) &server, sizeof(server)) == 0)
    {
        printf("CONNECTED\n");
        write(my_socket, msg, strlen(msg)* sizeof(char));
        read(my_socket, buffer, sizeof(buffer));
        printf("%s\n", buffer);
    }
    else
    {
        printf("error %d\n", errno);
    }

    return 0;
}
