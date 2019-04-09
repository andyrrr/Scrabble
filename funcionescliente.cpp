#include "funcionescliente.h"
#include "json.hpp"
#include "Lista.h"
#include <iostream>

using namespace std;
using json = nlohmann::json;

FuncionesCliente::FuncionesCliente()
{
}
json FuncionesCliente::generarJson(Lista lista) {
    json j1;
    Nodo *temp;
    temp = lista.getHead();
    int i = 1;
    j1["0"] = lista.size;

    while (temp != NULL) {
        std::string s = std::to_string(i);
        j1[s] = {{"Letra", temp->letra},
                 {"Posi",  {temp->fil, temp->col}}};
        temp = temp->next;
        i++;
    }

    return j1;
}
