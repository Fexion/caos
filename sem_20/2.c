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
    struct hostent *phe = gethostbyname(argv[1]);

    int port;
    sscanf(argv[2], "%d", &port);
    int sock = socket(PF_INET, SOCK_STREAM, 0);

    if(sock < 0) {
        exit(1);
    }

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    memcpy(&addr.sin_addr, phe->h_addr_list[0], sizeof(addr.sin_addr));


    if(connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        exit(1);
    }
    FILE *recieve = fdopen(sock, "r");
    FILE *send = fdopen(sock, "w");
    fprintf(send, "%s\n",argv[3]);
    uint64_t K;
    fscanf(recieve, "%"SCNu64, &K);
    fflush(send);
    for (uint64_t i = 0; i <= K; ++i) {
        fprintf(send, "%"PRIu64"\n", i);
    }
    fflush(send);
    fscanf(recieve, "%s", buffer);
    fclose(send);
    fclose(recieve);
    printf("%s\n", buffer);
    fflush(stdout);
    close(sock);
    return 0;
}
