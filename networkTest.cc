#include "networkTest.h"

int main(int argc, char *argv[]){
  if(argc<2){
    printf("Need one Parameter\n");
    return 1;
  }
  if(*argv[1]=='s'){
    printf("Server \n");
  
    sf::TcpListener listener;
    // lie l'écouteur à un port
    if (listener.listen(9000) != sf::Socket::Done) {
      printf("Error with port number\n");
      return 1;
    }

    // accepte une nouvelle connexion
    sf::TcpSocket client;
    if (listener.accept(client) != sf::Socket::Done) {
      printf("Client not found\n");
      return 1;
    }
    printf("A client has connected to the server\n");
    return 0;
  } else if (*argv[1]=='c') {
    printf("Client \n");

    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("127.0.0.1", 9000);
    
    if (status != sf::Socket::Done) {
      printf("Server not found\n");
      return 1;
    }
    printf("Connected to server\n");
    return 0;
  }
}
