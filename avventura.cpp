#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstring>
#include <cmath>
#include <windows.h>
#define ROWS 4
#define COLUMNS 4
#define DIM 10
using namespace std;
//indovinello conversione in secondi
class Time{
	private:
		double ore;
		double minuti;
		double secondi;
	public:
		void setOre(int r);
		int getOre(void);
		void setMinuti(int m);
		int getMinuti(void);
		void setSecondi(int s);
		int getSecondi(void);
		Time secondiTot (int);
};
void Time::setOre (int r){
	ore=r;
}
void Time::setMinuti (int m){
	minuti=m;
}
void Time::setSecondi (int s){
	secondi=s;
}
int Time::getOre (void){
	return ore;
}
int Time::getMinuti (void){
	return minuti;
}
int Time::getSecondi(void){
	return secondi;
}
Time Time::secondiTot(int){
	Time t;
	t.setSecondi((ore*60*60)+(minuti*60)+(secondi));
	return t;
}
class Rettangolo {
 	private:
 		double base, altezza;
 	public:
 		void Assegna(double b, double h) {
 			base = b;
 			altezza = h;
 		}
 		double Area() {
 			return base*altezza;
 		}
};
class Ricorsiva{
	private:
		int numero;
		int potenza;
	public:
		void ricorsiva(int n,int i){
			numero=n;
			potenza=i;
		}
		int Potenza(int numero,int potenza){
			if(potenza==0){
				return 0;
			}
			return numero+Potenza(numero,potenza-1);
		}
};
int vite(int &numero_vite){//se è 0 finisce il giocoù
	fstream fileAvventura;
	fileAvventura.open("Avventura.txt",ios::out);
	if(numero_vite==0){
		cout<<"prova non passata hai finito le vite";
		fileAvventura<<"HAI PERSO IL GIOCO SEI ARRIVATO ALLA FINE... :(\n";
		exit(EXIT_SUCCESS);//definita nell' cstdlib EXIT_SUCCESS --> restituisce un valore intero
	}
	fileAvventura.close();
}
int vite1(int i){//se non passa la prova finisce il gioco
	fstream fileAvventura;
	fileAvventura.open("Avventura.txt",ios::out);
	if(i==0){
		cout<<"prova non passata";
		fileAvventura<<"HAI PERSO IL GIOCO SEI ARRIVATO ALLA FINE...\n";
		fileAvventura<<"NON HAI VINTO IL LANCIO DEI DADI... :( \n";
		exit(EXIT_SUCCESS);//definita nell' cstdlib EXIT_SUCCESS --> restituisce un valore intero ed esce
	}
	fileAvventura.close();
}
class Dado{
	private:
		int n_Facce;
	public:
		Dado(int num_Facce){
			n_Facce=6;
			srand(time(NULL));
		}
		int lancioDado(){
			return rand()%n_Facce+1; //da 1 a 6 dipende dal numero delle facce
		}
};
//indovinello matrice diagonale principale
int matrice(int b[][COLUMNS],int &numero_vite,int &suggerimenti){
	int check_matrice=0;
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
    cin>>check_matrice;
    if  (check_matrice<1 or check_matrice>4){
    	cout<<"Attenzione! Per rispondere devi digitare un numero da 1 a 4!";
		cout<<"Inserisci di nuovo la risposta";
		cin>>check_matrice;
	}
    while(check_matrice==4){
    	cout<<"la diagonale principale è composta dai numeri che hanno stessi indici \n";
    	suggerimenti=suggerimenti-1;//classe suggerimenti per contollo se = a 0;
    	cin>>check_matrice;
	}
    if(check_matrice==1 or check_matrice==3){
    	cout<<"Risposta Errata perdi una vita \n";
    	numero_vite=numero_vite-1;
   	}else
   		cout<<"Risposta corretta!";
}
class Quadrato {
 	private:
 		double lato;
 	public:
 		void Assegna(double l) {
 			lato = l;
 		}
 		double Area() {
 			return lato*lato;
 		}
};
int main(void){
	int lato = 4;
	int numero_vite = 3;
	int prato_da_tagliare=0;
	int n_tentativi=5;
	int superficie=0;
	int risultato=0;
	int b[ROWS][COLUMNS];
	string nome_personaggio;
	int n_suggerimenti=3;
	int scelta_bivio1=0;
	int digitazione_secondi_totali=0;
	string stringa1= "Zack";
	string stringa1minuscola="zack";
	string stringa2= "Melany";
	string stringa2minuscola= "melany";
	string stringa3="John";
	string stringa3minuscola= "john";
	string stringa4="Alfred";
	string stringa4minuscola= "alfred";
	fstream fileAvventura;
	fileAvventura.open("Avventura.txt",ios::out);
    cout<<"... 12 Agosto... una calda giornata di estate, sono le 02:34 e stai dormendo tranquillo, \n";
	cout<<"a un certo punto ti svegli dentro un bosco.\n";
	cout<<"...Con te non hai niente, vedi solo alberi, alberi ovunque...\n";
	cout << endl;
  	cout<<"...A terra trovi un biglietto...\n";
  	cout<<"\n";
  	cout<<"BIGLIETTO: ...ti trovi dentro un mondo parallelo\n"; 
	cout<<"abitato da personaggi che non sono felici se il loro\n";
	cout<<"territorio viene scoperto da un nuovo individuo,\n"; 
	cout<<"hai solo una soluzione per scappare, arrivare alla fine...\n";
	cout<<endl;
	Sleep (5000);
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
	//Sleep (15000);
	cout<<"Bene, ora e' il momento di scegliere il personaggio che vuoi essere in questa fantastica avventura!\n";
	cout<<"Chi vuoi essere tra: Zack, John, Melany e Alfred?"<<endl;
	cin>>nome_personaggio;//controllare le lettere (while)
	cout<<endl;
	while (nome_personaggio != stringa1 and nome_personaggio!= stringa2 and nome_personaggio!= stringa3 and nome_personaggio!= stringa4 and nome_personaggio != stringa1minuscola and nome_personaggio != stringa2minuscola and nome_personaggio != stringa3minuscola and nome_personaggio != stringa4minuscola ){
		cout<<"Personaggio inesistente! Scegliere tra: Zack, John, Melany e Alfred: \n";
		cin>>nome_personaggio;
	}
	cout<<"Ottima scelta "<<nome_personaggio<<"! E' il momento di iniziare!";
	cout<<endl;
	//Sleep (3000);
	cout<<"Cominciato il tuo cammino, i problemi non tardano ad arrivare...ti trovi davanti ad un bivio.\n";
	cout<<"Puoi scegliere due strade: se vai a sinistra, raggiungerai le cascate";
	cout<<"Se invece sceglierai la strada sulla destra, arriverai una fitta vegetazione...";
	cout<<endl;
	//Sleep (5000);
	cout<<"Fai la tua scelta!\n"; 
	cout <<"Digita 1 per scegliere la strada che ti portera alle cascate, \n Digita 2 per scegliere la strada che ti porterà nella fitta vegetazione...\n";
	cout<<"SCELTA ...  ";
	cin>>scelta_bivio1;
	while(scelta_bivio1!=1 and scelta_bivio1!=2){
		cout<<"Attenzione! Hai solo due scelte! Digita 1 per scegliere la strada che ti portera alle cascate, \n Digita 2 per scegliere la strada che ti porterà nella fitta vegetazione...\n";	
		cin>>scelta_bivio1;
	}
	if(scelta_bivio1==1){
		cout<<"Perfetto! Dirigiamoci verso le cascate!";
	} 
	if(scelta_bivio1==2){
		cout<<"Perfetto! Dirigiamoci verso la vegetazione!";
	}
//SOMMA DIAGONALE PRINCIPALE
	cout<<"stabilisci la somma della diagonale principale \n";
	matrice(b,numero_vite,n_suggerimenti);
	vite(numero_vite);
	cout<<"Numero vite rimaste ... "<<numero_vite<<endl;
	cout<<"Numero suggerimenti rimasti ... "<<n_suggerimenti<<endl;
//AREA QUADRATO 
	cout<<"Molto bene per preseguire dovrai stabilire la superficie totale di un cubo, le faccie sono di lato 4\n";
	cin>>superficie;
	Quadrato cubo;
	cubo.Assegna (4.0);
	if (superficie==(cubo.Area()*6)){
 		cout<<"Risposta corretta! \n";
	}else{
 		cout<<"Risposta errara! \n";
 		numero_vite=numero_vite-1;
 	}
	vite(numero_vite);
	cout<<"Numero vite rimaste ... "<<numero_vite<<endl;
	cout<<"Numero suggerimenti rimasti ... "<<n_suggerimenti<<endl;
	cout<<endl;
	Time x,y,z;
	int r;
//INDOVINELLO CONVERSIONE ORARIO IN SECONDI
	cout<<"inserisci ore in questo momento: ";
	cin>>r;
	while(r<0 or r>24){
		cout<<"inserisci ore in questo momento:";
		cin>>r;
	}
	x.setOre(r);
	cout<<"inserisci minuti in questo momento: ";
	cin>>r;
	while(r<0 or r>59){
		cout<<"inserisci minuti in questo momento: ";
		cin>>r;
	}
	x.setMinuti(r);
	cout<<"inserisci secondi in questo momento: ";
	cin>>r;
	while(r<0 or r>59){
		cout<<"inserisci secondi in questo momento:  ";
		cin>>r;
	}
	x.setSecondi(r);
	cout<<"stabilisci quanti secondi totali considerante le ore i minuti e i secondi\n";
	cin>>digitazione_secondi_totali;
	z=x.secondiTot(r);
	if(digitazione_secondi_totali==z.getSecondi()){
		cout<<"Risposta esatta!! Fortissimo";
	}else{
		cout<<"Risposta Errata perdi una vita \n";
    	numero_vite=numero_vite-1;
	}
	vite(numero_vite);//funzione che conta le vite	
    cout<<"Numero vite rimaste ... "<<numero_vite<<endl;
	cout<<"Numero suggerimenti rimasti ... "<<n_suggerimenti<<endl;
//TROVARE AREA DA TAGLIARE
    Rettangolo prato;
 	prato.Assegna(5.0, 4.0);
 	cout<<"attenzione per superare il livello dovrai tagliare un prato rettangolare 5 x 4 \n";
 	cout<<"Quanta area di giardino dovrai tagliare per completare il livello ";
 	cin>>prato_da_tagliare;
 	if (prato_da_tagliare==prato.Area()){
 		cout<<"Risposta corretta \n";
	}else{
 		cout<<"Risposta errata! \n";
 		numero_vite=numero_vite-1;
 	}
 	vite(numero_vite);
 	cout<<"Numero vite rimaste ... "<<numero_vite<<endl;
	cout<<"Numero suggerimenti rimasti ... "<<n_suggerimenti<<endl;
//MOLTIPLICAZIONE RICORSIVA CON CLASSI
	cout<<"Per andare avanti completa questo livello \n";
	cout<<"LIVELLO finale... \n";
	Sleep(1000);
	cout<<"Stabilisci la moltiplicazione tra due numeri 8 e 9 ricorsivamente\n";
	cout<<"Inserisci risultato:  ";
	cin>>risultato;
	cout<<endl; 
	Ricorsiva r1;
	if(risultato==r1.Potenza(8,9)){//classe ricorsiva
		cout<<"Livello superato!!!, preparati all'ultimo livello...\n";
	}else{
		cout<<"Hai perso una vita!\n";
		numero_vite=numero_vite-1;
	}
	vite(numero_vite);
 	cout<<"Numero vite rimaste ... "<<numero_vite<<endl;
	cout<<"Numero suggerimenti rimasti ... "<<n_suggerimenti<<endl;
//LANCIO DADI
	int conta=0;
	Dado d1(6);
	Dado d2(6);
	int dd1=0;
	int dd2=0;
	while(n_tentativi!=0){
		dd1=d1.lancioDado();
		dd2=d2.lancioDado();
		cout<<dd1<<" "<<dd2<<endl;
		if((dd1+dd2)==10)
			conta++;
		n_tentativi--;
	}
	if (conta==0)
		vite1(0);
	cout<<"HAI VINTO IL GIOCO SEI ARRIVATO ALLA FINE...COMPLIMENTI";
	fileAvventura<<"HAI VINTO IL GIOCO SEI ARRIVATO ALLA FINE...COMPLIMENTI  :) \n";
	fileAvventura<<"Numero vite rimaste ... "<<numero_vite<<endl;
	fileAvventura.close();
}

