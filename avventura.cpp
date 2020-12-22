#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <windows.h>
#define ROWS 4
#define COLUMNS 4
using namespace std;
//indovinello matrice diagonale principale
int matrice(int b[][COLUMNS],int &numero_vite,int &suggerimenti){
	int check=0;
 	srand(time(NULL));
    int somma=0;
    for ( int i = 0; i < ROWS; i++){
        for ( int j = 0; j < COLUMNS; j++){
            b[i][j] = rand()%10+1;
            cout << b[i][j] <<"\t";
        }
        cout << endl;
    }
    for ( int i = 0; i < ROWS; i++){
        for ( int j = 0; j < COLUMNS; j++){
            if (i==j){
                somma=somma+b[i][j];
            }
        }
    }
    cout<<" 1 - "<< somma+1<<endl;
    cout<<" 2 - "<< somma<<endl;
    cout<<" 3 - "<< somma+5<<endl;
    cout<<" 4 -  Suggerimento"<<endl;
    cin>>check;
    while(check==4){
    	cout<<"la diagonale principale è composta dai numeri che hanno stessi indici \n";
    	suggerimenti=suggerimenti-1;
    	cin>>check;
	}
    if(check==1 or check==3){
    	cout<<"Risposta Errata perdi una vita \n";
    	numero_vite=numero_vite-1;
   	}else
   		cout<<"Risposta corretta!";
}
int getx() { 
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   	GetConsoleScreenBufferInfo(h,&csbi);
	return csbi.dwCursorPosition.X;
}
int gety() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&csbi);
    return csbi.dwCursorPosition.Y;
}
void gotoxy(int x, int y){ 
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main(void){
	int x,y;
	int numero_vite = 3;
	int b[ROWS][COLUMNS];
	x = getx();
	y = gety();
//	int invio;
	string nome_personaggio;
	int n_suggerimenti=3;
	int scelta_bivio1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k=2;
    gotoxy(x,y);
    SetConsoleTextAttribute(hConsole, k);
    cout<<"... 12 Agosto... una calda giornata di estate, sono le 02:34 e stai dormendo tranquillo, \n";
	cout<<"a un certo punto ti svegli dentro un bosco.\n";
	cout<<"...Con te non hai niente, vedi solo alberi, alberi ovunque...\n";
	cout << endl;
  	SetConsoleTextAttribute(hConsole, 7);
  	int a=5;
  	SetConsoleTextAttribute(hConsole, a);
  	cout<<"...A terra trovi un biglietto...\n";
  	cout<<"\n";
  	SetConsoleTextAttribute(hConsole, 7);
  	cout<<"BIGLIETTO: ...ti trovi dentro un mondo parallelo\n"; 
	cout<<"abitato da personaggi che non sono felici se il loro\n";
	cout<<"territorio viene scoperto da un nuovo individuo,\n"; 
	cout<<"hai solo una soluzione per scappare, arrivare alla fine...\n";
	cout<<endl;
	cout<<"Scegli un personaggio per continuare...\n";
	cout<<"-Zack: ragazzo giovane e sportivo, ama lo sport, ha una grande atleticità ed è molto furbo.\n";  
	cout<<"  Astuzia=4 Agilità=5 Coraggio=2 \n";
	cout<<endl;
	cout<<"-John: un uomo anziano, ma questo non vuol dire che non sia in grado di affrontare l’avventura! \n";
	cout<<"Grazie alla sua età e alla sua saggezza, è in grado di risolvere qualsiasi tipo di enigma, anche i più complicati!\n";  
	cout<<"  Astuzia=5 Agilità=1 Coraggio=3\n";
	cout<<endl;
	cout<<"-Melany: una ragazzina dolce e innocente….all’apparenza! In realtà Melany ha un grande coraggio,\n";
	cout<<"non si ferma davanti a niente a nessuno, una vera e propria temeraria!\n ";
	cout<<"  Astuzia=2 Agilità=3 Coraggio=5\n";
	cout<<endl;
	cout<<"-Alfred: il vero e proprio intelligentone...purtroppo gli piacciono davvero tanto le merendine!";
	cout<<"Con la sua intelligenza, nulla, nemmeno il più difficile degli indovinelli può fermarlo...\n";
	cout<<"speriamo però che con il suo fisico non proprio atletico riesca a scappare dai pericoli! \n ";
	cout<<"  Astuzia=5 Agilità=1, Coraggio 3 \n";
	cout<<endl;
	cout<<"Bene, ora è il momento di scegliere il personaggio che vuoi essere in questa fantastica avventura!\n";
	cout<<"Chi vuoi essere tra: Zack, John, Melany e Alfred?"<<endl;
	cin>>nome_personaggio;//controllare le lettere (while)
	cout<<endl;
	cout<<"Ottima scelta "<<nome_personaggio<<"! E' il momento di iniziare!";
	cout<<endl;
	cout<<"Cominciato il tuo cammino, i problemi non tardano ad arrivare...ti trovi davanti ad un bivio.\n";
	cout<<"Puoi scegliere due strade: se vai a sinistra, raggiungerai le cascate";
	cout<<"Se invece sceglierai la strada sulla destra, arriverai una fitta vegetazione...";
	cout<<endl;
	cout<<"Fai la tua scelta!\n"; 
	cout <<"Digita 1 per scegliere la strada che ti portera alle cascate, \n Digita 2 per scegliere la strada che ti porterà nella fitta vegetazione...\n";
	cout<<"SCELTA ...  ";
	cin>>scelta_bivio1;
	cout<<endl;
	if(scelta_bivio1==1){
		cout<<"Perfetto! Dirigiamoci verso le cascate!";
	} 
	if(scelta_bivio1==2){
		cout<<"Perfetto! Dirigiamoci verso la vegetazione!";
	}
	/*… davanti a te c’è una pietra e per superarla dovrai risolvere l’indovinello… 
	attenzione a disposizione hai solo 3 vite ogni errore una vita si perde, 
	e altrettanti suggerimenti che ti possono utilizzare per ricevere un aiuto… 
	attenzione però se le vite termineranno perderai e verrai catturato, ti capiterà di 
	scegliere dei bivi se scegli quello giusto troverai un curatore…*/
	cout<<"stabilisci la somma della diagonale principale \n";
	matrice(b,numero_vite,n_suggerimenti);//MATRICE QUADRATA TROVA SOMMA
	cout<<"Numero vite rimaste ... "<<numero_vite<<endl;
	cout<<"Numero suggerimenti rimasti ... "<<n_suggerimenti<<endl;
	cout<<endl;
	
}

