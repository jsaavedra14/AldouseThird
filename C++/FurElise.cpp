#include <iostream>
#include <math.h>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

void mostrar(long double x[][10], int cx, int lx, string prompt = "Resultado: "){ //Esta es una funcion que muestra matrices

    cout << endl << endl << prompt << endl;
    for (int i = 1; i <= lx; ++i) {
		for (int j = 1; j <= cx; ++j) {
			cout << right << setw(2) << "| "
			<< right << setw(10) << x[i][j] << " |";
		}

		cout <<  endl;
    }

    for (int n = 1; n <= cx; ++n) {

		cout << "--------------";
		}
		cout << endl;

}

int main(){

    long double x[10][10], identidad[10][10];
    int i, j, z; // Variables de loop
    int lx, cx, cc; //Los enteros seran usados para contar filas y columnas
    long double mul, restador; //variables para obtener la inversa
    bool found; //Y un booleano para verificar parametros en un futuro

    cout << "Inserte la cantidad de filas y columnas de su matriz x: "; //Empezamos pidiendo parametros de la matriz
    cin >> lx; //Inserta la cantidad de filas de la matriz
    cx = lx; //Necesito que la matriz sea cuadrada, asi que tendra la misma cantidad de filas y columnas
    
    for (i = 1; i <= lx; i++) { //Pide que se inserte la matriz

        for (j = 1; j <= cx; j++) {

    cout << "Inserte la variable en [" << i << "][" << j << "] : ";
    cin >> x[i][j];

        }
    }

    mostrar(x, cx , lx , "Su matriz es: "); // Muestra el sistema de ecuaciones insertado

    //Ahora voy a crear una matriz identidad equivalente

    for (i = 1; i <= lx; i++) { //Pide que se inserte la matriz

        for (j = 1; j <= cx; j++) {

            if(i == j){
                identidad[i][j] = 1;//Si se encuentra en un diagonal inserte un 1
            }

             else{ 
                 identidad[i][j] = 0;//De resto, inserte un 0
            }
        }
    }

    //mostrar(identidad, cx, lx, "La matriz identidad de esta es: ");

    for(i = 1; i <= cx; i++){ // Empiezo a obtener la matriz inversa

        if(x[i][i] != 1){ //Esto verifica que el pivote (las diagonales de la matriz) sea igual a 1, si no lo es, lo convierte a 1

            mul = 1/x[i][i]; //Obtengo la inversa del pivote(El numero que debe ser 1), todo numero multiplicado por su inversa es igual a 1

            for(j = 1; j <= cx ; j++){
                x[i][j] = x[i][j] * mul; //Multiplico toda la fila por la inversa que obtuve, de manera que el pivote sea un 1
                identidad[i][j] = identidad[i][j] * mul; //Aplico lo mismo a la matriz identidad respectiva
            }

            mostrar(x, cx, lx, "He dividido algo de la matriz, mirad!: "); //Muestro la matriz

        }

        for(j = 1; j <= lx; j++){ //Ahora que el pivote es 1, empiezo a despejar la columna como si estuviese haciendo Gauss, para tener una columna con unos y ceros
        //El loop de arriba se encarga de pasar por las filas de la matriz
            if(x[j][i] != 0 && j != i){ //Si en una coordenada que no sea el pivote (&& j != i) encuentra algo que no es 0 (x[j][i] != 0) . . .

                restador = x[j][i]; //Obtengo el numero que no es 0 para luego usarlo en la resta de filas

                for(z = 1; z <= cx; z++){

                    x[j][z] = x[j][z] - (x[i][z] * restador); //Resto la fila del numero que no es 0 y le resto la fila del pivote multiplicada por el numero que no es 0
                    //Esto es debido a que al ser el pivote 1, si lo multiplico por el numero que es 0 obtendre el mismo numero, al restar ese numero por si mismo obtengo 0
                    identidad[j][z] = identidad[j][z] - (identidad[i][z] * restador); //Le hago lo mismo a la matriz identidad


                    mostrar(x, cx, lx, "He restado algo de la matriz, mirad!: ");//Muestro la matriz
  
                    mostrar(identidad, cx, lx, "Y la identidad cambio a: ");//Muestro la matriz
                
                }
            }
        }
    }

    mostrar(x, cx , lx , "Su matriz es: "); //Muestro como quedo la matriz principal, deberia ser una matriz identidad
    mostrar(identidad, cx, lx, "Y la inversa es . . . : ");// Y la matriz que antes era identidad ahora es la matriz inversa de la que pusimos
    cout << endl << "Ya que llegaste aqui te mostrare un cumbion" << endl;

    system("pause");

    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //2
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //3
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //4
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(415,200); //Ab4
    Beep(493,200); //B4
    //5
    Beep(523,400); //C5
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(329,200); //E4
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //6
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //7
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //8
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(523,200); //C5
    Beep(493,200); //B4
    //9
    Beep(440,600); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(440,200); //A4
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //10
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //11
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //12
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(415,200); //Ab4
    Beep(493,200); //B4
    //13
    Beep(523,400); //C5
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(329,200); //E4
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //14
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //15
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //16
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(523,200); //C5
    Beep(493,200); //B4
    //17
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(493,200); //B4
    Beep(523,200); //C5
    Beep(587,200); //D5
    //18
    Beep(659,400); //E5
    Beep(130,200); //C3
    Beep(195,200); //G3
    Beep(261,200); //C4
    Beep(391,200); //G4
    Beep(698,200); //F5
    Beep(659,200); //E5
    //19
    Beep(587,400); //D5
    Beep(97,200); //G2
    Beep(195,200); //G3
    Beep(246,200); //B3
    Beep(349,200); //F4
    Beep(659,200); //E5
    Beep(587,200); //D5
    //20
    Beep(523,400); //C5
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(329,200); //E4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //21
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(329,200); //E4
    Beep(329,200); //E4
    Beep(659,200); //E5
    Beep(329,200); //E4
    //22
    Beep(659,200); //E5
    Beep(659,200); //E5
    Beep(1318,200); //E6
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //23
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //24
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //25
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //26
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(415,200); //Ab4
    Beep(493,200); //B4
    //27
    Beep(523,400); //C5
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(329,200); //E4
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //28
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //29
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //30
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(523,200); //C5
    Beep(493,200); //B4
    //31
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(493,200); //B4
    Beep(523,200); //C5
    Beep(587,200); //D5
    //32
    Beep(659,400); //E5
    Beep(130,200); //C3
    Beep(195,200); //G3
    Beep(261,200); //C4
    Beep(391,200); //G4
    Beep(698,200); //F5
    Beep(659,200); //E5
    //33
    Beep(587,400); //D5
    Beep(97,200); //G2
    Beep(195,200); //G3
    Beep(246,200); //B3
    Beep(349,200); //F4
    Beep(659,200); //E5
    Beep(587,200); //D5
    //34
    Beep(523,400); //C5
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(329,200); //E4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //35
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(329,200); //E4
    Beep(329,200); //E4
    Beep(659,200); //E5
    Beep(329,200); //E4
    //36
    Beep(659,200); //E5
    Beep(659,200); //E5
    Beep(1318,200); //E6
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //37
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //38
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //39
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //40
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(415,200); //Ab4
    Beep(493,200); //B4
    //41
    Beep(523,400); //C5
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(329,200); //E4
    Beep(659,200); //E5
    Beep(622,200); //Eb5
    //42
     Beep(659,200); //E5
    Beep(622,200); //Eb5
    Beep(659,200); //E5
    Beep(493,200); //B4
    Beep(587,200); //D5
    Beep(523,200); //C5
    //43
    Beep(440,400); //A4
    Beep(110,200); //A2
    Beep(164,200); //E3
    Beep(220,200); //A3
    Beep(261,200); //C4
    Beep(329,200); //E4
    Beep(440,200); //A4
    //44
    Beep(493,400); //B4
    Beep(82,200); //E2
    Beep(164,200); //E3
    Beep(207,200); //Ab3
    Beep(329,200); //E4
    Beep(523,200); //C5
    Beep(493,200); //B4
    //45
    Beep(440,1000); //A4
    return 0;
    }