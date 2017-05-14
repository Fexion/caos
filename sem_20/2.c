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
#include <string.h>

int main(int argc, char const *argv[]) {
    --argc;
    int bufsize = 1024;
    char buffer[bufsize];

    struct addrinfo hints = {}; // обнуляем структуру
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *res;
    struct in_addr maddr;
    unsigned short min_addr_port;

    int err = getaddrinfo(argv[1], argv[2], &hints, &res);
    if (err) {
        printf("%s\n", gai_strerror(err));
        return 0;
    }else {
        struct sockaddr_in *ai = (struct sockaddr_in *)res->ai_addr;
        maddr = ai->sin_addr;
        min_addr_port = ai->sin_port;
    }

    freeaddrinfo(res);
    int sock = socket(PF_INET, SOCK_STREAM, 0);

    if(sock < 0) {
        exit(1);
    }

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = min_addr_port;
    addr.sin_addr = maddr;


    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        exit(1);
    }
    FILE *recieve = fdopen(dup(sock), "r");
    FILE *send = fdopen(sock, "w");

    if (!fprintf(send, "%s\n",argv[3])) {
        fclose(send);
        fclose(recieve);
        //close(sock);
        return 0;
    }
    fflush(send);

    uint64_t K;
    if (!fscanf(recieve, "%"SCNu64, &K)) {
        fclose(send);
        fclose(recieve);
        //close(sock);
        return 0;
    }
    fflush(send);
    for (uint64_t i = 0; i <= K; ++i) {
        if (!fprintf(send, "%"PRIu64"\n", i)) {
            fclose(send);
            fclose(recieve);
            //close(sock);
            return 0;
        }
    }
    fflush(send);
    if (!fscanf(recieve, "%s", buffer)) {
        fclose(send);
        fclose(recieve);
        //close(sock);
        return 0;
    }
    fclose(send);
    fclose(recieve);
    printf("%s\n", buffer);
    fflush(stdout);
    //close(sock);
    return 0;
}
