#ifndef CONEXION_H
#define CONEXION_H
#include <string>
#include "empaquetar.h"
#include "iostream"
#include "json.hpp"

using json=nlohmann::json;
using namespace std;

class Conexion
{
public:
    Conexion(Empaquetar *paquete);
    void establecerConexion(string InfoEnviar);
    string getInfoRecibir();
    Lista * generateList(json j1);
    Lista * CambiosRecibidos;
    Empaquetar *package;

private:
    string infoEnviar;
    string infoRecibir;
    Empaquetar *desempaquetar(json j1);
    json StringtoJson(string s1);


};

#endif // CONEXION_H
