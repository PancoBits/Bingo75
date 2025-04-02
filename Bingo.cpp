#include<stdlib.h> /*Incluimos las Librerias*/
#include<stdio.h>
#include<conio.h>
#include<time.h> /*Incluimos la Librer?a <time.h>, para poder generar los n?meros aleatorios del bingo*/
#include<ctype.h>
#define MAX_STRLEN 256
/*
	Hecho por:
	Jesús Ruiz
	Franco Rodríguez
	Realizado en Abril 2023
*/

//Declaramos las funciones que usaremos
void Anim();
void reglas_ganar();
void Azar(int PCarton[4][5][5]); /*Funcion de asignacion de valores alatorios al carton*/
void Tab(int PCarton[4][5][5]); /*Funcion de mostrar el Carton*/
void reg(); /*Funcion de regresar al menu*/
void NJug(int PCarton[4][5][5]); /*Funcion que nos ayudara a mostrar los cartones junto a los nombres*/
void NRam(int PCarton[4][5][5]); /*Funcion que genera un numero ramdon y comprueba en los cartones*/
void Win(int PCarton[4][5][5]); /*Funcion que comprobara si se gano*/
void Estad(int PCarton[4][5][5]); /*Funcion que mostrara las Estadisticas Finales*/
void Era(); /*Funcion que reiniciara los valores, por si se quiere jugar otra partida*/
void MostrarNum(int PCarton[4][5][5]); /*Funcion de Estadistica que ayuda a mostar los numeros del patron escogido*/
void numfalta(int PCarton[4][5][5]);  // Funcino para mostrar los numeros que faltaron en el patron para ganar
//Declaramos algunas variables globales
int b,x,rb,ri,rn,rg,ro,AuxPos[75],r,c,p,t,j=0,Auxj,Auxx,numj,w,AcertN[4],ganador[4],nwin=0,i,o,m,e,es,AuxCarton[4][5][5],y,Ne[4]; //Ramon: Declare pl para poder usar el switch y escoger la forma de ganar. Declare ganador para escoger al ganador
bool talque,ret,cic,jes;
char s,resp,opc,pl,nj,g,car[4][MAX_STRLEN],Est;

int main(){
	int PCarton[4][5][5]; /*Declaramos la matriz que usaremos durante el main*/
	do{
		do {
			talque=false; /*le asignamos false para que salga del bucle, si es que no cambia su valor*/
			system("cls");
			Anim();
			printf("\t       _____                                 _____\n");
			printf("\t      (_____)-------------------------------(_____)\n");
			printf("\t       | / |                                 | / |\n");
			printf("\t       | / |            [1] Jugar            | / |\n");
			printf("\t       | / |                                 | / |\n");
			printf("\t       | / |            [2] Reglas           | / |\n");
			printf("\t       | / |                                 | / |\n");
			printf("\t       | / |            [3] Salir            | / |\n");
			printf("\t       | / |                                 | / |\n");
			printf("\t      (_____)-------------------------------(_____)\n\n");
			printf("\t\t\t-> ");
			scanf("%c",&resp); /*Guardamos el valor de "resp" que nos ayudara en el "switch" de más adelante*/
			fflush(stdin);
			if (resp=='1' || resp=='2' || resp=='3'){ /*se sale del bucle si se selecciona una de las opciones */
				talque=false;
			} else {
				printf ("\n Ingrese una opci%cn correcta\n",162);
				talque=true; /*Hacemos "talque=true" para que no salga del bucle*/
				system ("timeout /t 3");
			}
		} while (talque!=false); /*Mientras sea "false" sale del bucle*/
	
	switch (resp){ /*Usando la respuesta anterior, manejaremos las intrucciones*/
		case '1': /*En el caso 1 se ejecutaria las funciones y todo lo que tiene que ver con la ejecución del juego*/
			do{
				system("cls");
				printf("  _____                                  _____\n");
				printf(" (_____)--------------------------------(_____)\n");
				printf("  | / |                                  | / |\n");
				printf("  | / |  Escoje el patr%cn que se jugar%c  | / |\n",162,160);
				printf("  | / |         en la partida            | / |\n");
				printf("  | / |                                  | / |\n");
				printf("  | / |        [1] L%cneas                | / |\n",161);
				printf("  | / |                                  | / |\n");
				printf("  | / |        [2] Cruz                  | / |\n");
				printf("  | / |                                  | / |\n");
				printf("  | / |        [3] Marco                 | / |\n");
				printf("  | / |                                  | / |\n");
				printf("  | / |        [4] Cubrir Todo           | / |\n");
				printf("  | / |                                  | / |\n");
				printf(" (_____)--------------------------------(_____)\n\n");
				printf("\t -> ");
				scanf("%c",&pl);
				fflush(stdin);
				if(pl=='1' || pl=='2' || pl == '3' || pl=='4'){ //Dependiendo del valor de pl, se usara mas adelante para determinar la forma de ganar con un switch
					talque=false;
				}
				else{
					printf ("\n Ingrese una opci%cn correcta\n",162);
					talque=true;
					system ("timeout /t 3");
				}
			}while (talque!=false);
			
			do {
				/*Preguntamos la cantidad de jugadores, para generar "X" número de cartones*/
				system("cls");
				printf("  _____                                 _____\n");
				printf(" (_____)-------------------------------(_____)\n");
				printf("  | / |                                 | / |\n");
				printf("  | / |    %cCu%cntos jugadores ser%cn?    | / |\n",168,160,160);
				printf("  | / |                                 | / |\n");
				printf("  | / |        [1] Jugadores 2          | / |\n");
				printf("  | / |                                 | / |\n");
				printf("  | / |        [2] Jugadores 3          | / |\n");
				printf("  | / |                                 | / |\n");
				printf("  | / |        [3] Jugadores 4          | / |\n");
				printf("  | / |                                 | / |\n");
				printf(" (_____)-------------------------------(_____)\n\n");
				printf("\t -> ");
				scanf("%c",&nj);
				fflush(stdin);
				if (nj=='1' || nj=='2' || nj=='3'){ /*Se repite el mismo mecanismo del bucle anterior*/
					talque=false;
				} else {
					printf ("\n Ingrese una opci%cn correcta\n",162);
					talque=true;
						system ("timeout /t 5");
				}
			} while (talque!=false);
			
			numj=1;
			switch(nj){ /*Dependiendo del valor de nj se determina cuantos jugadores*/
				case '1':
					system ("cls");
					j=0; /*Hacemos j=0 ya que dentro de las funciones nos servira*/
					for(s='0';s<=nj;s++){ /*Se repetiria 2 veces ya que "s" empieza en 0 y "nj=1"*/
						NJug(PCarton); /*Llamamos a la funcion que pedira el nombre y mostrara el carton referente*/
					}
					fflush(stdin);
					break;
				case '2':
					system ("cls");
					j=0;
					for(s='0';s<=nj;s++){ /*Se repetiria 3 veces ya que "s" empieza en 0 y "nj=2"*/
						NJug(PCarton);
					}
					fflush(stdin);
					break;
				case '3':
					system ("cls");
					j=0;
					for(s='0';s<=nj;s++){ /*Se repetiria 4 veces ya que "s" empieza en 0 y "nj=3"*/
						NJug(PCarton);
					}
					fflush(stdin);
					break;
			}
			
			Auxj=j;		
			
			for (b=0;b<75;b++){ /*Hacemos un bucle que se repetira en todos los valores de la "Posicion Aux" y los reiniciara en 0*/
				AuxPos[b]=0; 
			}
			
			nwin=0;
			
			for (j=0;j<Auxj;j++){ /*j es el numero del carton del jugador*/
				for (Auxx=0;Auxx<5;Auxx++){ /*Auxx es la casilla horizontal*/
					for (p=0;p<5;p++){ /*p es la casilla vertical*/
						AuxCarton[j][Auxx][p]=PCarton[j][Auxx][p]; /*Hacemos una copia de todos los cartones, ya que nos servira mas adelante*/
					}
				}
			}
			
			do {
				talque=false;
				system("cls");
				printf("  _____                                      _____\n");
				printf(" (_____)------------------------------------(_____)\n");
				printf("  | / |                                      | / |\n");
				printf("  | / |    %cC%cmo quieres que se muestren     | / |\n",168,162);
				printf("  | / |          los n%cmeros al azar?        | / |\n",163);
				printf("  | / |                                      | / |\n");
				printf("  | / |   [1] Con una pausa hasta que        | / |\n");
				printf("  | / |   presione enter.                    | / |\n");
				printf("  | / |                                      | / |\n");
				printf("  | / |   [2] Con tiempo de espera para      | / |\n");
				printf("  | / |   ver los cambios del carton.        | / |\n");
				printf("  | / |                                      | / |\n");
				printf("  | / |   [3] Automaticamente se generan     | / |\n");
				printf("  | / |   los n%cmeros y al final se muestre  | / |\n",163);
				printf("  | / |   quien gana.                        | / |\n");
				printf("  | / |                                      | / |\n");
				printf(" (_____)------------------------------------(_____)\n\n");
				printf("\t -> ");
				scanf("%c",&g);
				fflush(stdin);
				if (g=='1' || g=='2' || g=='3'){ /*Se repite el mismo mecanismo del bucle anterior*/
					talque=false;
				} else {
					printf ("\n Ingrese una opci%cn correcta\n",162);
					talque=true;
						system ("timeout /t 5");
				}
			} while (talque!=false);
			srand(time(NULL));
			system ("cls");
			printf (" Pulsa enter para generar el n%cmero aleatorio\n",163);
			getch();
			do{
				fflush(stdin);
				NRam(PCarton); /*Llamamos a funcion que genera el numero ramdon*/
				Win(PCarton); /*Comprobamos si se cumplen las condiciones para ganar*/
				for (w=0;w<Auxj;w++){ /*Un bucle que comprobara si se gana, hay empate o no paso nada*/
					if (ganador[w]==1){ /*Si hay un Ganador guardamos el numero del carton*/
						if (nwin==0){ /*Esto solo pasara la primera vez, para que por lo menos haya un ganador*/
							nwin++; /*Aumentamos el valor para que no vuelva a entrar*/
							i=w; /*Guardamos el valor del numero del carton en otra variable, que servira para evitar empates*/
							o=0; /*Esta variable nos ayudara mas adelante cuando se vaya a llamar al ganador*/
						} else if(AcertN[w]<AcertN[i]){ 
							if ((Auxj-w)==1){ /*Si es el ultimo carton, significa que aun puede llegar a ser empate*/
								if(AcertN[m]==AcertN[i]){  /*Entonces con la variable que le dimos el valor del carton de empate anteriormente, si son iguales significa que es un empate definitivo*/
						 			o=1; /*Hacemos o=1 para que mas adelante marque es un empate*/
								}
							}
						} else if(AcertN[w]>AcertN[i]){/*Si el numero de aciertos del primer ganador es menor al segundo ganador*/
						 	i=w; /*El numero de carton actual pasara sobreescribir el valor anterior que ya no seria el ganador*/
						 	o=0;
						
						} else if(AcertN[w]==AcertN[i]){ /*Si se cumple que el anterior ganador es igual al actual*/
							Ne[w]=w;
							Ne[i]=i;
							m=w; /*Guardamos el valor del numero del carton en otra variable para evitar errores mas adelante*/
						 	if ((Auxj-w)==1){ /*Si es el ultimo carton, significa que es un empate*/
						 		o=1;
						 	}
						}
					}
				}
			} while (nwin==0);
			
			printf ("\n El juego ha terminado...\n Pulsa enter para mostrar estad%csticas finales",161);
			getch();
			fflush(stdin);
			Estad(PCarton);
			printf ("\n");
			Era();
			fflush(stdin);
			break;
		case '2':
			system ("cls");
			reglas_ganar();
			system("cls");
			fflush(stdin);
			break;
		case '3':
			cic= false;
			system ("cls"); /*Borramos la Pantalla*/
			printf ("Hasta la Pr%cxima...\n",162);
			system ("timeout /t 3"); /*Cuenta regresiva para cerrar la Ventana*/
			fflush(stdin);
			break;
		default:
			printf ("\nEscoge una opci%cn correcta",162); /*Opcion default si no se selecciona una respuesta correcta*/
			system ("timeout /t 3");
			cic = true;	 /*Hacemos el valor de "cic" True para que se repita el bucle y regrese al menu*/
	}
		
	} while (cic!=false);
	return 0;
}

void NJug(int PCarton[4][5][5]){ /*Esta funcion es la que nos permite Pedir y mostrar los nombres de los jugadores, ademas de mostrar en pantalla los cartones*/
	system ("cls");
	printf (" ---------------------------------------\n");
	printf (" | %cCu%cl es el Nombre del Jugador (%d)? |",168,160,numj); /*Pedimos el Nombre del Jugador*/
	printf ("\n ---------------------------------------\n\n ");
	scanf ("%[^\n]",&car[j]); /*Guardamos el Nombre del Jugador usando la Sintaxis "[^\n]" para almacenar X N° de carácteres hasta un Salto de Línea*/
	fflush(stdin); /*Usamos esta Instrucción para limpiar la memoria y evitar que se sobrepongan los datos*/
	do{
		system ("cls");
		Azar(PCarton); /*Llamamos a la función del Azar, que genera los numeros del Carton del bingo*/
		Tab(PCarton); /*Llamamos a la función del Tab, que genera el Carton del bingo*/
		printf ("\n --------------\n");
		printf (" | Cart%cn de: | ~ %s ~",162,car[j]); /*Mostramos al final del carton el nombre del jugador*/
		printf ("\n --------------\n");
		do {
			talque=false;
			printf ("\n %cAceptas el cart%cn?\n",168,162,163); /*Repite la misma estructura, que las que hemos usado anteriormente en el programa*/
			printf("\n(1) Si");
			printf("\n(2) No\n");
			printf(" -> ");
			scanf("%c",&opc);
			fflush(stdin);
			switch (opc){
				case '1':
					ret=false;
					fflush(stdin);
					break;
				case '2':
					for (b=0;b<75;b++){ /*Hacemos un bucle que se repetira en todos los valores de la "Posicion Aux" y los reiniciara en 0 (Para evitar que se genere incompleto)*/
						AuxPos[b]=0; 
					}
					ret=true;
					fflush(stdin);
					break;
				default:
					printf ("\nEscoge una opci%cn correcta\n",162);
					talque=true;
					system ("timeout /t 3");
				}
			} while (talque!=false);	
	} while (ret!=false);
	j++; /*Aumenta el valor de j, para que se vea reflejado en las funciones correctamente*/
	numj++; /*Aumenta el valor de numj, para que se vea reflejado en el numero del jugador*/
}

void Tab(int PCarton[4][5][5]){
	printf ("   ------------------------- \n"); /*Mostramos el Encabezado del Juego, que no va a variar*/
	printf ("  |  B    I    N    G    O  |\n");
	printf ("   ------------------------- \n");
	printf ("   ________________________   \n");
	printf ("  |    |    |    |    |    |  ");
	for (x=0;x<5;x++){
		if(x==2){ /*Con esta condicion hacemos que el medio quede vacio*/
			if (PCarton[j][x][0]<10){ /*Con esta condicion evitamos problemas por la parte grafica, cuando no es un número de 2 cifras*/
				printf ("\n  | 0%d | %d | TT | %d | %d |  ",PCarton[j][x][0],PCarton[j][x][1],PCarton[j][x][3],PCarton[j][x][4]);
				printf ("\n  |____|____|____|____|____|  \n"); /*Mostramos los respectivos valores acotados que obtuvimos gracias a la función "Azar", en la matriz*/
			}else {
				printf ("\n  | %d | %d | TT | %d | %d |  ",PCarton[j][x][0],PCarton[j][x][1],PCarton[j][x][3],PCarton[j][x][4]);
				printf ("\n  |____|____|____|____|____|  \n");
			}
		} else { /*PCarton[j=El carton del jugador número][x=la Casilla Horizontal][La posicion Vertical B=0,I=1,N=2,G=3,O=4]*/
			if (PCarton[j][x][0]<10){ /*La misma condicion para evitar problemas por la parte grafica, cuando no es un número de 2 cifras */
				printf ("\n  | 0%d | %d | %d | %d | %d |  ",PCarton[j][x][0],PCarton[j][x][1],PCarton[j][x][2],PCarton[j][x][3],PCarton[j][x][4]);
				printf ("\n  |____|____|____|____|____|  \n");
			} else {
				printf ("\n  | %d | %d | %d | %d | %d |  ",PCarton[j][x][0],PCarton[j][x][1],PCarton[j][x][2],PCarton[j][x][3],PCarton[j][x][4]);
				printf ("\n  |____|____|____|____|____|  \n");
			}
		}
		if (x<4){ /*Otra condicion pra que cuando este en el ultimo "for" no se muestre esta parte*/
			printf ("  |    |    |    |    |    |  ");
		}
	}
}

void Win(int PCarton[4][5][5]){
	for(w=0;w<Auxj;w++){
		switch(pl){ //dependiendo de la forma de ganar que se selecciono, pl va a ser igual a uno de estos casos

			case '1': //Ganar de Forma Lineal
						
				//Ganar de Forma horizontal
					
				if (PCarton[w][0][0] == PCarton[w][0][1] && PCarton[w][0][1] == PCarton[w][0][2] && PCarton[w][0][2] == PCarton[w][0][3] && PCarton[w][0][3] == PCarton[w][0][4]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][1][0] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][1][4]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][2][0] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][2][4]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][3][0] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][3][3] && PCarton[w][3][3] == PCarton[w][3][4]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][4][0] == PCarton[w][4][1] && PCarton[w][4][1] == PCarton[w][4][2] && PCarton[w][4][2] == PCarton[w][4][3] && PCarton[w][4][3] == PCarton[w][4][4]){
					ganador[w] = 1;		
				}
		
				//Ganar de Forma Vertical
						
				else if (PCarton[w][0][0] == PCarton[w][1][0] && PCarton[w][1][0] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][3][0] && PCarton[w][3][0] == PCarton[w][4][0]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][0][1] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][4][1]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][0][2] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][4][2]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][0][3] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][3][3] && PCarton[w][3][3] == PCarton[w][4][3]){
					ganador[w] = 1;		
				}
				else if (PCarton[w][0][4] == PCarton[w][1][4] && PCarton[w][1][4] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][4] && PCarton[w][3][4] == PCarton[w][4][4]){
					ganador[w] = 1;		
				}
						
				//Ganar de Forma Oblicua
						
				else if(PCarton[w][0][0] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton [w][3][3] && PCarton [w][3][3] == PCarton [w][4][4]){
					ganador[w] = 1;
				}
				else if(PCarton[w][0][4] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton [w][3][1] && PCarton [w][3][1] == PCarton [w][4][0]){
					ganador[w] = 1;
				}
					
				fflush(stdin);
				break;
						
			case '2': //Ganar con una cruz
					
				//Ganar con Cruz Pequeña
					
				if (PCarton[w][1][2] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][3][2]){
					ganador[w] = 1;
				}
					
				//Ganar con Cruz Grande
					
				if (PCarton[w][0][2] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][4][2]){
					ganador[w] = 1;
				}
						
				fflush(stdin);
				break;
						
			case '3': //Ganar con un marco
					
				//Ganar con un marco interno
						
				if (PCarton[w][1][1] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][3][3]){
					ganador[w] = 1;
				}
			
				//Ganar con un marco externo
				
				if (PCarton[w][0][0] == PCarton[w][0][1] && PCarton[w][0][1] == PCarton[w][0][2] && PCarton[w][0][2] == PCarton[w][0][3] && PCarton[w][0][3] == PCarton[w][0][4] && PCarton[w][0][4] == PCarton[w][1][0] && PCarton[w][1][0] == PCarton[w][1][4] && PCarton[w][1][4] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][0] && PCarton[w][3][0] == PCarton[w][3][4] && PCarton[w][3][4] == PCarton[w][4][0] && PCarton[w][4][0] == PCarton[w][4][1] && PCarton[w][4][1] == PCarton[w][4][2] && PCarton[w][4][2] == PCarton[w][4][3] && PCarton[w][4][3] == PCarton[w][4][4] ){
					ganador[w] = 1;
				}
				
				fflush(stdin);
				break;

			case '4': //Ganar cubriendo todo
				
				if (PCarton[w][0][0] == PCarton[w][0][1] && PCarton[w][0][1] == PCarton[w][0][2] && PCarton[w][0][2] == PCarton[w][0][3] && PCarton[w][0][3] == PCarton[w][0][4] && PCarton[w][0][4] == PCarton[w][1][0] && PCarton[w][1][0] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][1][4] && PCarton[w][1][4] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][0] && PCarton[w][3][0] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][3][3] && PCarton[w][3][3] == PCarton[w][3][4] && PCarton[w][3][4] == PCarton[w][4][0] && PCarton[w][4][0] == PCarton[w][4][1] && PCarton[w][4][1] == PCarton[w][4][2] && PCarton[w][4][2] == PCarton[w][4][3] && PCarton[w][4][3] == PCarton[w][4][4]){
					ganador[w] = 1;
				}
						
				fflush(stdin);
				break;	
		}
	}
}

void Estad (int PCarton[4][5][5]){
	do{
		do{
			system("cls");
			printf("  _____                                   _____\n");
			printf(" (_____) - ESTAD%cSTICAS - DEL - BINGO -  (_____)\n",214);
			printf("  | / |                                   | / |\n");
			printf("  | / |  [1] Cart%cn ganador               | / |\n",162);
			printf("  | / |                                   | / |\n");
			printf("  | / |  [2] N%cmeros que conforman el     | / |\n",163);
			printf("  | / |  patr%cn del juego (Ganador).      | / |\n",162);
			printf("  | / |                                   | / |\n");
			printf("  | / |  [3] Cantidad de n%cmeros que      | / |\n",163);
			printf("  | / |  fueron acertados en cada cart%cn. | / |\n",162);
			printf("  | / |                                   | / |\n");
			printf("  | / |  [4] N%cmeros que faltaron en cada | / |\n",163);
			printf("  | / |  cart%cn para lograr el patr%cn.    | / |\n",162,162);
			printf("  | / |                                   | / |\n");
			printf("  | / |  [5] Volver al men%c               | / |\n",163);
			printf("  | / |                                   | / |\n");
			printf(" (_____)---------------------------------(_____)\n\n");
			printf("\t -> ");
			scanf("%c",&Est);
			fflush(stdin);
			if(Est =='1' || Est =='2' || Est == '3' || Est =='4' || Est =='5'){ //Dependiendo del valor de pl, se usara mas adelante para determinar la forma de ganar con un switch
				talque=false;
			}else{
				printf ("\n Ingrese una opci%cn correcta\n",162);
				talque=true;
				system ("timeout /t 3");
			}
		}while (talque!=false);
		
		switch (Est){
			case '1':
				if(o==1){
					printf ("\n - Hay un Empate\n");
				} else{
					printf ("\n ------------------\n");
					printf (" | El ganador es: | ~ %s ~",car[i]); /*Mostramos al final del carton el nombre del jugador*/
					printf ("\n ------------------\n\n");
					j=i;
					Tab(PCarton);
				}
				printf("\n (Presionar cualquier tecla para volver)");
	   			getch();
	   			talque=true;
				fflush(stdin);
				break;
			case '2':
				if(o==1){
					printf ("\n - Como hay un Empate se muestran todos los numeros de los empatados\n");
					for (x=0;x<Auxj;x++){
						if (Ne[x]!=0){
							w=Ne[x];
							printf("\n - Los n%cmeros que conforman patron de %s son: ",163,AcertN[w]);
							MostrarNum(PCarton);
							printf ("\n");
						}
					}
				} else{
					w=i;
					printf("\n - Los n%cmeros que conforman el patron del Ganador %s son:\n ",163,car[i]);
					MostrarNum(PCarton);
				}
				printf("\n\n (Presionar cualquier tecla para volver)");
	   			getch();
	   			talque=true;
				fflush(stdin);
				break;
			case '3':
				for(es=0;es<Auxj;es++){ 
					printf ("\n - N%cmeros acertados del cart%cn de: %s (%d)\n",163,162,car[es],AcertN[es]);
				}
				printf("\n (Presionar cualquier tecla para volver)");
	   			getch();
	   			talque=true;
				fflush(stdin);
				break;
			case '4':
				for(es=0;es<Auxj;es++){ 
					printf("\n - N%cmeros que le faltaron a %s para completar el patr%cn: \n",163,car[es],162);
					w=es;
					numfalta(PCarton);
					printf ("\n\n");	
				}
				printf("\n\n (Presionar cualquier tecla para volver)");
				talque=true;
	   			getch();
				fflush(stdin);
				break;
			case '5':
				cic=true;
				talque=false;
				fflush(stdin);
				break;
		}	
	}while(talque!=false);
}

void MostrarNum(int PCarton[4][5][5]){
		switch(pl){ //dependiendo de la forma de ganar que se selecciono, pl va a ser igual a uno de estos casos

			case '1': //Ganar de Forma Lineal
						
				//Ganar de Forma horizontal
					
				if (PCarton[w][0][0] == PCarton[w][0][1] && PCarton[w][0][1] == PCarton[w][0][2] && PCarton[w][0][2] == PCarton[w][0][3] && PCarton[w][0][3] == PCarton[w][0][4]){	
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][0][x]);
					}
				}
				else if (PCarton[w][1][0] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][1][4]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][1][x]);
					}	
				}
				else if (PCarton[w][2][0] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][2][4]){
					for (x=0;x<5;x++){
						if (AuxCarton[w][2][x]!=0){
							printf ("(%d) ",AuxCarton[w][2][x]);
						}
					}	
				}
				else if (PCarton[w][3][0] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][3][3] && PCarton[w][3][3] == PCarton[w][3][4]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][3][x]);
					}	
				}
				else if (PCarton[w][4][0] == PCarton[w][4][1] && PCarton[w][4][1] == PCarton[w][4][2] && PCarton[w][4][2] == PCarton[w][4][3] && PCarton[w][4][3] == PCarton[w][4][4]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][4][x]);
					}		
				}
		
				//Ganar de Forma Vertical
						
				else if (PCarton[w][0][0] == PCarton[w][1][0] && PCarton[w][1][0] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][3][0] && PCarton[w][3][0] == PCarton[w][4][0]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][x][0]);
					}		
				}
				else if (PCarton[w][0][1] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][4][1]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][x][1]);
					}			
				}
				else if (PCarton[w][0][2] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][4][2]){
					for (x=0;x<5;x++){
						if (AuxCarton[w][x][2]!=0){
							printf ("(%d) ",AuxCarton[w][x][2]);
						}
					}			
				}
				else if (PCarton[w][0][3] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][3][3] && PCarton[w][3][3] == PCarton[w][4][3]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][x][3]);
					}			
				}
				else if (PCarton[w][0][4] == PCarton[w][1][4] && PCarton[w][1][4] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][4] && PCarton[w][3][4] == PCarton[w][4][4]){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][x][4]);
					}			
				}
						
				//Ganar de Forma Oblicua
						
				else if(PCarton[w][0][0] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton [w][3][3] && PCarton [w][3][3] == PCarton [w][4][4]){
					for (x=0;x<5;x++){
						if (AuxCarton[w][x][x]!=0){
							printf ("(%d) ",AuxCarton[w][x][x]);
						}
					}		
				}
				else if(PCarton[w][0][4] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton [w][3][1] && PCarton [w][3][1] == PCarton [w][4][0]){
					y=4;
					for (x=0;x<5;x++){
						if (AuxCarton[w][x][y]!=0){
							printf ("(%d) ",AuxCarton[w][x][y]);
						}
						y--;
					}		
				}
					
				fflush(stdin);
				break;
						
			case '2': //Ganar con una cruz
					
				//Ganar con Cruz Pequeña
					
				if (PCarton[w][1][2] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][3][2]){
					printf ("(%d) ",AuxCarton[w][1][2]);
					printf ("(%d) ",AuxCarton[w][2][1]);
					printf ("(%d) ",AuxCarton[w][2][3]);
					printf ("(%d) ",AuxCarton[w][3][2]);		
				}
					
				//Ganar con Cruz Grande
					
				if (PCarton[w][0][2] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][4][2]){
					printf ("(%d) ",AuxCarton[w][0][2]);
					printf ("(%d) ",AuxCarton[w][1][2]);
					for (x=0;x<5;x++){
						if (AuxCarton[w][2][x]!=0){
							printf ("(%d) ",AuxCarton[w][2][x]);
						}
					}
					printf ("(%d) ",AuxCarton[w][3][2]);
					printf ("(%d) ",AuxCarton[w][4][2]);
				}
						
				fflush(stdin);
				break;
						
			case '3': //Ganar con un marco
					
				//Ganar con un marco interno
						
				if (PCarton[w][1][1] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][3][3]){
					for (x=1;x<4;x++){
						printf ("(%d) ",AuxCarton[w][1][x]);
					}
					printf ("(%d) ",AuxCarton[w][2][1]);
					printf ("(%d) ",AuxCarton[w][2][3]);
					for (x=1;x<4;x++){
						printf ("(%d) ",AuxCarton[w][3][x]);
					}
				}
			
				//Ganar con un marco externo
				
				if (PCarton[w][0][0] == PCarton[w][0][1] && PCarton[w][0][1] == PCarton[w][0][2] && PCarton[w][0][2] == PCarton[w][0][3] && PCarton[w][0][3] == PCarton[w][0][4] && PCarton[w][0][4] == PCarton[w][1][0] && PCarton[w][1][0] == PCarton[w][1][4] && PCarton[w][1][4] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][0] && PCarton[w][3][0] == PCarton[w][3][4] && PCarton[w][3][4] == PCarton[w][4][0] && PCarton[w][4][0] == PCarton[w][4][1] && PCarton[w][4][1] == PCarton[w][4][2] && PCarton[w][4][2] == PCarton[w][4][3] && PCarton[w][4][3] == PCarton[w][4][4] ){
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][0][x]);
					}
					for (x=1;x<4;x++){
						printf ("(%d) ",AuxCarton[w][x][0]);
						printf ("(%d) ",AuxCarton[w][x][4]);
					}
					
					for (x=0;x<5;x++){
						printf ("(%d) ",AuxCarton[w][4][x]);
					}
				}
				
				fflush(stdin);
				break;

			case '4': //Ganar cubriendo todo
				
				if (PCarton[w][0][0] == PCarton[w][0][1] && PCarton[w][0][1] == PCarton[w][0][2] && PCarton[w][0][2] == PCarton[w][0][3] && PCarton[w][0][3] == PCarton[w][0][4] && PCarton[w][0][4] == PCarton[w][1][0] && PCarton[w][1][0] == PCarton[w][1][1] && PCarton[w][1][1] == PCarton[w][1][2] && PCarton[w][1][2] == PCarton[w][1][3] && PCarton[w][1][3] == PCarton[w][1][4] && PCarton[w][1][4] == PCarton[w][2][0] && PCarton[w][2][0] == PCarton[w][2][1] && PCarton[w][2][1] == PCarton[w][2][3] && PCarton[w][2][3] == PCarton[w][2][4] && PCarton[w][2][4] == PCarton[w][3][0] && PCarton[w][3][0] == PCarton[w][3][1] && PCarton[w][3][1] == PCarton[w][3][2] && PCarton[w][3][2] == PCarton[w][3][3] && PCarton[w][3][3] == PCarton[w][3][4] && PCarton[w][3][4] == PCarton[w][4][0] && PCarton[w][4][0] == PCarton[w][4][1] && PCarton[w][4][1] == PCarton[w][4][2] && PCarton[w][4][2] == PCarton[w][4][3] && PCarton[w][4][3] == PCarton[w][4][4]){
					for (x=0;x<5;x++){ /*Auxx es la casilla horizontal*/
						for (p=0;p<5;p++){ /*p es la casilla vertical*/
							if (AuxCarton[w][x][p]!=0){
								printf ("(%d) ",AuxCarton[w][x][p]);
							}
							
						}
					}
				}
						
				fflush(stdin);
				break;	
		}
}


void Azar(int PCarton[4][5][5]){
	
	srand(time(NULL)); /*iniciamos el generador de numeros alatorios*/
	
	for (b=0;b<5;b++){ /*La "b" es la posición del bingo en B*/
		rb=rand()%15+1; /*El primer aleatorio va a ser el B (Del 1 al 15)*/
		if (AuxPos[rb]==0){ /*Comparamos si en la "Posicion Aux" ya fue ocupada la posicion*/
			AuxPos[rb]=1; /*Como ya esta ocupada la "Posicion Aux", le asignamos un valor, para que no seleccione ese numero*/
			PCarton[j][b][0]=rb; /*Guardamos el numero ramdon en la matriz del carton en la posicion B*/
		} else {
			b--;
		}
	}

	for (b=0;b<5;b++){ 
		ri=rand()%15+16; /*El Segundo Aleatorio va a ser el I (Del 16 al 30)*/
		if (AuxPos[ri]==0){ /*Comparamos si en la "Posicion Aux" ya fue ocupada la posicion*/
			AuxPos[ri]=1; /*Como ya esta ocupada la "Posicion Aux", le asignamos un valor, para que no seleccione ese n?mero*/
			PCarton[j][b][1]=ri; /*Guardamos el numero ramdon en la matriz del carton en la posicion B*/
		} else {
			b--;
		}
	}

	for (b=0;b<5;b++){ 
		rn=rand()%15+31; /*El tercer aleatorio va a ser el N (Del 31 al 45)*/
		if (AuxPos[rn]==0){ /*Comparamos si en la "Posicion Aux" ya fue ocupada la posicion*/
			AuxPos[rn]=1; /*Como ya esta ocupada la "Posicion Aux", le asignamos un valor, para que no seleccione ese n?mero*/
			PCarton[j][b][2]=rn; /*Guardamos el numero random en la matriz del carton en la posicion B*/
		} else {
			b--;
		}
	}

	for (b=0;b<5;b++){
		rg=rand()%15+46; /*El Cuarto Aleatorio va a ser el G (Del 46 al 60)*/
		if (AuxPos[rg]==0){ /*Comparamos si en la "Posicion Aux" ya fue ocupada la posicion*/
			AuxPos[rg]=1; /*Como ya esta ocupada la "Posicion Aux", le asignamos un valor, para que no seleccione ese n?mero*/
			PCarton[j][b][3]=rg; /*Guardamos el numero ramdon en la matriz del carton en la posicion B*/
		} else {
			b--;
		}
	}

	for (b=0;b<5;b++){ 
		ro=rand()%15+61; /*El ultimo aleatorio va a ser el O (Del 61 al 75)*/
		if (AuxPos[ro]==0){ /*Comparamos si en la "Posicion Aux" ya fue ocupada la posicion*/
			AuxPos[ro]=1; /*Como ya esta ocupada la "Posicion Aux", le asignamos un valor, para que no seleccione ese n?mero*/
			PCarton[j][b][4]=ro; /*Guardamos el numero ramdon en la matriz del carton en la posicion B*/
		} else {
			b--;
		}
	}

//Con este if hacemos que se reinicie la "Posicion Aux" y pueda volver a tomar valores

	if(j==1){ /*Si se cumple que "j" = 1*/
		for (b=0;b<75;b++){ /*Hacemos un bucle que se repetira en todos los valores de la "Posicion Aux" y los reiniciara en 0*/
			AuxPos[b]=0; 
		}
	}
	
	PCarton[j][2][2]=0;
}

void NRam(int PCarton[4][5][5]){
	
		r=rand()%75+1; /*Los números aleatorias seran del 1 al 75*/
		t=0;
		if (AuxPos[r]==0){ /*Comparamos si en la "Posicion Aux" ya fue ocupada la posicion*/
			AuxPos[r]=1; /*Como ya esta ocupada la "Posicion Aux", le asignamos un valor, para que no seleccione ese número*/
			printf ("\n El n%cmero generado es: (%d)\n",163,r);
			for (j=0;j<Auxj;j++){ /*c es el numero del carton del jugador*/
				for (Auxx=0;Auxx<5;Auxx++){ /*x es la casilla horizontal*/
					for (p=0;p<5;p++){ /*p es la casilla vertical*/
						if (PCarton[j][Auxx][p]==r){ /*Se cumple si en el carton Ej.0 y en las casillas x,p está el numero ramdon*/
							PCarton[j][Auxx][p]=99; /*Le asignamos un valor para identificar que ya ha sido cubierto*/
							printf ("\n Se encontro el n%cmero en el carton de: (%s)\n\n",163,car[j]);
							Tab(PCarton);
							printf ("\n --------------\n");
							printf (" | Cart%cn de: | ~ %s ~",162,car[j]); /*Mostramos al final del carton el nombre del jugador*/
							printf ("\n --------------\n");
							AcertN[j]++; /*Esta variable me ayuda a guardar la cantidad de numeros guardados de cada carton*/	
							t++; /*Variable que nos ayuda a saber si algún carton tiene el ramdon*/
							if (g=='1'){
								printf ("\n(Pulse enter para generar el pr%cximo n%cmero)\n",162,163);
								getch();
								fflush(stdin);
							} else if (g=='2'){
								system ("timeout \t 7");
							}
												
						}
					}
				}
			}
			
			if(t==0){
				printf ("\n Ning%cn cart%cn tiene el n%cmero\n",163,162,163);
				if (g=='1' || g=='2'){
					system ("timeout \t 3");
				}
									
			}
			
		} 
}

void Era(){
	
	for (b=0;b<75;b++){ /*Hacemos un bucle que se repetira en todos los valores de la "Posicion Aux" y los reiniciara en 0*/
		AuxPos[b]=0; 
	}
			
	for(x=0;x<Auxj;x++){ 
		AcertN[x]=0;
		ganador[x]=0;
		Ne[x]=0;
	}
}

void reg() { /*Esta Funcion nos ayudara para regresar o no al menu inicial*/
	do{
		printf ("%cDeseas Volver al Men%c?\n",168,163); /*Repite la misma estructura, que las que hemos usado anteriormente en el programa*/
		ret=false;
		printf("\n(1) Si");
		printf("\n(2) No\n");
		scanf("%c",&opc);
		fflush(stdin);
		if (opc=='1'){
			cic=true;
		} else if (opc=='2'){
			cic=false;
			system("cls"); /*Borramos la Pantalla*/
			printf("Hasta la Pr%cxima...\n",162);
			system("timeout /t 5"); /*Cuenta regresiva para cerrar la Ventana*/
		} else {
			printf ("\nEscoge una opci%cn correcta",162);
			ret=true;
			printf ("\n\n");	
		}	
	system("cls");
	} while (ret!=false);		
}

void numfalta(int PCarton[4][5][5]){
			switch(pl){ //dependiendo de la forma de ganar que se selecciono, pl va a ser igual a uno de estos casos

				case '1': //Ganar de Forma Lineal
				
				//Ganar de Forma horizontal
				if (PCarton[w][0][0] != PCarton[w][0][1] || PCarton[w][0][0] != PCarton[w][0][2] || PCarton[w][0][0] != PCarton[w][0][3] || PCarton[w][0][0] != PCarton[w][0][4]){
					printf("\n Los n%cmeros que faltaron para formar el patr%cn de la horizontal [1] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][0][x]!=99){
							printf (" (%d)",AuxCarton[w][0][x]);
						}		
					}
				} else {
					printf ("\n El patr%cn horizontal [1] est%c completo",162,160);
				}

				if (PCarton[w][1][0] != PCarton[w][1][1] || PCarton[w][1][0] != PCarton[w][1][2] || PCarton[w][1][0] != PCarton[w][1][3] || PCarton[w][1][0] != PCarton[w][1][4]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la horizontal [2] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][1][x]!=99){
							printf (" (%d)",AuxCarton[w][1][x]);
						}	
					}
				} else {
					printf ("\n\n El patr%cn horizontal [2] est%c completo",162,160);
				}
				
				if (PCarton[w][2][0] != PCarton[w][2][1] || PCarton[w][2][0] != PCarton[w][2][3] || PCarton[w][2][0] != PCarton[w][2][4]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la horizontal [3] son:",163,162);
					for (x=0;x<5;x++){
						if (PCarton[w][2][x]!=99 && PCarton[w][2][x]!=0){
							printf (" (%d)",AuxCarton[w][2][x]);
						}
					}	
				} else {
					printf ("\n\n El patr%cn horizontal [3] est%c completo",162,160);
				}
				
				if (PCarton[w][3][0] != PCarton[w][3][1] || PCarton[w][3][0] != PCarton[w][3][2] || PCarton[w][3][0] != PCarton[w][3][3] || PCarton[w][3][0] != PCarton[w][3][4]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la horizontal [4] son:",163,162);
					for (x=0;x<5;x++){
						if (PCarton[w][3][x]!=99){
							printf (" (%d)",AuxCarton[w][3][x]);
						}
					}	
				} else {
					printf ("\n\n El patr%cn horizontal [4] est%c completo",162,160);
				}

				if (PCarton[w][4][0] != PCarton[w][4][1] || PCarton[w][4][0] != PCarton[w][4][2] || PCarton[w][4][0] != PCarton[w][4][3] || PCarton[w][4][0] != PCarton[w][4][4]){
					printf("\n\n Los n%cmeros que faltaron para formar el patron de la horizontal [5] son:",163);
					for (x=0;x<5;x++){
						if (PCarton[w][4][x]!=99){
							printf (" (%d)",AuxCarton[w][4][x]);
						}
					}
				} else {
					printf ("\n\n El patr%cn horizontal [5] est%c completo",162,160);
				}
				
				//Ganar de Forma Vertical
						
				if (PCarton[w][0][0] != PCarton[w][1][0] || PCarton[w][0][0] != PCarton[w][2][0] || PCarton[w][0][0] != PCarton[w][3][0] || PCarton[w][0][0] != PCarton[w][4][0]){
					printf("\n\n\n Los n%cmeros que faltaron para formar el patr%cn de la vertical [1] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][x][0]!=99){
							printf (" (%d)",AuxCarton[w][x][0]);
						}
					}		
				} else {
					printf ("\n\n\n El patr%cn vertical [1] est%c completo",162,160);
				}
				
				if (PCarton[w][0][1] != PCarton[w][1][1] || PCarton[w][0][1] != PCarton[w][2][1] || PCarton[w][0][1] != PCarton[w][3][1] || PCarton[w][0][1] != PCarton[w][4][1]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la vertical [2] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][x][1]!=99){
							printf (" (%d)",AuxCarton[w][x][1]);
						}
					}			
				} else {
					printf ("\n\n El patr%cn vertical [2] est%c completo",162,160);
				}
				
				if (PCarton[w][0][2] != PCarton[w][1][2] || PCarton[w][0][2] != PCarton[w][3][2] || PCarton[w][0][2] != PCarton[w][4][2]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la vertical [3] son:",163,162);
					for (x=0;x<5;x++){
						if (PCarton[w][x][2]!=99 && PCarton[w][x][2]!=0){
							printf (" (%d)",AuxCarton[w][x][2]);
						}
					}			
				} else {
					printf ("\n\n El patr%cn vertical [3] est%c completo",162,160);
				}
				
				if (PCarton[w][0][3] != PCarton[w][1][3] || PCarton[w][0][3] != PCarton[w][2][3] || PCarton[w][0][3] != PCarton[w][3][3] || PCarton[w][0][3] != PCarton[w][4][3]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la vertical [4] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][x][3]!=99){
							printf (" (%d)",AuxCarton[w][x][3]);
						}
					}		
				} else {
					printf ("\n\n El patr%cn vertical [4] est%c completo",162,160);
				}
				
				if (PCarton[w][0][4] != PCarton[w][1][4] || PCarton[w][0][4] != PCarton[w][2][4] || PCarton[w][0][4] != PCarton[w][3][4] || PCarton[w][0][4] != PCarton[w][4][4]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la vertical [5] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][x][4]!=99){
							printf (" (%d)",AuxCarton[w][x][4]);
						}
					}		
				} else {
					printf ("\n\n El patr%cn vertical [5] est%c completo",162,160);
				}
						
				//Ganar de Forma Diagonal
						
				if(PCarton[w][0][0] != PCarton[w][1][1] || PCarton[w][0][0] != PCarton [w][3][3] || PCarton [w][0][0] != PCarton [w][4][4]){
					printf("\n\n\n Los n%cmeros que faltaron para formar el patr%cn de la diagonal [1] son:",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][x][x]!=99 && PCarton[w][x][x]!=0){
							printf (" (%d)",AuxCarton[w][x][x]);
						}		
					}
				} else {
					printf ("\n\n\n El patr%cn diagonal [1] est%c completo",162,160);
				}
				
				if(PCarton[w][0][4] != PCarton[w][1][3] || PCarton[w][0][4] != PCarton [w][3][1] || PCarton [w][0][4] != PCarton [w][4][0]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la diagonal [2] son:",163,162);
					y=4;
					for (x=0;x<5;x++){
						if(PCarton[w][x][y]!=99 && PCarton[w][x][y]!=0){
							printf (" (%d)",AuxCarton[w][x][y]);
							y--;
						}		
					}
				} else {
					printf ("\n\n El patr%cn diagonal [2] est%c completo",162,160);
				}
					
				fflush(stdin);
				break;
						
			case '2': //Ganar con una cruz
	
				//Ganar con Cruz Pequeña
					
				if (PCarton[w][1][2] != PCarton[w][2][1] || PCarton[w][1][2] != PCarton[w][2][3] || PCarton[w][1][2] != PCarton[w][3][2]){
					printf("\n Los n%cmeros que faltaron para formar el patr%cn de la cruz peque%ca son:\n",163,162,164);
					if(PCarton[w][1][2]!=99){
						printf (" (%d)",AuxCarton[w][1][2]);		
					}
					if(PCarton[w][2][1]!=99){
						printf (" (%d)",AuxCarton[w][2][1]);		
					}
					if(PCarton[w][2][3]!=99){
						printf (" (%d)",AuxCarton[w][2][3]);		
					}
					if(PCarton[w][3][2]!=99){
						printf (" (%d)",AuxCarton[w][3][2]);		
					}
				} else {
					printf ("\n El patr%cn de la cruz peque%ca est%c completo",162,164,160);
				}
					
				//Ganar con Cruz Grande
					
				if (PCarton[w][0][2] != PCarton[w][1][2] || PCarton[w][0][2] != PCarton[w][2][0] || PCarton[w][0][2] != PCarton[w][2][1] || PCarton[w][0][2] != PCarton[w][2][3] || PCarton[w][0][2] != PCarton[w][2][4] || PCarton[w][0][2] != PCarton[w][3][2] || PCarton[w][0][2] != PCarton[w][4][2]){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn de la cruz grande son:\n",163,162);
						
					if(PCarton[w][0][2]!=99){
						printf (" (%d)",AuxCarton[w][0][2]);
					}
					
					if (PCarton[w][1][2]!=99){
						printf (" (%d)",AuxCarton[w][1][2]);
					}
					
					for (x=0;x<5;x++){
						if (PCarton[w][2][x]!=99 && PCarton[w][2][x]!=0){
							printf (" (%d)",AuxCarton[w][2][x]);
						}
					}
						
					if (PCarton[w][3][2]!=99){
						printf (" (%d)",AuxCarton[w][3][2]);
					}
					if (PCarton[w][4][2]!=99){
						printf (" (%d)",AuxCarton[w][4][2]);
					}
				} else {
					printf ("\n\n El patr%cn de la cruz grande est%c completo",162,160);
				}		
				fflush(stdin);
				break;
				
			case '3': //Ganar con un marco

				//Ganar con un marco interno
						
				if (PCarton[w][1][1] != PCarton[w][1][2] || PCarton[w][1][1] != PCarton[w][1][3] || PCarton[w][1][1] != PCarton[w][2][1] || PCarton[w][1][1] != PCarton[w][2][3] || PCarton[w][1][1] != PCarton[w][3][1] || PCarton[w][1][1] != PCarton[w][3][2] || PCarton[w][1][1] != PCarton[w][3][3]){
					printf("\n Los n%cmeros que faltaron para formar el patr%cn del marco interno son:\n",163,162);
					for (x=1;x<4;x++){
						if(PCarton[w][1][x]!=99){
							printf (" (%d)",AuxCarton[w][1][x]);
						}
					}
					if(PCarton[w][2][1]!=99){
						printf (" (%d)",AuxCarton[w][2][1]);
					}
					if(PCarton[w][2][3]!=99){
						printf (" (%d)",AuxCarton[w][2][3]);
					}
					for (x=1;x<4;x++){
						if(PCarton[w][3][x]!=99){
							printf (" (%d)",AuxCarton[w][3][x]);
						}
					}
				} else {
					printf ("\n El patr%cn del marco interno est%c completo",162,160);
				}		
			
				//Ganar con un marco externo
				
				if (PCarton[w][0][0] != PCarton[w][0][1] || PCarton[w][0][0] != PCarton[w][0][2] || PCarton[w][0][0] != PCarton[w][0][3] || PCarton[w][0][0] != PCarton[w][0][4] || PCarton[w][0][0] != PCarton[w][1][0] || PCarton[w][0][0] != PCarton[w][1][4] || PCarton[w][0][0] != PCarton[w][2][0] || PCarton[w][0][0] != PCarton[w][2][4] || PCarton[w][0][0] != PCarton[w][3][0] || PCarton[w][0][0] != PCarton[w][3][4] || PCarton[w][0][0] != PCarton[w][4][0] || PCarton[w][0][0] != PCarton[w][4][1] || PCarton[w][0][0] != PCarton[w][4][2] || PCarton[w][0][0] != PCarton[w][4][3] || PCarton[w][0][0] != PCarton[w][4][4] ){
					printf("\n\n Los n%cmeros que faltaron para formar el patr%cn del marco externo son:\n",163,162);
					for (x=0;x<5;x++){
						if(PCarton[w][0][x]!=99){
							printf (" (%d)",AuxCarton[w][0][x]);
						}
					}
				
					for (x=1;x<4;x++){
						if(PCarton[w][x][0]!=99){
							printf (" (%d)",AuxCarton[w][x][0]);
						}
					}
					
					for (x=1;x<4;x++){
						if(PCarton[w][x][4]!=99){
							printf (" (%d)",AuxCarton[w][x][4]);
						}
					}

					for (x=0;x<5;x++){
						if(PCarton[w][4][x]!=99){
							printf (" (%d)",AuxCarton[w][4][x]);
						}
					}
				} else {
					printf ("\n\n El patr%cn del marco externo est%c completo",162,160);
				}
				
				fflush(stdin);
				break;
			case '4': //Ganar cubriendo todo
			
				if (PCarton[w][0][0] != PCarton[w][0][1] || PCarton[w][0][0] != PCarton[w][0][2] || PCarton[w][0][0] != PCarton[w][0][3] || PCarton[w][0][0] != PCarton[w][0][4] || PCarton[w][0][0] != PCarton[w][1][0] || PCarton[w][0][0] != PCarton[w][1][1] || PCarton[w][0][0] != PCarton[w][1][2] || PCarton[w][0][0] != PCarton[w][1][3] || PCarton[w][0][0] != PCarton[w][1][4] || PCarton[w][0][0] != PCarton[w][2][0] || PCarton[w][0][0] != PCarton[w][2][1] || PCarton[w][0][0] != PCarton[w][2][3] || PCarton[w][0][0] != PCarton[w][2][4] || PCarton[w][0][0] != PCarton[w][3][0] || PCarton[w][0][0] != PCarton[w][3][1] || PCarton[w][0][0] != PCarton[w][3][2] || PCarton[w][0][0] != PCarton[w][3][3] || PCarton[w][0][0] != PCarton[w][3][4] || PCarton[w][0][0] != PCarton[w][4][0] || PCarton[w][0][0] != PCarton[w][4][1] || PCarton[w][0][0] != PCarton[w][4][2] || PCarton[w][0][0] != PCarton[w][4][3] || PCarton[w][0][0] != PCarton[w][4][4]){
					printf("\n Los n%cmeros que faltaron para llenar todo el cart%cn son:",163,162);
					for (x=0;x<5;x++){ //Auxx es la casilla horizontal
						for (p=0;p<5;p++){ //p es la casilla vertical
							if(PCarton[w][x][p] != 99 && PCarton[w][x][p]!=0){
								printf (" (%d)",AuxCarton[w][x][p]);
							}
							
						}
					}
				} else {
					printf ("\n El patr%cn de llenar todo el cart%cn est%c completo",162,162,160);
				}		
				fflush(stdin);
				break;	
			}
	
} 


void reglas_ganar(){
	int seleccion,ciclo; //seleccion = Escoger que opción quieres en las reglas 
   	do{
		ciclo=0;
   		system ("cls");
   		printf(" _____                             _____\n");
		printf("(_____) - R - E - G - L - A - S - (_____)\n");
		printf(" | / |                             | / |\n");
		printf(" | / |     [1] %cC%cmo jugar?        | / |\n",168,162);
		printf(" | / |                             | / |\n");
		printf(" | / |                             | / |\n");
		printf(" | / |     [2] Formas de ganar     | / |\n");
		printf(" | / |                             | / |\n");
		printf(" | / |                             | / |\n");
		printf(" | / |     [3] Volver al men%c      | / |\n",163);
		printf(" | / |                             | / |\n");
		printf("(_____)---------------------------(_____)\n");
		printf("\n\t -> ");
   		scanf("%d",&seleccion);
   		fflush(stdin);
   		
   		if (seleccion==1){
   			system("cls");
   			printf(" -----------------------------------------\n");	
   			printf(" %c         %cC%cmo jugar BINGO?            %c\n",179,168,162,179);	
   			printf(" -----------------------------------------\n\n");
   			printf(" -----------------------------------------\n");
   			printf(" %c                                       %c\n",179,179);
   			printf(" %c - Bingo 75 tiene formato de cart%cn.   %c\n",179,162,179);
   			printf(" %c - Cada cart%cn cuenta con 75 n%cmeros.  %c\n",179,162,163,179);
   			printf(" %c - Se cantar%cn los n%cmeros del 1 al 75,%c\n",179,160,163,179);
   			printf(" %c si alguno coincide con un n%cmero de   %c\n",179,163,179);
   			printf(" %c tu cart%cn, ser%c marcado.              %c\n",179,162,160,179);
   			printf(" %c - Gana el primer jugador que consiga  %c\n",179,179);
   			printf(" %c el patr%cn que se seleccion%c           %c\n",179,162,162,179);
   			printf(" %c - En caso de empate se verificara     %c\n",179,179);
   			printf(" %c que jugador tiene el mayor n%cmero     %c\n",179,163,179);
   			printf(" %c de aciertos y ser%c declarado ganador. %c\n",179,160,179);
   			printf(" %c - Si el n%cmero de aciertos es igual   %c\n",179,163,179);
   			printf(" %c se declarara un empate total.         %c\n",179,179);
   			printf(" %c                                       %c\n",179,179);
   			printf(" -----------------------------------------\n");
   			printf("\n (Presionar cualquier tecla para volver)");
   			getch();
   			fflush(stdin);
   			
   		} else if(seleccion==2){
			system("cls");	
			printf(" -----------------------------------------\n");	
   			printf(" %c       Formas de ganar en BINGO         %c\n",179,179);	
   			printf(" -----------------------------------------\n\n");
   			printf(" -----------------------------------------\n");
   			printf(" %c                                       %c\n",179,179);
   			printf(" %c - Existen diferentes formas de ganar  %c\n",179,179);
   			printf(" %c                                       %c\n",179,179);
   			printf(" -----------------------------------------\n");
   			printf("\n (Oprima cualquier bot%cn para seguir)",162);
			getch();
			fflush(stdin);
			
			system("cls");
			printf(" -----------------------------------------\n");	
   			printf(" %c             Forma lineal              %c\n",179,179);	
   			printf(" -----------------------------------------\n\n");
   			printf(" - Para ganar con el modo lineal necesitas formar\n");
   			printf(" un patr%cn que forme una l%cnea vertical, diagonal\n",162,161);
   			printf(" u horizontal; desde un extremo a otro. La casilla\n");
   			printf(" del medio, al ser libre, ya se incluye como cantada.\n");
   			printf("\n         Horizontal              Vertical                         Diagonal\n");
   			printf("  ________________________         ____               ____\n");
			printf(" |    |    |    |    |    |       |    |             |    | \n");
			printf(" | 99 | 99 | 99 | 99 | 99 |       | 99 |             | 99 |\n");
			printf(" |____|____|____|____|____|       |____|             |____|____\n");
			printf("                                  |    |                  |    |\n");
			printf("                                  | 99 |                  | 99 |  \n");
			printf("                                  |____|                  |____|____\n");
			printf("                                  |    |                       |    |\n");
			printf("                                  | 99 |                       | TT |\n");
			printf("                                  |____|                       |____|____\n");
			printf("                                  |    |                            |    |\n");
			printf("                                  | 99 |                            | 99 |\n");
			printf("                                  |____|                            |____|____\n");
			printf("                                  |    |                                 |    |\n");
			printf("                                  | 99 |                                 | 99 |\n");
			printf("                                  |____|                                 |____|\n");
			printf("\n (Oprima cualquier bot%cn para seguir)",162);
   			getch();
   			fflush(stdin);
   			
   			system("cls");
   			printf(" -----------------------------------------\n");	
   			printf(" %c             Forma en cruz             %c\n",179,179);	
   			printf(" -----------------------------------------\n\n");
   			printf(" - Para ganar con el modo en cruz necesitaras\n");
   			printf(" un patr%cn que forme una cruz desde el medio, ya\n",162);
   			printf(" sea peque%ca o grande.\n",164);
   			printf("\n         Cruz peque%ca               Cruz grande\n",164);
   			printf ("            ____                        ____\n");
			printf ("           |    |                      |    |\n");
			printf ("           | 99 |                      | 99 |\n");
			printf ("       ____|____|____                  |____|\n");
			printf("      |    |    |    |                 |    |\n");
			printf("      | 99 | TT | 99 |                 | 99 |\n");
			printf("      |____|____|____|        _________|____|_________\n");
			printf("           |    |            |    |    |    |    |    |\n");
			printf("           | 99 |            | 99 | 99 | TT | 99 | 99 |\n");
			printf("           |____|            |____|____|____|____|____|\n");
			printf("                                       |    |\n");
			printf("                                       | 99 |\n");
			printf("                                       |____|\n");
			printf("                                       |    |\n");
			printf("                                       | 99 |\n");
			printf("                                       |____|\n");
			printf("\n (Oprima cualquier bot%cn para seguir)",162);
			getch();
			fflush(stdin);
   			system("cls");
   			
   			printf(" -----------------------------------------\n");	
   			printf(" %c             Forma en marco            %c\n",179,179);	
   			printf(" -----------------------------------------\n\n");
   			printf(" - Para ganar con este modo necesitaras un\n");
   			printf(" patr%cn que se forme usando todas las casillas\n",162);
   			printf(" del borde, formando un cuadrado grande. O las\n");
   			printf(" casillas que rodean el centro.\n");
   			printf("\n        Marco externo                      Marco interno\n");			
			printf("  ________________________                ______________  \n");
			printf(" |    |    |    |    |    |              |    |    |    |\n");
			printf(" | 99 | 99 | 99 | 99 | 99 |              | 99 | 99 | 99 |\n");
			printf(" |____|____|____|____|____|              |____|____|____|\n");
		    printf(" |    |              |    |              |    |    |    |\n");
			printf(" | 99 |              | 99 |              | 99 | TT | 99 |\n");
			printf(" |____|              |____|              |____|____|____|\n");
			printf(" |    |              |    |              |    |    |    |\n");
			printf(" | 99 |              | 99 |              | 99 | 99 | 99 |\n");
			printf(" |____|              |____|              |____|____|____|\n");
			printf(" |    |              |    |\n");
			printf(" | 99 |              | 99 |\n");
			printf(" |____|______________|____|\n");
			printf(" |    |    |    |    |    |\n");
			printf(" | 99 | 99 | 99 | 99 | 99 |\n");
			printf(" |____|____|____|____|____|\n");
			printf("\n (Oprima cualquier bot%cn para seguir)",162);
   			getch();
   			fflush(stdin);
   			system("cls");
   	
   			printf(" -----------------------------------------\n");	
   			printf(" %c             Cubrir todo               %c\n",179,179);	
   			printf(" -----------------------------------------\n\n");
   			printf(" - Para ganar con este modo necesitaras\n");
   			printf(" completar todas las casillas del cart%cn\n",162);
   			printf("\n        Cubrir todo\n");
			printf("  ________________________\n");
			printf(" |    |    |    |    |    |\n");
			printf(" | 99 | 99 | 99 | 99 | 99 |\n");
			printf(" |____|____|____|____|____|\n");
			printf(" |    |    |    |    |    |\n");
			printf(" | 99 | 99 | 99 | 99 | 99 |\n");
			printf(" |____|____|____|____|____|\n");
			printf(" |    |    |    |    |    |\n");
			printf(" | 99 | 99 | TT | 99 | 99 |\n");
			printf(" |____|____|____|____|____|\n");
			printf(" |    |    |    |    |    |\n");
			printf(" | 99 | 99 | 99 | 99 | 99 |\n");
			printf(" |____|____|____|____|____|\n");
			printf(" |    |    |    |    |    |\n");
			printf(" | 99 | 99 | 99 | 99 | 99 |\n");
			printf(" |____|____|____|____|____|\n");
			printf("\n (Oprima cualquier bot%cn para seguir)",162);
   			getch();
   			fflush(stdin);
   			
		} else if(seleccion==3){
			ciclo=1;
			cic=true;	
		}else{
		 	printf("\nNo es una de las opciones...");
		 	getch();
		}
		
	}while(ciclo==0);
}

void Anim(){
printf("  %c%c%c%c%c%c%c%c\t%c%c%c%c%c%c%c%c      %c%c       %c%c\t  %c%c%c%c%c%c%c       %c%c%c%c%c%c%c%c%c\n",220,219,219,219,219,219,219,220,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,220,219,219,219,219,219,219,219,220);
	printf("  %c%c    %c%c\t   %c%c\t      %c%c%c      %c%c\t%c%c%c\t        %c       %c\n",219,219,219,219,219,219,219,219,219,219,219,220,219,219,219,219,219);
	printf("  %c%c    %c%c%c\t   %c%c\t      %c%c%c%c     %c%c       %c%c\t       %c%c       %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c    %c%c\t   %c%c\t      %c%c %c%c    %c%c      %c%c\t       %c%c       %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c%c%c%c%c%c%c\t   %c%c\t      %c%c  %c%c   %c%c      %c%c\t       %c%c       %c%c\n",219,219,219,219,219,219,219,220,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c    %c%c\t   %c%c\t      %c%c   %c%c  %c%c      %c%c\t       %c%c       %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c     %c%c\t   %c%c\t      %c%c    %c%c %c%c      %c%c       %c%c%c    %c%c       %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c     %c%c\t   %c%c\t      %c%c     %c%c%c%c      %c%c        %c%c    %c%c       %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c     %c%c\t   %c%c\t      %c%c      %c%c%c\t%c%c       %c%c    %c%c       %c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c    %c%c\t   %c%c\t      %c%c       %c%c\t %c%c      %c%c     %c       %c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
	printf("  %c%c%c%c%c%c%c\t%c%c%c%c%c%c%c%c      %c%c       %c%c\t  %c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,223,219,219,219,219,219,219,219,223);
	printf("\n\t\t Hecho por Franco Rodr%cguez & Jes%cs Ruiz\n",161,163);
}
