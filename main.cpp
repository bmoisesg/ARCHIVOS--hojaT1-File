#include <iostream>
#include <fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

struct alumno{
    int tipo=0;
    char primer_apellido[21];
    char segundo_apellido[21];
    char nombre[21];
    char codigo[11];
    int nota;
};

struct docente{
    int tipo=1;
    char primer_apellido[21];
    char segundo_apellido[21];
    char nombre[21];
    char codigo[11];
    int seccion;
};

void mensaje(){
    cout<<"\n*********************************\n MoisesGonzalezFuentes-201602907"<<endl;
    cout<<" 0. Crear archivo binario"<<endl;
    cout<<" 1. Ingresar alumno"<<endl;
    cout<<" 2. Ingresar docente"<<endl;
    cout<<" 3. Editar alumno"<<endl;
    cout<<" 4. Editar docente"<<endl;
    cout<<" 5. Reporte"<<endl;
    cout<<" 6. Salir\n**************************";
}

void addAlumno(){
    cout<<"->AGREGAR alumno--------------------"<<endl;

    FILE *arch;
    arch=fopen("datos.bin","ab");
    if (arch==NULL)
        exit(1);
    alumno nuevo;

    char a[21];
    cout<<"ingrese nombre:";
    cin>>a;
    strcpy(nuevo.nombre,a);
    cout<<"ingrese primer apellido:";
    cin>>a;
    strcpy(nuevo.primer_apellido,a);
    cout<<"ingrese segundo apelligo:";
    cin>>a;
    strcpy(nuevo.segundo_apellido, a);
    cout<<"ingrese codigo:";
    cin>>a;
    strcpy(nuevo.codigo,a);
    cout<<"ingrese nota:";
    int n;
    cin>>n;
    nuevo.nota=n;
    fwrite(&nuevo, sizeof(alumno), 1, arch);
    fclose(arch);
}

void addDocente(){
    cout<<"->AGREGAR docente--------------------"<<endl;

    FILE *arch;
    arch=fopen("datos.bin","ab");
    if (arch==NULL)
        exit(1);
    docente nuevo;

    char a[21];
    cout<<"ingrese nombre:";
    cin>>a;
    strcpy(nuevo.nombre,a);
    cout<<"ingrese primer apellido:";
    cin>>a;
    strcpy(nuevo.primer_apellido,a);
    cout<<"ingrese segundo apelligo:";
    cin>>a;
    strcpy(nuevo.segundo_apellido, a);
    cout<<"ingrese codigo:";
    cin>>a;
    strcpy(nuevo.codigo,a);
    cout<<"ingrese seccion:";
    int n;
    cin>>n;
    nuevo.seccion=n;
    fwrite(&nuevo, sizeof(docente), 1, arch);
    fclose(arch);
}

void mostrarContenido(){
    cout<<"\nCONTENIDO DE DATOS ALMACENADOS-------------------------------\n"<<endl;
    alumno leer;
    ifstream leerArchivo("datos.bin", ios::binary );
    while( !leerArchivo.eof() ) {
        leerArchivo.read( (char *) &leer, sizeof(alumno ) );
        if(!leerArchivo.eof()){
            cout<<"id:"<<leer.tipo<<endl;
            cout<<"nombre:"<<leer.nombre<<endl;
            cout<<"apellido:"<<leer.primer_apellido<<endl;
            cout<<"apellido:"<<leer.segundo_apellido<<endl;
            cout<<"codigo:"<<leer.codigo<<endl;
            cout<<"nota:"<<leer.nota<<endl;
            cout<<"*************************************"<<endl;
        }
    }
    cout<<endl<<endl;
}

void editAlumno(){
    FILE *arch=fopen("datos.bin","r+b");
    char buscarCodigo[]={};
    cout<<"ingresar el codigo del alumno:";
    cin>>buscarCodigo;
    int encontre=0;
    alumno x;

    while(!feof(arch))
    {
        fread(&x, sizeof(alumno), 1, arch);
        if(!feof(arch)){
            if (strcmp(x.codigo,buscarCodigo)==0 && x.tipo==0)
            {
                alumno nuevo;
                char a[21];
                cout<<"ingrese nuevo nombre:";
                cin>>a;
                strcpy(nuevo.nombre,a);
                cout<<"ingrese nuevo primer apellido:";
                cin>>a;
                strcpy(nuevo.primer_apellido,a);
                cout<<"ingrese nuevo segundo apelligo:";
                cin>>a;
                strcpy(nuevo.segundo_apellido, a);
                cout<<"ingrese nuevo codigo:";
                cin>>a;
                strcpy(nuevo.codigo,a);
                cout<<"ingrese nuevo  nota:";
                int n;
                cin>>n;
                nuevo.nota=n;

                int pos=ftell(arch)-sizeof(alumno);
                fseek(arch,pos,SEEK_SET);
                fwrite(&nuevo, sizeof(alumno), 1, arch);
                encontre=1;
                break;
            }
        }

    }


    if(encontre==0){
        cout<<"no lo encontre :c"<<endl;
    }
    fclose(arch);
}
void editDocente(){
    FILE *arch=fopen("datos.bin","r+b");
    char buscarCodigo[]={};
    cout<<"ingresar el codigo del docente:";
    cin>>buscarCodigo;
    int encontre=0;
    alumno x;

    while(!feof(arch))
    {
        fread(&x, sizeof(alumno), 1, arch);
        if(!feof(arch)){
            if (strcmp(x.codigo,buscarCodigo)==0 && x.tipo==1)
            {
                docente nuevo;
                char a[21];
                cout<<"ingrese nuevo nombre:";
                cin>>a;
                strcpy(nuevo.nombre,a);
                cout<<"ingrese nuevo primer apellido:";
                cin>>a;
                strcpy(nuevo.primer_apellido,a);
                cout<<"ingrese nuevo segundo apelligo:";
                cin>>a;
                strcpy(nuevo.segundo_apellido, a);
                cout<<"ingrese nuevo codigo:";
                cin>>a;
                strcpy(nuevo.codigo,a);
                cout<<"ingrese nuevo seccion:";
                int n;
                cin>>n;
                nuevo.seccion=n;

                int pos=ftell(arch)-sizeof(docente);
                fseek(arch,pos,SEEK_SET);
                fwrite(&nuevo, sizeof(docente), 1, arch);
                encontre=1;
                break;
            }
        }

    }


    if(encontre==0){
        cout<<"no lo encontre :c"<<endl;
    }
    fclose(arch);
}
void primeraVez(){

    FILE *arch;
    //    char titulo[10];
    //    cout<<"escriba el nombre con que se guardara el archivo binario:";
    //    cin>>titulo;
    //    arch=fopen(strcat(titulo, ".bin"),"wb");
    arch=fopen("datos.bin","wb");
    if (arch==NULL) exit(1);
    fclose(arch);

}
int main()
{

    bool bandera=false;
    char tecla;
    while(true){
        mensaje();
        cin >> tecla;
        switch (tecla) {
        case '0':
            primeraVez();
            break;
        case '1':
            addAlumno();
            break;
        case '2'://agregar docente
            addDocente();
            break;
        case '3'://editar alumnos
            editAlumno();
            break;
        case '4'://editar alumnos
            editDocente();
            break;
        case '5'://reporte
            mostrarContenido();
            break;
        case '6'://salir
            bandera=true;
            break;
        }
        if(bandera==true)break;
    }
    return 0;
}
