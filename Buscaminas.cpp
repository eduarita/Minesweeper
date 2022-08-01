#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void CrearTablero(int);
void ContarAlrededor(int);
void MostrarTabPerdedor(int);
void MostrarTab(int);
bool Descubrir(int,int,int);
void Casilla_0(int,int,int);
void Actualizar(int);
bool Verificar_Gane(int);

int matriz[15][15];
char tablero[15][15];
char MostrarTablero[15][15];

int main (){

    int tam = 0;
    srand(time(NULL));

    cout<<"     ------------- Buscaminas -------------"<<endl;
    cout<<endl;
    cout<<"INSTRUCCIONES:"<<endl;
    cout<<"1. Ingrese el tamanio del tablero, debe ser un valor entre 6 y 15."<<endl;
    cout<<"Nota: Entre mas casillas tenga el tablero, mas dificil es ganar!"<<endl;
    cout<<endl;

    cout<<"--> Ingrese el tamanio del tablero: ";
    cin>>tam;
    cout<<endl;

    while (tam < 6 || tam > 15){
    cout<<"Error! Ingrese un numero entre 6 y 15."<<endl;
    cout<<"--> Ingrese el tamanio del tablero: ";
    cin>>tam;
    }

    CrearTablero(tam);
    ContarAlrededor(tam);
    MostrarTab(tam);
    cout<<endl;
    cout<<"EMPECEMOS A JUGAR!!!"<<endl;
    cout<<"--> Ingrese la coordenada de las casillas que desee seleccionar: "<<endl;
    int fila=0;
    int columna =0;
    cout<<"--> Ingrese la fila: ";
    cin>>fila;
    fila=fila-1;
    cout<<"--> Ingrese la columna: ";
    cin>>columna;
    columna=columna-1;
    cout<<endl;

	while(fila<0 || fila>tam-1 || columna<0 || columna>tam-1){
	cout<<endl;
	cout<<"Error!:Coordenada fuera del tablero "<<endl;
	cout<<"--> Ingrese la fila: ";
    cin>>fila;
    fila=fila-1;
    cout<<"--> Ingrese la columna: ";
    cin>>columna;
    columna=columna-1;
    cout<<endl;
	}
	bool Descubre=true;
	bool Ganar=false;
	Descubre=Descubrir(tam,fila,columna);
	while (Descubre==true){
		cout<<endl;
		cout<<"--> Ingrese la fila: ";
    	cin>>fila;
    	fila=fila-1;
    	cout<<"--> Ingrese la columna: ";
    	cin>>columna;
    	cout<<endl;
    	columna=columna-1;
    	Descubre=Descubrir(tam,fila,columna);
    	Ganar=Verificar_Gane(tam);
    	if (Ganar==true){
            cout<<endl;
    		cout<<"FELICIDADES!!...HA GANADO EL JUEGO!!"<<endl;
    		Descubre=false;
		}
	}
 	return 0;
}


void CrearTablero(int tam){
    int filas = 0;
    int columnas = 0;
    filas=tam;
    columnas=tam;
    double k;
    k = (12 + rand()%(9));
    double porcentaje;
    porcentaje = (tam*tam)*(k/100);

    int cantMinas;
    cantMinas = porcentaje;
    cout<<endl;
    cout<<"Cantidad de minas en el tablero: "<<cantMinas<<endl;
    cout<<endl;

    int tablero;
    tablero = (tam*tam);

  for(int i=0; i<filas; i++) {
  for(int j=0; j<columnas; j++) {
       matriz[i][j] = 7;}
 }

    for (int i=0; i<cantMinas; i++){
    int posCol = rand()%(columnas);
    int posFil = rand()%(filas);
      if (matriz[posCol][posFil]==7){
         matriz[posCol][posFil]=9;
  }
  else{
            i--;
  }
   }
}

void ContarAlrededor(int tam){
    int filas = 0;
    int columnas = 0;
    int cont = 0;
    filas=tam;
    columnas=tam;

    //--------------------------------------------Cuenta las esquinas-------------------------------------------------
    for(int i=0; i<filas; i++) {
     for(int j=0; j<columnas; j++) {
        if ((i==0 && j==0)&& (matriz[i][j]!=9)){ //cuenta si esta en la esquina superior izquierda
            if (matriz[i][j+1] == 9){
            cont++;}
            if (matriz[i+1][j+1]==9){
            cont++;}
            if (matriz[i+1][j]==9){
            cont++;}

            matriz[i][j]=cont;
            cont=0;
        }
        else if ((i==0 && j==tam-1)&& (matriz[i][j]!=9)){ //cuenta si esta en la esquina superior derecha
            if (matriz[i][j-1] == 9){
            cont++;}
            if (matriz[i+1][j-1]==9){
            cont++;}
            if (matriz[i+1][j]==9){
            cont++;}

            matriz[i][j]=cont;
            cont=0;
        }
 	    else if ((i==tam-1 && j==0)&& (matriz[i][j]!=9)){ //cuenta si esta en la esquina inferior izquierda
            if (matriz[i-1][j] == 9){
            cont++;}
            if (matriz[i-1][j+1]==9){
            cont++;}
            if (matriz[i][j+1]==9){
            cont++;}

            matriz[i][j]=cont;
            cont=0;
        }
        else if ((i==tam-1 && j==tam-1)&& (matriz[i][j]!=9)){ //cuenta si esta en la esquina inferior derecha
            if (matriz[i-1][j] == 9){
            cont++;}
            if (matriz[i-1][j-1]==9){
            cont++;}
            if (matriz[i][j-1]==9){
            cont++;}

            matriz[i][j]=cont;
            cont=0;
        }
        //-Cuenta las orillas que no son esquinas

    	else if (i==0 && (matriz[i][j]!=9)){ //cuenta si esta en orilla superior
			if (matriz[i][j+1] == 9){
	        cont++;}
	        if (matriz[i+1][j+1]==9){
	        cont++;}
	        if (matriz[i+1][j]==9){
	        cont++;}
	        if (matriz[i][j-1] == 9){
            cont++;}
            if (matriz[i+1][j-1]==9){
            cont++;}
	        matriz[i][j]=cont;
	        cont=0;
        }
		else if (i==tam-1 && (matriz[i][j]!=9)){ //cuenta si esta en orilla inferior
			if (matriz[i-1][j] == 9){
            cont++;}
            if (matriz[i-1][j+1]==9){
            cont++;}
            if (matriz[i][j+1]==9){
            cont++;}
            if (matriz[i-1][j-1]==9){
            cont++;}
            if (matriz[i][j-1]==9){
            cont++;}

	        matriz[i][j]=cont;
	        cont=0;
        }

		else if (j==0 && (matriz[i][j]!=9)){ //cuenta si esta en orilla izquierda
			if (matriz[i-1][j] == 9){
            cont++;}
            if (matriz[i-1][j+1]==9){
            cont++;}
            if (matriz[i][j+1]==9){
            cont++;}
            if (matriz[i+1][j+1]==9){
            cont++;}
            if (matriz[i+1][j]==9){
            cont++;}

	        matriz[i][j]=cont;
	        cont=0;
        }

        else if (j==tam-1 && (matriz[i][j]!=9)){ //cuenta si esta en orilla derecha
			if (matriz[i-1][j] == 9){
            cont++;}
            if (matriz[i-1][j-1]==9){
            cont++;}
            if (matriz[i][j-1]==9){
            cont++;}
            if (matriz[i+1][j-1]==9){
            cont++;}
            if (matriz[i+1][j]==9){
            cont++;}

	        matriz[i][j]=cont;
	        cont=0;
        }
		else{//cuenta si son las casillas del centro
			if (matriz[i][j]!=9){
				if (matriz[i-1][j] == 9){
	            cont++;}
	            if (matriz[i-1][j-1]==9){
	            cont++;}
	            if (matriz[i][j-1]==9){
	            cont++;}
	            if (matriz[i+1][j-1]==9){
	            cont++;}
	            if (matriz[i+1][j]==9){
	            cont++;}
	            if (matriz[i-1][j+1]==9){
	            cont++;}
	            if (matriz[i][j+1]==9){
	            cont++;}
	            if (matriz[i+1][j+1]==9){
	            cont++;}
				matriz[i][j]=cont;
		        cont=0;
			}
		}
		}
	}
	for(int i=0; i<filas; i++) {
	  for(int j=0; j<columnas; j++) {
	  	if (matriz[i][j]==9){
	  		tablero[i][j]='*';
		  }
		  else{
		  	tablero[i][j]=char(matriz[i][j]+48);
		  }
	  }
	 }
}

void MostrarTabPerdedor(int tam){
    for(int i=0; i<tam; i++) {
    for(int j=0; j<tam; j++) {
   cout<<tablero[i][j]<<" ";
  }
  cout<<endl;
 }
    return;
}

void MostrarTab(int tam){
	int filas=tam;
	int columnas=tam;

	for(int i=0; i<filas; i++) {
	  for(int j=0; j<columnas; j++) {
	   MostrarTablero[i][j]='#';
	   cout<<MostrarTablero[i][j]<<" ";
	  }
	  cout<<endl;
	 }


}

bool Descubrir(int tam,int fila,int columna){
	int filas=tam;
	int columnas=tam;

	while(fila<0 || fila>tam-1 || columna<0 || columna>tam-1){
		cout<<"Error! Coordenada fuera del tablero "<<endl;
		cout<<"--> Ingrese la fila: ";
	    cin>>fila;
	    fila=fila-1;
	    cout<<"--> Ingrese la columna: ";
	    cin>>columna;
	    columna=columna-1;
	    cout<<endl;
	}

   	if (tablero[fila][columna]=='0'){
   		Casilla_0(tam,fila,columna);
   		Actualizar(tam);
	  	return true;
	 }
	else if(tablero[fila][columna]!='*'){
		MostrarTablero[fila][columna] =tablero[fila][columna] ;
		Actualizar(tam);
		return true;
	}
	else if(tablero[fila][columna]=='*'){
		cout<<"HA SELECCIONADO UNA MINA...USTED A PERDIDO EL JUEGO!!"<<endl;
		cout<<endl;
		MostrarTabPerdedor(tam);
		return false;
	}
}

void Actualizar(int tam){
	for(int i=0; i<tam; i++) {
	  for(int j=0; j<tam; j++) {

			cout<<MostrarTablero[i][j]<<" ";
	  }
	  cout<<endl;
	 }
}

void Casilla_0(int tam,int fila,int columna){
	MostrarTablero[fila][columna] =tablero[fila][columna] ;
//----------------------------------------------------Cuenta las esquinas---------------------------------------------------------------------
    if (fila==0 && columna==0){ //cuenta si esta en la esquina superior izquierda
		MostrarTablero[fila][columna+1] =tablero[fila][columna+1] ;
        MostrarTablero[fila+1][columna+1]=tablero[fila+1][columna+1];
        MostrarTablero[fila+1][columna]=tablero[fila+1][columna];

    }

    else if (fila==0 && columna==tam-1){ //cuenta si esta en la esquina superior derecha
		MostrarTablero[fila][columna-1] =tablero[fila][columna-1] ;
        MostrarTablero[fila+1][columna-1]=tablero[fila+1][columna-1];
        MostrarTablero[fila+1][columna]=tablero[fila+1][columna];
    }

    else if (fila==tam-1 && columna==0){ //cuenta si esta en la esquina inferior izquierda
		MostrarTablero[fila-1][columna] =tablero[fila-1][columna] ;
        MostrarTablero[fila-1][columna+1]=tablero[fila-1][columna+1];
        MostrarTablero[fila][columna+1]=tablero[fila][columna+1];
    }

    else if (fila==tam-1 && columna==tam-1){ //cuenta si esta en la esquina inferior derecha
		MostrarTablero[fila-1][columna] =tablero[fila-1][columna] ;
        MostrarTablero[fila-1][columna-1]=tablero[fila-1][columna-1];
        MostrarTablero[fila][columna-1]=tablero[fila][columna-1];
    }

        //----------------------------------------------------Cuenta las orillas que no son esquinas---------------------------------------------------------------------
	else if (fila==0){ //cuenta si esta en orilla superior
		MostrarTablero[fila][columna+1] =tablero[fila][columna+1] ;
        MostrarTablero[fila+1][columna+1]=tablero[fila+1][columna+1];
        MostrarTablero[fila+1][columna]=tablero[fila+1][columna];
		MostrarTablero[fila][columna-1]=tablero[fila][columna-1];
        MostrarTablero[fila+1][columna-1]=tablero[fila+1][columna-1];
    }

	else if (fila==tam-1){ //cuenta si esta en orilla inferior
		MostrarTablero[fila-1][columna] =tablero[fila-1][columna] ;
        MostrarTablero[fila-1][columna+1]=tablero[fila-1][columna+1];
        MostrarTablero[fila][columna+1]=tablero[fila][columna+1];
		MostrarTablero[fila-1][columna-1]=tablero[fila-1][columna-1];
        MostrarTablero[fila][columna-1]=tablero[fila][columna-1];
    }

	else if (columna==0 ){ //cuenta si esta en orilla izquierda
		MostrarTablero[fila-1][columna] =tablero[fila-1][columna] ;
        MostrarTablero[fila-1][columna+1]=tablero[fila-1][columna+1];
        MostrarTablero[fila][columna+1]=tablero[fila][columna+1];
		MostrarTablero[fila+1][columna+1]=tablero[fila+1][columna+1];
        MostrarTablero[fila+1][columna]=tablero[fila+1][columna];
    }

    else if (columna==tam-1){ //cuenta si esta en orilla derecha
		MostrarTablero[fila-1][columna] =tablero[fila-1][columna] ;
        MostrarTablero[fila-1][columna-1]=tablero[fila-1][columna-1];
        MostrarTablero[fila][columna-1]=tablero[fila][columna-1];
		MostrarTablero[fila+1][columna-1]=tablero[fila+1][columna-1];
        MostrarTablero[fila+1][columna]=tablero[fila+1][columna];
    }

	else{//cuenta si son las casillas del centro
		MostrarTablero[fila-1][columna] =tablero[fila-1][columna] ;
        MostrarTablero[fila-1][columna-1]=tablero[fila-1][columna-1];
        MostrarTablero[fila][columna-1]=tablero[fila][columna-1];
		MostrarTablero[fila+1][columna-1]=tablero[fila+1][columna-1];
        MostrarTablero[fila+1][columna]=tablero[fila+1][columna];
		MostrarTablero[fila-1][columna+1]=tablero[fila-1][columna+1];
		MostrarTablero[fila][columna+1]=tablero[fila][columna+1];
        MostrarTablero[fila+1][columna+1]=tablero[fila+1][columna+1];
	}

}
bool Verificar_Gane(int tam){
	int cont=0;
	for(int i=0; i<tam; i++) {
	  for(int j=0; j<tam; j++) {
	   if ((MostrarTablero[i][j]=='#' )&& (tablero[i][j]!='*')){
	   	cont++;
	   }
	  }
	 }
	if(cont==0){
		return true;
	}
	else{
		return false;
	}
}