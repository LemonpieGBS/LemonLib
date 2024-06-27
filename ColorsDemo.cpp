#include <iostream>

#include "LemonLib/LemonLibCSB.h"

using namespace LLC;
using namespace std;

int main() {

    #ifdef _WIN32
        CSB_VIRTUAL_PROCESSING();
    #endif

    // Esta es una demostración de LemonLibCSB.h, una libreria de colores que usa ANSI para
    // sus formatos, conviertiendola en muy portable
    
    // CSB se refiere a los atributos que puedes cambiar con esta libreria:
    // COLORS | STATES | BACKGROUNDS
    // veremos una demostracion:

    _colSET(cRED);
    cout << "HOLA EN ROJO!! ";
    _colRESET();
    cout << "Hola pero ahora normal" << endl << endl;

    // Aqui estamos haciendo uso de la funcion _colSET que acepta un color para tintar la consola
    // los colores estan en el ennumerador COLORS en LemonLibCSB.h

    // Tambien podemos hacerlo con estados como poner el texto en negritas, en italica, subrayado, etc.

    _stateSET(stBOLD);
    cout << "Texto en negritas! ";

    _stateSET(stSTRIKETHROUGH);
    cout << "Texto en negritas y strikethrough! ";

    _stateRESET(); _stateSET(stUNDERLINE, stITALIC);
    cout << "Texto subrayado y en italicas!" << endl << endl;

    _stateRESET();

    // _stateSET te deja poner mas de un estado, es mas, cuantos quieras, sin embargo, por limitaciones
    // _stateRESET resetea todos los estados, asi que si solo quieres quitar un estado vas a tener que resetear todos

    // los estados estan en el ennumerador STATES en LemonLibCSB.h e incluye:
    // BOLD (negritas)
    // ITALIC (italica o inclinada)
    // UNDERLINED (subrayado)
    // STRIKETHROUGH (con una linea empalando por el medio)

    // Finalmente, veremos como usar los backgrounds, que es casi lo mismo que los colores:

    _backgroundSET(bgRED);
    cout << "Texto con fondo rojo!! ";

    _backgroundSET(bgBLUE);
    cout << "Texto con fondo azul!! ";

    _backgroundRESET();
    cout << "Texto sin fondo :(" << endl << endl;

    // los backgrounds estan como de costumbre en el ennumerador BACKGROUNDS en LemonLibCSB.h
    // Adicionalmente, puedes usar la función _csbRESET() para resetear de fabrica la consola y evitar
    // que se desparramen colores, estados o backgrounds

    _csbRESET();

    // Ahora, poner tantas funciones se hace cansado, por ende, he maquinado una manera de incluir CSB
    // en couts de manera rapida, sencilla e intuitiva: _cTAG y _rTAG

    // _cTAG hace un poco de magia para cambiar la consola al estado deseado, sea color, state o background
    // Una grandisima ventaja es que puedes meter múltiples tags en un solo _cTAG

    cout << _cTAG(cBLUE,stUNDERLINE,stBOLD) << "Texto azul en negritas y subrayado! ";
    _csbRESET(); // Es buena practica resetear despues de usar un TAG

    cout << _cTAG(cRED,stITALIC,bgWHITE) << "Rojo en Blanco e inclinado! ";
    _csbRESET(); 

    cout << _cTAG(bgYELLOW,stSTRIKETHROUGH,cBLACK) << "Negro empalado en amarillo!" << endl << endl;
    // ^ ^ ^ cuando haces nuevas lineas con un BACKGROUND activo se desparrama en todo asi que asegura
    // de resetear antes de hacer un \n

    _csbRESET();

    // _rTAG es para resetear: COLORS, STATES y BACKGROUND
    // Existen rtCOLOR, rtSTATES y rtBACKGROUND, rt quiere decir Reset Type
    // hay una opcion adicional llamada rtFULL que los resetea todos al default, el equivalente a _csbRESET()

    cout << _cTAG(cPURPLE, stBOLD, stUNDERLINE, stITALIC) << "Me emociona mucho el morado y los estados ";
    cout << _rTAG(rtSTATES) << "Ahora solo el morado" << endl << endl;

    // Ahora una demostracion final:
    cout << _cTAG(cRED,stBOLD) << "GRACIAS " << _rTAG(rtFULL);
    cout << _cTAG(cYELLOW, stITALIC, stUNDERLINE) << "POR " << _rTAG(rtFULL);
    cout << _cTAG(cBLACK,bgBLUE,stSTRIKETHROUGH) << "LEER!" << _rTAG(rtFULL) << endl << endl;

    // Elije la manera que quieras de hacer las cosas, o con las funciones o con los tags, ambas tienen sus
    // ventajas :)

    _csbRESET(); // Al final de tu programa, asegurate de resetear CSB por si acaso. Es buena practica.
    system("pause");

    return 0;

}