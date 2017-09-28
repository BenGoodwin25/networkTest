#include <sys/socket.h>
#include "networkTest.h"

int main(int argc, char *argv[]){
  if(argc<2){
    printf("Need one Parameter\n");
    printf("Use -c for client\nUse -s for Server\n");
    return 1;
  }
  if(argv[1][1]=='s'){
    int status=server();
    return status;
  } else if (argv[1][1]=='c') {
    int status=client();
    return status;
  } else if (argv[1][1]=='h') {
    printf("Use -c for client\nUse -s for Server\n");
    return 0;
  } else {
    printf("Use -c for client\nUse -s for Server\n");
    return 1;
  }
}


int server(){
  printf("Server \n");

  sf::TcpListener listener;
  // link listener to a port
  if (listener.listen(9000) != sf::Socket::Done) {
    printf("Error with port number\n");
    return 1;
  }

  // accept new connection
  sf::TcpSocket server;
  if (listener.accept(server) != sf::Socket::Done) {
    printf("Client not found\n");
    return 1;
  }
  printf("A client has connected to the server\n");

  char data[3];
  std::size_t received;

// socket TCP:
  if (server.receive(data, 3, received) != sf::Socket::Done)
  {
    printf("Data could not found\n");
  }
  printf("received %zu bytes : %s \n",received, data);
  return 0;
}


int client(){
  printf("Client \n");

  sf::TcpSocket client;
  sf::Socket::Status status = client.connect("127.0.0.1", 9000);

  if (status != sf::Socket::Done) {
    printf("Server not found\n");
    return 1;
  }
  printf("Connected to server\n");

  char data[3] = "OK";
  if (client.send(data, 3) != sf::Socket::Done)
  {
    printf("Data could not be sent\n");
  }


  return 0;
}