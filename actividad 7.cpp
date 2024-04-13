#include<iostream>
using namespace std;
//ambito global
const char *nombre_archivo ="archivo.dat";
struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
};
void leer();
void crear();
main (){
	// ambito local
	leer();
	crear();
	system ("pause");
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		cout<<id<<" , "estudiante.codigo<<" , "estudiante.nombres<<" , "estudiante.apellidos<<" , "fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	
	fclouse(archivo);
	

}
void crear(){
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char file;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"ingrese codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese nombres:";
		cin.getline(estudiante.nombre,50);
		cout<<"Ingrese apellidos";
		cin.getline(estudiante.apellido,50);
		cout<<"ingrese Telefono:";
		cin>>estudiante.telefono;
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Deseas ingresar otros estudiante (s/n):";
		cin>>res;
	}while(res=='s'|| res =='s');
	fclose(archivo);
	leer();
}
