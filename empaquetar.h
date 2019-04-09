#ifndef EMPAQUETAR_H
#define EMPAQUETAR_H
#include "json.hpp"
#include "Lista.h"

using json = nlohmann::json;

class Empaquetar
{
public:
    Empaquetar(int IDJugador, int IDjuego, bool CrearJuego, bool ActualizarJuego, bool Actualizado, Lista *listaCambios);
    int getIDJugador() const;
    void setIDJugador(int idjugador);
    int getIDjuego() const;
    void setIDjuego(int idjuego);
    bool getCrearJuego();
    void setCrearJuego(bool crearJuego);
    bool getActualizarJuego();
    void setActualizarJuego(bool actualizarJuego);
    bool getActualizado();
    void setActualizado(bool actualizado);

    json getCambios();
    void setCambios(json Cambios);
    json generarJson();


private:
    int IDJugador;
    int IDjuego;
    bool CrearJuego;
    bool ActualizarJuego;
    bool Actualizado;
    json Cambios;
    Lista *ListaCambios;
};

#endif // EMPAQUETAR_H
