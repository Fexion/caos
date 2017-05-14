#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char const *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Not enough parameters!\n");
    return 0;
  }

  uint16_t port = htons(atoi(argv[1]));

  int sfd = socket(PF_INET, SOCK_STREAM, 0);
  if (sfd == -1) {
    perror("socket");
    return 0;
  }

  int sopt = 1;
  setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &sopt, sizeof(sopt));

  struct sockaddr_in bind_addr = {.sin_family = AF_INET,
                                  .sin_port = port,
                                  .sin_addr.s_addr = INADDR_ANY};
  if (bind(sfd, (struct sockaddr*) &bind_addr, sizeof(bind_addr)) == -1) {
    perror("bind");
    return 0;
  }

  if (listen(sfd, 5) == -1) {
    perror("listen");
    return 0;
  }

  struct sockaddr_in in_addr;
  while (1) {
    while (waitpid(-1, NULL, WNOHANG) > 0);


    int afd;
    int in_size = sizeof(in_addr);
    if ((afd = accept(sfd, (struct sockaddr *) &in_addr, (socklen_t *)&in_size)) == -1) {
      perror("accept");
      return 0;
    }

    if (!fork()) {
      close(sfd);
      FILE* client_read = fdopen(dup(afd), "r");
      FILE* client_write = fdopen(afd, "w");

      printf("Client accepted from %s:%hu\n", inet_ntoa(in_addr.sin_addr), ntohs(in_addr.sin_port));

      char key[1024];
      fscanf(client_read, "%s", key);
      printf("Received key %s\n", key);

      int k = atoi(argv[2]);
      fprintf(client_write, "%d\n", k);
      fflush(client_write);
 
      int temp;
      for (int i = 0; i <= k; ++i) {
        fscanf(client_read, "%d", &temp);
        if (temp != i) {
          printf("Error! Temp is: %d\n", temp);
          fflush(stdout);
          _exit(0);
        }
      }

      fprintf(client_write, "%d\n", 111111);
      fflush(client_write);
      fclose(client_read);
      fclose(client_write);
      _exit(0);
    }
    close(afd);
  }
  return 0;
}
