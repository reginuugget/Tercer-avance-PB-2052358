#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
//3er Avance Programación Básica c:
//Regina Osoria Gutiérrez

using namespace std;

struct tiendita
{
	//it = ítem
	int numit;
	float precioit, ivait, totit;
	string nameit, descit, genit, consit, clasifit, status;
};

tiendita* item;//Puntero: ítem

int n;//Número de registros deseados (arreglo dinámico)

//Mis funciones

void Alta();
void Mod();
void Baja();
void Lista();
void Archivos();


int main()
{

	int opc, i = 0;

	printf("\n\tGameStop!! > < !! <3\n"); //Nombre de tienda
	printf("\n%c!  1.- Alta de %ctem.\n%c!  2.- Modificaci%cn de %ctem.\n%c!  3.- Baja de %ctem.", 3, 161, 3, 162, 161, 3, 161);
	printf("\n%c!  4.- Lista de %ctems.\n%c!  5.- Limpiar pantalla.\n%c!  6.- Salir y crear archivo.\n\n", 3, 161, 3, 3);
	scanf_s("%d", &opc);

	switch (opc)//Switch principal; menú de opciones!!
	{
	case 1: //ALTA ^^

		Alta();
		return main();
		break;

	case 2: //MOD ^^

		Mod();
		return main();
		break;

	case 3: //BAJA ^^

		Baja();
		return main();
		break;

	case 4: //LISTA ^^

		Lista();
		return main();
		break;

	case 5: //LIMPIAR PANTALLA ^^

		system("cls");
		return main();
		break;

	case 6: //SALIR Y CREAR ARCHIVO ^^
		Archivos();
		exit(1);
		break;
	}
}


//Funciones:

void Alta()
{
	int num_error = 0, j = 0;//num_error lo utilizamos para verificar que los No. de registros no se repitan.

	printf("%cCu%cntos %ctems desea dar de alta?\n", 168, 160, 161);
	scanf_s("%d", &n); //Arreglo dinámico

	item = new tiendita[n]; //"new" para crear arreglo con los "n" registros deseados

	for (int i = 0; i < n; i++)
	{
		/*
		La estructura para leer los datos, en este caso, es:
		PUNTERO[i].VARIABLE
		*/

		printf("\n%c ¡Nuevo %ctem!\n", 1, 161);

		do//DO-WHILE se utiliza aquí para evitar No. de registros repetidos;
		{
			printf("\n\t(%c) No. del nuevo %ctem: \n", 4, 161);
			scanf_s("%d", &item[i].numit);

			for (j = 0; j < i; j++)
			{
				if (item[i].numit == item[j].numit)
				{
					num_error = 1;
					printf("\nError :( ! No es posible repetir No. de registro.\n");
				}
				else
				{
					num_error = 2;
				}
			}
		} while (num_error == 1);

		printf("\n\t(%c) T%ctulo del %ctem: \n", 4, 161, 161);
		cin.ignore();
		getline(cin, item[i].nameit);

		printf("\n\t(%c) Descripci%cn del %ctem: \n", 4, 162, 161);
		getline(cin, item[i].descit);

		printf("\n\t(%c) G%cnero del %ctem: \n", 4, 130, 161);
		getline(cin, item[i].genit);

		printf("\n\t(%c) Clasificaci%cn de edad del %ctem: \n", 4, 162, 161);
		getline(cin, item[i].clasifit);

		printf("\n\t(%c) Consola compatible al %ctem: \n", 4, 161);
		getline(cin, item[i].consit);

		printf("\n\t(%c) Precio del %ctem: \n", 4, 161);//SUBTOTAL
		scanf_s("%f", &item[i].precioit);
		item[i].ivait = item[i].precioit * 0.16;
		item[i].totit = item[i].precioit + item[i].ivait;
	}

}


void Mod()
{
	int j, opc1, valido;
	do//Do-While INICIO
	{
		printf("\nIngrese el No. de registro que desea modificar:\n");
		scanf_s("%d", &j);
		j = j - 1;//Esto porque "i" inicia en 0; por ejemplo, el registro 1 ("j") es i=0

		for (int i = j; i == j; i++)
		{
			if ((item[i].status == "ELIMINADO"))
			{
				printf("\nREGISTRO %d ELIMINADO\n", i + 1);
				printf("\nIngrese un No. de registro v%clido:\n", 160);
				valido = 2;
			}
			else
			{
				valido = 1;//Para terminar nuestro DO-WHILE y continuar con la modificación
			}
		}
	} while (valido == 2);//Do-While FIN

	printf("\n%cQu%c desea modificar?\n[%c] 1.- T%ctulo.\n[%c] 2.- Descripci%cn.\n[%c] 3.- G%cnero.\n[%c] 4.- Clasificaci%cn de edad.", 168, 130, 26, 161, 26, 162, 26, 130, 26, 162);
	printf("\n[%c] 5.- Consola compatible.\n[%c] 6.- Precio.\n", 26, 26);
	scanf_s("%d", &opc1);

	switch (opc1)//Switch de modificación
	{
	case 1://TÍTULO Mod
		for (int i = j; i == j; i++)
		{
			printf("\n\tT%ctulo del %ctem:", 161, 161);
			cin.ignore();
			getline(cin, item[i].nameit);
		}
		break;

	case 2://DESCRIPCIÓN Mod
		for (int i = j; i == j; i++)
		{
			printf("\n\tDescripci%cn del %ctem:", 162, 161);
			cin.ignore();
			getline(cin, item[i].descit);
		}
		break;

	case 3://GÉNERO Mod
		for (int i = j; i == j; i++)
		{
			printf("\n\tG%cnero del %ctem:", 130, 161);
			cin.ignore();
			getline(cin, item[i].genit);
		}
		break;

	case 4://CLASIFICACIÓN DE EDAD Mod
		for (int i = j; i == j; i++)
		{
			printf("\n\tClasificaci%cn de edad del %ctem:", 162, 161);
			cin.ignore();
			getline(cin, item[i].clasifit);
		}
		break;

	case 5://CONSOLA COMPATIBLE Mod
		for (int i = j; i == j; i++)
		{
			printf("\n\tConsola compatible al %ctem:", 161);
			cin.ignore();
			getline(cin, item[i].consit);
		}
		break;

	case 6://PRECIO Mod
		for (int i = j; i == j; i++)
		{
			printf("\n\tPrecio del %ctem:", 161);
			scanf_s("%f", &item[i].precioit);

			item[i].ivait = item[i].precioit * 0.16;
			item[i].totit = item[i].precioit + item[i].ivait;
		}
		break;

	}
}


void Baja()
{
	int j=0;
	printf("\n%c Ingrese el No. de registro a eliminar: \n", 16);
	scanf_s("%d", &j);
	j = j - 1;//Esto porque "i" inicia en 0; por ejemplo, el registro 1 ("j") es i=0

	for (int i = j; i == j; i++)
	{
		printf("\n\tEliminando registro %d...%c\n\t¡Registro eliminado!^^\n", j + 1, 2);
		item[i].status = "ELIMINADO";
	}

}


void Lista()
{
	for (int i = 0; i < n; i++)
	{
		if (item[i].status == "ELIMINADO")
		{
			printf("\n\t%c REGISTRO %d ELIMINADO %c\n", 16, i + 1, 2);
		}
		else
		{
			printf("\n\t%c REGISTRO %d", 16, item[i].numit);

			printf("\n%c T%ctulo:\n%s", 4, 161, item[i].nameit.c_str());

			printf("\n%c Descripci%cn:\n%s", 4, 162, item[i].descit.c_str());

			printf("\n%c G%cnero:\n%s", 4, 130, item[i].genit.c_str());

			printf("\n%c Clasificaci%cn:\n%s", 4, 162, item[i].clasifit.c_str());

			printf("\n%c Consola compatible:\n%s", 4, item[i].consit.c_str());

			printf("\n%c Subtotal: $%0.2f", 6, item[i].precioit);
			printf("\n%c IVA: $%0.2f", 6, item[i].ivait);
			printf("\n%c Total: $%0.2f\n", 6, item[i].totit);

		}
	}

}



void Archivos()
{
	ofstream archivo; //"OFSTREAM" PARA ESCRIBIR ARCHIVOS
	string namearchivo;
	int texto;
	float texto1;
	string texto2;

	namearchivo = "itemstiendita.txt";

	archivo.open(namearchivo.c_str(), ios::out); //Para abrir archivo

	if (archivo.fail())//Si ocurre un error al intentar crear el archivo...
	{
		printf("\n\tHa ocurrido un error %c\n\tNo fue posible abrir el archivo.", 2);
		exit(1);
	}

	/*
	cout <<    ..."<<" se utilizan para imprimir algo en pantalla
	*/

	archivo << "\n\tGameStop!! > < !! <3\n\n";
	archivo << "No. ITEM\t";
	archivo << "TITULO\t";
	archivo << "DESCRIPCION\t";
	archivo << "\tGENERO\t";
	archivo << "\tCLASIF. DE EDAD\t";
	archivo << "CONSOLA COMPATIBLE\t";
	archivo << "SUBTOTAL\t";
	archivo << "IVA\t";
	archivo << "\tTOTAL\t";
	archivo << "\tSTATUS\t\n";//"\n" aquí sirve para hacer salto de línea y continuar escribiendo info. en la segunda línea

	for (int i = 0; i < n; i++)
	{
		if (item[i].status == "ELIMINADO")
		{
			texto2 = "REGISTRO ELIMINADO ";
			texto = item[i].numit;
			archivo << texto2 << texto << "\n";
		}
		else
		{
			texto = item[i].numit;
			archivo << texto << "\t" << "\t";

			texto2 = item[i].nameit;
			archivo << texto2 << "\t" << "\t";

			texto2 = item[i].descit;
			archivo << texto2 << "\t " << "\t";

			texto2 = item[i].genit;
			archivo << texto2 << "\t " << "\t";

			texto2 = item[i].clasifit;
			archivo << texto2 << "\t " << "\t " << "\t";

			texto2 = item[i].consit;
			archivo << texto2 << "\t " << "\t " << "\t";

			texto1 = item[i].precioit;
			archivo << texto1 << "\t " << "\t";

			texto1 = item[i].ivait;
			archivo << texto1 << "\t " << "\t";

			texto1 = item[i].totit;
			archivo << texto1 << "\n";

		}
	}
	archivo.close();

}