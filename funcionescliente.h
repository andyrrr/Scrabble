#ifndef FUNCIONESCLIENTE_H
#define FUNCIONESCLIENTE_H

#include "Lista.h"
#include "json.hpp"

using json = nlohmann::json;


class FuncionesCliente
{
public:
    FuncionesCliente();
    json generarJson(Lista ls);
};

#endif // FUNCIONESCLIENTE_H
