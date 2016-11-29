/*#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>*/
#include <bits/stdc++.h>//Se puede usar bits o todas las librerias comentadas en su lugar
using namespace std;
map<string, string> HexKeys;
map<string, string> BinKeys;
const int MAX=0x7FFFF;
//PROTOYPES
//_____________________________________________________________________________________
string decToBin(int decimal);
int binToDec(string binWord);
string binToHex(string binWord);
string hexToBin(string hexWord);

float add(float firstNumber,  float secondNumber);
float subs(float firstNumber,float secondNumber);
float mult(float firstNumber, float secondNumber);
float div(float firstNumber, float secondNumber);
float power(float base, float exp);
float sqroot(float m);

int searchFor(int numberToFind, int[], int arrSize);
void change(int forChange, int toChange, int[], int arrSize);
bool insertion(int toInsert, int[], int maxSize);
void bubbleSort(int[] , int arrSize);

void matrixAdd(int [5][5] , int [5][5] ,int[5][5] , int rows, int cols);
void matrixSub(int arr1[5][5] , int arr2[5][5], int answer[5][5] , int rows,int cols);
void byScalarMult(int [5][5] , int scalar,int [5][5], int rows, int cols);
void byMatrixMult(int[5][5] , int[5][5] , int[5][5] , int rows, int cols,int k);
void transpose(int [5][5], int [5][5],int rows, int cols);

void printArray(int[] , int size);
void print2d(int[5][5],int rows,int cols);
void fillArray(int[],int arrSize);
void readMatrix(int[5][5],int rows, int cols);
void sort2d(int[3][3],int arrSize);

void game();

//MENU
//_____________________________________________________________________________________
int main()
{
    int mainOption=0;
    char mainMenu='Y', subMenu='Y';
    HexKeys["0000"]="0";
    HexKeys["0001"]="1";
    HexKeys["0010"]="2";
    HexKeys["0011"]="3";
    HexKeys["0100"]="4";
    HexKeys["0101"]="5";
    HexKeys["0110"]="6";
    HexKeys["0111"]="7";
    HexKeys["1000"]="8";
    HexKeys["1001"]="9";
    HexKeys["1010"]="A";
    HexKeys["1011"]="B";
    HexKeys["1100"]="C";
    HexKeys["1101"]="D";
    HexKeys["1110"]="E";
    HexKeys["1111"]="F";

    BinKeys["0"]="0000";
    BinKeys["1"]="0001";
    BinKeys["2"]="0010";
    BinKeys["3"]="0011";
    BinKeys["4"]="0100";
    BinKeys["5"]="0101";
    BinKeys["6"]="0110";
    BinKeys["7"]="0111";
    BinKeys["8"]="1000";
    BinKeys["9"]="1001";
    BinKeys["A"]="1010";
    BinKeys["B"]="1011";
    BinKeys["C"]="1100";
    BinKeys["D"]="1101";
    BinKeys["E"]="1110";
    BinKeys["F"]="1111";

    enum options{basic_op,conv,array_op,matrix_op,games};
    int sub_option=0;

    while(mainMenu=='Y')
    {
        cout<<"\n\tProyecto Programacion Estructurada Segundo Parcial\n\n";
        cout<<"Opciones:\n"
        <<"1-Operaciones basicas con enteros\n"
        <<"2-Conversiones numericas\n"
        <<"3-Operaciones sobre arreglos unidimensionales\n"
        <<"4-Operaciones con matrices de 2 dimensiones\n"
        <<"5-Juego\n";
        cout<<"Inserte la opcion deseada: ";
        cin>>mainOption;
            switch (--mainOption){
            case basic_op:
                float param1,param2;
                subMenu='Y';
                while(subMenu=='Y')
                {
                    cout<<"Operaciones disponibles: \n"
                    <<"1.-Suma   2.-Resta   3.-Division  4.-Potencia  5.-Multiplicacion  6.-Raiz\n";
                    cout<<"Inserte el numero de la operacion deseada: ";
                    cin>>sub_option;
                    switch(sub_option)
                    {

                    case 1:
                        cout<<"Inserte el primer numero: ";
                        cin>>param1;
                        cout<<"Inserte el segundo numero: ";
                        cin>>param2;
                        cout<<"\nLa suma es "<<add(param1,param2);
                        break;
                    case 2:
                        cout<<"Inserte el primer numero: ";
                        cin>>param1;
                        cout<<"Inserte el numero a restar: ";
                        cin>>param2;
                        cout<<"\nLa resta es "<<subs(param1,param2);
                        break;
                    case 3:
                        cout<<"Inserte el numerador: ";
                        cin>>param1;
                        cout<<"Inserte el denominador: ";
                        cin>>param2;
                        if(!div(param1,param2))
                        {cout<<"\nEso no funcionara\n";}
                        else cout<<"\nEl cociente es "<<div(param1,param2);
                        break;
                    case 4:
                        cout<<"Inserte la base: ";
                        cin>>param1;
                        cout<<"Inserte el exponente: ";
                        cin>>param2;
                        cout<<"\n"<<param1<<" a la "<<param2<<" es igual a "<<power(param1,param2);
                        break;
                    case 5:
                        cout<<"Inserte el primer multiplo: ";
                        cin>>param1;
                        cout<<"Inserte el segundo multiplo: ";
                        cin>>param2;
                        cout<<" \nEl resultado de la multiplicacion es: "<<mult(param1,param2)<<"\n";
                        break;
                    case 6:
                        cout<<"Inserte el numero: ";
                        cin>>param1;
                        cout<<"La raiz es: "<<sqroot(param1)<<"\n";
                        break;
                        default: cout<<"\n No es valida\n";
                    }
                    cout<<"\nDesea realizar otra consulta(Y/N): ";
                    cin>>subMenu;
                }
                break;
            case conv:
                subMenu='Y';
                while(subMenu=='Y')
                {
                    string binWord="",hexWord="";
                    int decimal=0;
                    cout<<"\nConversiones disponibles: \n"
                    <<"1.-Decimal a binario  2.-Binario a decimal  3.- Binario a hexadecimal\n"
                    <<"4.-Hexadecimal a binario  5.-Hexadecimal a decimal  6.-Decimal a hexadecimal\n";
                    cout<<"Inserte la opcion de conversion: ";
                    cin>>sub_option;
                    switch(sub_option)
                    {

                    case 1:
                        cout<<"Inserte el numero en decimal: ";
                        cin>>decimal;
                        cout<<decimal<<" en binario= "<<decToBin(decimal);
                        break;
                    case 2:
                        cout<<"Inserte el numero en binario: ";
                        cin>>binWord;
                        cout<<binWord<<" en decimal= "<<binToDec(binWord);
                        break;
                    case 3:
                        cout<<"Inserte el numero binario: ";
                        cin>>binWord;
                        cout<<binWord<<" en hexadecimal= "<<binToHex(binWord);
                        break;
                    case 4:
                        cout<<"Inserte el numero hexadecimal: ";
                        cin>>hexWord;
                        cout<<hexWord<<" en binario= "<<hexToBin(hexWord);
                        break;
                    case 5:
                        cout<<"Inserte el numero hexadecimal: ";
                        cin>>hexWord;
                        binWord=hexToBin(hexWord);
                        cout<<hexWord<<" en decimal= "<<binToDec(binWord);
                        break;
                    case 6:
                        cout<<"Inserte el numero decimal: ";
                        cin>>decimal;
                        binWord=decToBin(decimal);
                        cout<<decimal<<" en hexadecimal= "<<binToHex(binWord);
                        break;
                    default:cout<<"\nNo es una opcion valida\n";

                    }
                    cout<<"\nDesea realizar otra prueba? (Y/N): ";
                    cin>>subMenu;

                }
                break;
            case array_op:

                subMenu='Y';
                int arr[100];
                for(int i=0;i<100;i++)arr[i]=MAX;
                int arraySize;
                int toFind,toReplace,forReplace,toInsert;
                cout<<"Inserte cuantos elementos se generaran: ";
                cin>>arraySize;
                if(arraySize>0&&arraySize<=100)
                {
                    fillArray(arr,arraySize);
                } else cout<<"\nDebe ser mayor a 0 y menor a 100\n";
                if( arraySize<=100)while(subMenu=='Y')
                {
                    cout<<"Su arreglo es: ";
                    printArray(arr,arraySize);
                    cout<<"Operaciones disponibles para el arreglo:\n";
                    cout<<"1-Busqueda  2-Reemplazar elemento  3-Insercion  4-Ordenamiento 5-Generar uno nuevo\n";
                    cout<<"Inserte la opcion deseada: ";
                    cin>>sub_option;
                    switch(sub_option)
                    {
                    case 1:
                        cout<<"Inserte el elemento a buscar: ";
                        cin>>toFind;
                        cout<<"El elemento fue encontrado: "<<searchFor(toFind,arr,arraySize)<<" veces \n";
                        break;

                    case 2:
                        cout<<"Inserte el elemento a reemplazar: ";
                        cin>>toReplace;
                        cout<<"Inserte el elemento para reemplazarlo: ";
                        cin>>forReplace;
                        if(searchFor(toReplace,arr,arraySize)!=0)
                        {
                            change(forReplace,toReplace,arr,arraySize);
                            cout<<"El nuevo arreglo es: \n";
                            printArray(arr,arraySize);
                        }else cout<<"\nEl elemento para reemplazar no existe\n";
                        break;

                    case 3:
                        cout<<"Introduzca el numero a insertar: ";
                        cin>>toInsert;
                        if(insertion(toInsert,arr,100))
                        {
                            arraySize++;
                            cout<<"\nEl nuevo arreglo es: \n";
                            printArray(arr,arraySize);
                        } else cout<<"\nArreglo lleno\n";
                        break;

                    case 4:
                        bubbleSort(arr,arraySize);
                        cout<<"El nuevo arreglo es: \n";
                        printArray(arr,arraySize);
                        break;
                    case 5:{
                        cout<<"Inserte el numero de elementos a generar (1-100)\n";
                        int temp=arraySize;
                        cin>>arraySize;
                        if(arraySize>0&&arraySize<=100)
                        {
                            for(int i=0;i<100;i++)arr[i]=MAX;
                            fillArray(arr,arraySize);
                            cout<<"El nuevo arreglo es: ";
                            printArray(arr,arraySize);
                        }
                        else {
                            arraySize=temp;
                            cout<<"\nValores invalidos, el arreglo anterior se conserva\n";
                        }
                        break;}
                    default:
                        cout<<"Opcion invalida\n";
                        break;

                    }
                    cout<<"Seguir haciendo operaciones?(Y/N)\n";
                    cin>>subMenu;
                }
                break;
            case matrix_op:
                int arr1[5][5],arr2[5][5],ans[5][5];
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        arr1[i][j]=MAX;
                        arr2[i][j]=MAX;
                        ans[i][j]=MAX;
                    }
                }
                subMenu='Y';
                int rows,cols,k, scalar;
                cout<<"Inserte el numero de filas de su matriz: ";
                cin>>rows;
                cout<<"Inserte el numero de columnas de su matriz: ";
                cin>>cols;
                readMatrix(arr1,rows,cols);
                if(rows>0&&rows<=5&&cols>0&&cols<=5)
                while(subMenu=='Y')
                    {
                        cout<<"Su matriz es: ";
                        print2d(arr1,rows,cols);
                        cout<<"\nLas operaciones disponibles son: "
                        <<"\n 1.-Multiplicacion por un escalar  2.-Suma de matrices 3.-Multiplicacion de matrices 4.-Transpuesta 5.-Resta de matrices\n";
                        cout<<"Inserte la opcion deseada : ";
                        cin>>sub_option;
                        switch(sub_option)
                        {
                        case 1:
                            cout<<"Inserte el escalar para multiplicar la matriz: ";
                            cin>>scalar;
                            byScalarMult(arr1,scalar,ans,rows,cols);
                            cout<<"El resultado es: \n";
                            print2d(ans,rows,cols);
                            break;
                        case 2:
                            cout<<"Ingrese la matriz para sumarse: \n";
                            readMatrix(arr2,rows,cols);
                            matrixAdd(arr1,arr2,ans,rows,cols);
                            cout<<"La respuesta es: \n";
                            print2d(ans,rows,cols);
                            break;
                        case 3:
                            cout<<"Inserte el numero de columnas de la matriz a multiplicar: ";
                            cin>>k;
                            readMatrix(arr2,cols,k);
                            byMatrixMult(arr1,arr2,ans,rows,cols,k);
                            cout<<"La solucion es: \n";
                            print2d(ans,rows,k);
                            break;
                        case 4:
                            transpose(arr1,ans,rows,cols);
                            cout<<"La transpuesta es: \n";
                            print2d(ans,cols,rows);
                            break;
                        case 5:
                            cout<<"Ingrese la matriz para restarse: \n";
                            readMatrix(arr2,rows,cols);
                            matrixSub(arr1,arr2,ans,rows,cols);
                            cout<<"La respuesta es: \n";
                            print2d(ans,rows,cols);
                            break;
                        default: cout<<"\nOpcion invalida\n";
                        }
                        cout<<"Desea seguir realizando operaciones? (Y/N) : ";
                        cin>>subMenu;
                    }

                break;
            case games:
                subMenu='Y';
                while(subMenu=='Y')
                {
                    game();
                    cout<<"\nDesea otro juego(Y/N): ";
                    cin>>subMenu;
                }
            break;
            default: cout<<"\nOpcion invalida\n";
            }
            cout<<"Desea continuar en el menu principal(Y/N): ";
            cin>>mainMenu;
    }
	return 0;
}
//FUNCTIONS
//_____________________________________________________________________________________
//HELPERS
void sort2d(int arr[3][3],int arraySize)
{
    int indiceArreglo=0,auxSwap;

    for (int i=0; i<(arraySize-1); i++)
    {
        for (int j=(arraySize-1); j>indiceArreglo; j--)
        {
            if (arr[0][j]<arr[0][j-1])
            {
                auxSwap=arr[0][j];
                arr[0][j]=arr[0][j-1];
                arr[0][j-1]=auxSwap;
            }
        }
        indiceArreglo++;
    }
}

void print2d(int arr[5][5], int rows,int cols)
{
    cout<<"\n";
    for (int i = 0; i < rows; i++)
    {
        for(int j=0;j<cols;j++)cout<<arr[i][j]<<"\t";
            cout<<"\n";
    }
}
void printArray(int arr[], int arrSize)
{
    cout<<"\n";
    for(int i=0;i<arrSize;i++)cout<<arr[i]<<"--";
        cout<<"\n";
}

void fillArray(int arr[], int arrSize)
{
    srand(time(NULL));
    for(int i=0;i<arrSize;i++)arr[i]=1+rand()%100;
}
void readMatrix(int arr[5][5],int rows, int cols)
{

    if(rows>0&&rows<=5&&cols>0&&cols<=5)
        {
            for(int i=0;i<rows;i++)
                {
                    for(int j=0;j<cols;j++)
                        {
                            cout<<"Inserte el elemento ["<<i<<"]["<<j<<"]: ";
                            cin>>arr[i][j];
                        }
                    }
                }else cout<<"\nNo se insertaron valores validos\n";
}
//2d Matrix Operations
void byScalarMult(int arr[5][5] , int scalar,int ans[5][5], int rows, int cols)
{
	for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)ans[i][j]=scalar*arr[i][j];
}
void matrixAdd(int arr1[5][5] , int arr2[5][5], int answer[5][5] , int rows,int cols)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)answer[i][j]=arr1[i][j]+arr2[i][j];
	}
}
void matrixSub(int arr1[5][5] , int arr2[5][5], int answer[5][5] , int rows,int cols)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)answer[i][j]=arr1[i][j]-arr2[i][j];
	}
}
void byMatrixMult(int arr1[5][5], int arr2[5][5],int answer[5][5] , int rows, int cols,int k)
{
    for (int i = 0; i < rows; i++)
    {
        for (int z = 0; z <k ; z++)
        {
            int sum=0;
            for(int j=0;j<cols;j++)
            {
                sum+=arr1[i][j]*arr2[j][z];
            }
            answer[i][z]=sum;
        }
    }
}

void transpose(int arr[5][5], int ans[5][5], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ans[j][i]=arr[i][j];
        }
    }
}
//1d Matrix operations
bool insertion(int toInsert,int arr[] , int maxSize)
{
	bool wasInserted=false;
	for(int i=0;i<maxSize;i++)
	{
		if(arr[i]==MAX)
		{
			arr[i]=toInsert;
			wasInserted=true;
			break;
		}
	}
	return wasInserted;
}
int searchFor(int numberToFind, int arr[] , int arrSize)
{
	int instances=0;
	for (int i = 0; i < arrSize; i++) arr[i]==numberToFind?instances++:NULL;
		return instances;
}
void change(int forChange,int toChange,int arr[] , int arrSize)
{
	for (int i = 0; i < arrSize; i++) arr[i]==toChange?arr[i]=forChange:NULL;
}
void bubbleSort(int arr[] , int arraySize)
{
	int indiceArreglo=0,auxSwap;

    for (int i=0; i<(arraySize-1); i++)
    {
        for (int j=(arraySize-1); j>indiceArreglo; j--)
        {
            if (arr[j]<arr[j-1])
            {
                auxSwap=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=auxSwap;
            }
        }
        indiceArreglo++;
    }
}

//Basic operations
float power(float base, float exp)
{
	float answer=1;
	if(exp==0)return 1;
	for (int i = 0; i < abs(exp); i++) answer*=base;
		if(exp<0)return 1/answer;
	return answer;
}
float div(float firstNumber, float secondNumber)
{
    if(secondNumber!=0)return firstNumber/secondNumber;
    return float(0);
}
float mult(float firstNumber,float secondNumber){return (firstNumber*secondNumber);}
float add(float firstNumber,float secondNumber) {return (firstNumber+secondNumber);}
float subs(float firstNumber,float secondNumber){return (firstNumber-secondNumber);}

float sqroot(float m)
{
    float square=0.00;
    while(square*square<m)square+=0.01;
    return square-0.01;
}
//Number convert
string decToBin(int decimal)
{
    string binWordInverse="",binWord="";
    int indexForComplete;

    while(decimal>1)
    {
        binWordInverse+=char(decimal%2)+'0';
        decimal/=2;
    }
    binWordInverse+=char(decimal)+'0';

    indexForComplete=binWordInverse.size();

    while(indexForComplete++%4!=0)binWordInverse+='0';

    for(int index=binWordInverse.size()-1;index>=0;index--)
    {
        binWord+=binWordInverse[index];
    }
    return binWord;
}

int binToDec(string binWord)
{
    int decimal=0,position=0;
    for(int index=binWord.length()-1;index>=0;index--)
    {
        if(binWord[index]!=' ')
        {
            decimal+=int(binWord[index]-'0')*pow(2,position++);
        }
    }
    return decimal;
}

string binToHex(string binWord)
{
    string partialBinaryWord="",hexWord="";
    int index=0;
    reverse(binWord.begin(),binWord.end());
    while(binWord.size()%4!=0)binWord+='0';
    reverse(binWord.begin(),binWord.end());
    //while(binWord[index]=='0')index++;
    for(index;index<binWord.length();index++)
    {
        partialBinaryWord+=binWord[index];
        if((index+1)%4==0 && index!=0)
        {
            hexWord+=HexKeys[partialBinaryWord];
            partialBinaryWord="";
        }
    }
    if(hexWord=="")return "0";
    return hexWord;
}

string hexToBin(string hexWord)
{
    string binWord="",hexKey="";
    for(int i=0;i<hexWord.size();i++) hexWord[i]=toupper(hexWord[i]);
    for(int index=0;index<hexWord.length();index++)
    {
        hexKey+=hexWord[index];
        binWord+=BinKeys[hexKey];
        hexKey="";
    }
    return binWord;
}

//Game
void game()
{
    int player1[3][3], player2[3][3], temp=0;
    int scoreFirst=0,scoreSecond=0;
    int numbers[10], numbers2d[10][10];
    bool correct=true;
    const int nearRange=5;
    for(int i=0;i<3;i++)
    {
        player1[0][i]=MAX;
        player2[0][i]=MAX;
    }
    //Reading numbers from players
    for(int i=0;i<3;i++)
    {
        correct=true;
        do{
        cout<<"Jugador 1 inserte su numero "<<i+1<<": ";
        cin>>temp;
        correct=true;
        for(int j=0;j<3;j++)
        {
            if(temp==player1[0][j])
            {
                cout<<"\nNo puede insertar numeros iguales\n";
                correct=false;
            }
        }
        if(correct){
                player1[1][i]=1;
                player1[0][i]=temp;
            }
        } while(!correct);



        do{
        cout<<"Jugador 2 inserte su numero "<<i+1<<": ";
        cin>>temp;
        correct=true;
        for(int j=0;j<3;j++)
        {
            if(temp==player2[0][j])
            {
                cout<<"\nNo puede insertar numeros iguales\n";
                correct=false;
            }
        }
        if(correct){
                player2[1][i]=1;
                player2[0][i]=temp;
            }
        } while(!correct);
    }
    fillArray(numbers,10);
    bubbleSort(numbers,10);
    sort2d(player1,3);
    sort2d(player2,3);
    cout<<"\nLos numeros del jugador 1 son:\n[";
    for(int i=0;i<3;i++)cout<<player1[0][i]<<"-";
    cout<<"]\n Los numeros del jugador 2 son: \n[";
    for(int i=0;i<3;i++)cout<<player2[0][i]<<"-";
    cout<<"]\nEl arreglo de aleatorios es:";
    printArray(numbers,10);
    for(int i=0;i<10;i++)
    {
        numbers2d[0][i]=numbers[i];
        numbers2d[1][i]=1;
    }

    //First Rule

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(player1[0][j]==numbers2d[0][i]&&player1[1][j])
            {
                cout<<"\nEl numero ["<<player1[0][j]<<"] del jugador 1 coincide con "<<numbers2d[0][i]<<" =+5";
                numbers2d[1][i]=0;
                scoreFirst+=5;
                player1[1][j]=0;
            }
            if(player2[0][j]==numbers2d[0][i]&&player2[1][j])
            {
                cout<<"\nEl numero ["<<player2[0][j]<<"] del jugador 2 coincide con "<<numbers2d[0][i]<<" =+5";
                numbers2d[1][i]=0;
                scoreSecond+=5;
                player2[1][j]=0;
            }
        }
    }
    cout<<"\n--Rango de proximidad establecido ="<<nearRange<<"\n";

        //Second Rule
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<3;j++)
            {
                bool wasUsed=false;
                if(player1[1][j]&&numbers2d[1][i])//both items are available
                {
                    if((player1[0][j]>=numbers2d[0][i]-nearRange)&&(player1[0][j]<numbers2d[0][i]))
                    {
                        cout<<"\nEl numero ["<<player1[0][j]<<"] del jugador 1 se acerco a "<<numbers2d[0][i]<<" =+3";
                        player1[1][j]=0;
                        wasUsed=true;
                        scoreFirst+=3;
                    }
                }

                if(player2[1][j]&&numbers2d[1][i])//both items are available
                {
                    if((player2[0][j]>=numbers2d[0][i]-nearRange)&&(player2[0][j]<numbers2d[0][i]))
                    {
                        cout<<"\nEl numero ["<<player2[0][j]<<"] del jugador 2 se acerco a "<<numbers2d[0][i]<<" =+3";
                        player2[1][j]=0;
                        wasUsed=true;
                        scoreSecond+=3;
                    }
                }
                if(wasUsed)numbers2d[1][i]=0;
            }
        }
        //Last Rule
        	for(int j=0;j<3;j++)
        	{
        	    bool isSmaller=true;
        		if(player1[1][j])
        		{
        			for(int x=0;x<10;x++)
        			{
        				if( (player1[0][j]>numbers2d[0][x])&&numbers2d[1][x] )isSmaller=false;
        			}
                    if(isSmaller)
                    {
                        cout<<"\nEl numero ["<<player1[0][j]<<"] del jugador 1 no fue utilizado y fue menor que cualquiera del arreglo =+2";
                        scoreFirst+=2;
                    }

        		}
        		isSmaller=true;
        		if(player2[1][j])
        		{

        			for(int x=0;x<10;x++)
        			{
        				if( (player2[0][j]>numbers2d[0][x])&&numbers2d[1][x] )isSmaller=false;
        			}
                    if(isSmaller)
                    {
                        cout<<"\nEl numero["<<player2[0][j]<<"] del jugador 2 no fue utilizado y fue menor que cualquiera del arreglo= +2";
                        scoreSecond+=2;
                    }
        		}
            }
            cout<<"\n--La suma total de puntos del jugador 1 es: "<<scoreFirst<<"\n";
            cout<<"\n--La suma total de puntos del jugador 2 es: "<<scoreSecond<<"\n";
            if(scoreFirst>scoreSecond)
            {
                cout<<"\nGana jugador 1!\n";
            }else if(scoreFirst!=scoreSecond)
            {
                cout<<"\nGana jugador 2!\n";
            }
        //Special Rule
        if(scoreFirst==scoreSecond)
        {
            cout<<"\nEmpate! pero...";
        	int sum1=0,sum2=0;
        	for(int i=0;i<3;i++)
        	{
        		sum1+=player1[0][i];
        		sum2+=player2[0][i];
        	}
        	if(sum2>sum1&&sum1!=sum2){
        		cout<<"	Los numeros del jugador 2 sumados son mayores gana jugador 2!\n";
        	}else if(sum2!=sum1){cout<<"Los numeros del jugador 1 sumados son mayores gana jugador 1!\n";}
        	else cout<<" aun con las sumas sigue siendo un empate...\n";
        }
    }


