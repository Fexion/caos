#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <inttypes.h>


int main() {
    char host[1000], service[1000];
    struct addrinfo hints = {}; // обнуляем структуру
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    while ((scanf("%s %s", host, service)) != EOF) {
        struct addrinfo *res;

        int err = getaddrinfo(host, service, &hints, &res);
        if (err) {
            printf("%s\n", gai_strerror(err));
        }else {
            uint32_t min_addr = UINT32_MAX;
            struct in_addr addr;
            unsigned short min_addr_port;
            for (struct addrinfo *cur = res; cur; cur = cur->ai_next) {
                struct sockaddr_in *ai = (struct sockaddr_in *)cur->ai_addr;
                uint32_t ai_addr =  ntohl((ai->sin_addr).s_addr);

                if (min_addr >= ai_addr) {
                    min_addr = ai_addr;
                    addr = ai->sin_addr;
                    min_addr_port = ai->sin_port;
                }
            }

            printf("%s:%hu\n", inet_ntoa(addr), ntohs(min_addr_port));

        freeaddrinfo(res);
        }
    }
}
