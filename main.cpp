#include <iostream>
#include <exception>

#include "CGFapplication.h"
#include "TPscene.h"
#include "DemoScene.h"
#include "XMLScene.h"

using std::cout;
using std::exception;

int main(int argc, char* argv[])
{

    CGFapplication app = CGFapplication();
    XMLScene lsf_scene = XMLScene((char *)"scene.xml");

    try
    {
        app.init(&argc, argv);

        app.setScene(new DemoScene());
        app.setInterface(new CGFinterface());

        app.run();
    }
    catch (GLexception& ex)
    {
        cout << "Erro: " << ex.what();
        return -1;
    }
    catch (exception& ex)
    {
        cout << "Erro inesperado: " << ex.what();
        return -1;
    }

    return 0;
}