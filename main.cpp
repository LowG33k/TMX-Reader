#include <iostream>
#include "Map.hpp"
#include <windows.h>

using namespace std;

int main()
{
    system( "pause" );

    //TMX::Map myMap( "Maps/town.tmx" );
    //TMX::Map myMap( "Maps/town_csv.tmx" );
    TMX::Map myMap( "Maps/town_b64.tmx" );

    myMap.printToStream();

    return 0;
}

