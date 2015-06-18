#include <iostream>
#include "io/nosqlrow.h"
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    string *_schema = new string[3];
    _schema[0] = "nombre";
    _schema[1] = "apellido";
    _schema[2] = "edad";
    RowElement * rowelement=new RowElement[3];
    rowelement[0] = RowElement("Cristian");
    rowelement[1] = RowElement("Rivera  ");
    rowelement[2] = RowElement(20);
    RowElement * rowelement2=new RowElement[3];
    rowelement2[0] = RowElement("Cristal ");
    rowelement2[1] = RowElement("Rivera  ");
    rowelement2[2] = RowElement(18);
    RowElement * rowelement3=new RowElement[3];
    rowelement3[0] = RowElement("Eddie   ");
    rowelement3[1] = RowElement("Rivera  ");
    rowelement3[2] = RowElement(14);
    NoSQLRow nsql(_schema,rowelement,3);
    RowElement el= nsql[string("nombre")];
    try{
        cout << "El nombre es: " << nsql["nombre"].toString() << endl;
        cout << "El apellido es: " << nsql["apellido"].toString() << endl;
        cout << "La edad es: " << nsql["edad"].toInt() << endl;
    }
    catch (BadParseException e){
        cout << e.getMessage() << endl;
    }
    catch (ElementDontFounded e1){
        cout << e1.getMessage() << endl;
    }
    ofstream fsalida("prueba.bin", ios::out | ios::binary);
    int * element = new int(rowelement[2].toInt());
    fsalida.write(reinterpret_cast<char*>(rowelement),sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    fsalida.write(reinterpret_cast<char*>(rowelement2),sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    fsalida.write(reinterpret_cast<char*>(rowelement3),sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    fsalida.close();
    cout << sizeof(RowElement) << endl;
    ifstream fentrada("prueba.bin",ios::in | ios::binary);
    char *appel = new char[8];
    fentrada.seekg(sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    fentrada.read(reinterpret_cast<char*>(rowelement),sizeof(RowElement)*3+sizeof(int)+sizeof(char)*16);
    cout << rowelement[0].toString() << endl;
    cout << rowelement[1].toString() << endl;
    cout << rowelement[2].toInt() << endl;
    fentrada.close();

    return 0;
}

