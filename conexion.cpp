
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>


#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "conexion.h"

using namespace std;


Conexion::Conexion(Empaquetar* paquete)
{
    json jsonGenerado=paquete->generarJsonEmpaquetado();
    infoEnviar=jsonGenerado.dump();
    infoRecibir="";
    establecerConexion(infoEnviar);

}


void Conexion::establecerConexion(string infoenviar){
    //	Create a socket+
    cout<<"A ENVIAR ------------------------------"<<endl;
    cout<<infoenviar<<endl;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        return;
    }

    //	Create a hint structure for the server we're connecting with
    int port = 6969;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        return;
    }

    //	While loop:
    char buf[4096];


        char mensajeCliente[sizeof(infoenviar)];
        strcpy(mensajeCliente, infoenviar.c_str());
        cout<<strlen(mensajeCliente)<<endl;
        int sendRes = send(sock, mensajeCliente, strlen(mensajeCliente), 0);
        if (sendRes == -1)
        {
            cout << "Could not send to server! Whoops!\r\n";
        }

        //		Wait for response
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            cout << "There was an error getting response from server\r\n";
        }
        else
        {
            buf[bytesReceived] = '\0';
            cout<<buf<<endl;
            cout<<"aqui entra"<<endl;
            Empaquetar *recibido = desempaquetar(StringtoJson(string(buf)));
            cout<<"CJ"<<recibido->getCrearJuego()<<endl;
            cout<<"AJ"<<recibido->getActualizarJuego()<<endl;
            cout<<"Ado"<<recibido->getActualizado()<<endl;
            if (recibido->getActualizado()){
                cout<<"no entiendo"<<endl;
                CambiosRecibidos=recibido->getListaCambios();
                infoRecibir=buf;
            }
            close(sock);
            return;
        }
}

string Conexion::getInfoRecibir(){
    return infoRecibir;
}

json Conexion::StringtoJson(string s1){
    json j1;
    j1 = json::parse(s1);
    return j1;

}

Empaquetar* Conexion::desempaquetar(json j1){
    Empaquetar *paquete = new Empaquetar();
        json lista = j1["JSON"];
        int idGam = j1["IDGAME"];
        int idPlay = j1["IDPLAYER"];
        bool crearJuego = j1["CREATE"];
        bool refresh = j1["REFRESH"];
        bool refreshed = j1["REFRESHED"];
        paquete->setIDjuego(idGam);
        paquete->setIDJugador(idPlay);
        paquete->setCrearJuego(crearJuego);
        paquete->setActualizarJuego(refresh);
        paquete->setActualizado(refreshed);
        paquete->setCambios(lista);
        paquete->setListaCambios(generateList(lista));
        paquete->getListaCambios()->vernodos();
        package = paquete;
        return paquete;
}


Lista* Conexion::generateList(json j1) {
    Lista *temp = new Lista(); //la lista es recibida mediante el socket
        int s = j1["0"];
        if(s==1){
            std::cout << "hello"<<std::endl;

            temp->addLetra("NULL");
            return temp;
        }else{
        for (int j = 1; j <= s; ++j) {
            std::string sq = std::to_string(j);
            temp->addLetra(j1[sq]["Letra"]);
        }
            return temp;
        }

    }
