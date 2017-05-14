#include <sys/socket.h>
#include <inttypes.h>
#include <stdlib.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <inttypes.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    --argc;
    struct sockaddr_in addr;
    int port;
    sscanf(argv[1], "%d", &port);
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    int sopt;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &sopt, sizeof(sopt));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (const struct sockaddr *) &addr, sizeof(addr));



    listen(sock, 5);
    int client_sock;
    socklen_t client_addr_size;
    struct sockaddr_in client_addr;
    int32_t sum = 0;
    while(1) {
        client_sock = accept(sock, (struct sockaddr *) &client_addr, &client_addr_size);
        int32_t inp;
        read(client_sock, &inp, sizeof(inp));
        inp = ntohl(inp);
        if (inp == 0) {
            close(client_sock);
            break;
        }
        sum += inp;
        close(client_sock);
    }
    printf("%d\n", sum);

    return 0;
}
