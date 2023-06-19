//  drugim kroku musisz zdefiniować kształty, które chcesz rysować, np. koło, kwadrat, prostokąt, trójkąt, itp.
// (minimum 3). Stwórz abstrakcyjną klasę Figure, z której będą dziedziczyły konkretne figury. Możesz także 
// zastosować dziedziczenie wielokrotne, czyli np. z klasy Figure może dziedziczyć klasa Rectangle, a z Rectangle
// może dziedziczyć klasa Square. Każda figura musi posiadać współrzędne np. środka oraz wymiary 
// pozwalające ją narysować, np. promień w przypadku koła. Każda figura powinna też posiadać funkcję 
// odpowiedzialną za narysowanie jej na canvasie, np. draw(Canvas &c). Poszczególne piksele obrazka powinny 
// być „wypełniane” różnymi symbolami, w zależności od tego, czy należą do obszaru figury czy nie. Możemy 
// np. założyć, że każdy „piksel” obrazka, który należy do figury to #, a każdy piksel, który nie należy do figury to 
// spacja. To jakie symbole będą wykorzystane powinno być ustalane w pliku konfiguracyjnym (patrz kolejny 
// podpunkt)



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

class Canvas{
private:

public:
string wypelniacz;
string plik;
int width,height;
virtual void narysuj(int x, int y)=0;
void rozmiar(int x,int y){
width = x;
height = y;

}

string text(){

    return plik;
}
};

class ASCIICanvas:public Canvas{
private:

public:
ASCIICanvas(string nazwa,string c,int x,int y)
{
    width = x;
    height = y;
    plik = nazwa;
wypelniacz = c;
}
ASCIICanvas(string nazwa,int x,int y)
{
    width = x;
    height = y;
    plik = nazwa;
wypelniacz = " ";
}
ASCIICanvas(string nazwa)
{
    plik = nazwa;
}

void narysuj(int x, int y){
 


ofstream str;
 str.open(plik,ios_base::binary);
 if( str.good() == true )
{
    cout << "Pomyslnie otwarto plik: " << plik<<endl;
    for (int i = 0; i <= y+1; ++i) {
       
       if(i==0||i==y+1){
        for (int j = 0; j <= x+1; ++j) {
                if(j==0 || j==x+1){
                str << "|";  
            }
            else{

         str << "="; 

            }}
        }
else{
for (int j = 0; j <= x+1; ++j) {
                if(j==0 || j==x+1){
                str << "|";  
            }
            else{

         str << wypelniacz; 


    
}}}
str<<endl;
}
} else cout << "Dostep do pliku zostal zabroniony!" <<endl;
str.close();
 }};


class Figure{
public:
virtual void draw(Canvas &c)=0;


protected:
int wymiar_x;
int wymiar_y;
int wymiar_z;
int srodek_x;
int srodek_y;
string plik;
string symbol;

};

class Kwadrat:public Figure{
public:

Kwadrat(int x,string s,int wspolzedna_x, int wspolzedna_y){
wymiar_x = x;
srodek_x = wspolzedna_x;
srodek_y = wspolzedna_y;
symbol = s;
}

void draw(Canvas &c){
fstream st;
this->plik = c.plik;
st.open(plik,ios::in);

vector<string>lines;
    string line;
if(st.good()==true){
    
    while(getline(st,line)){
        lines.push_back(line);
    }
}
st.close();
st.open(plik,ios::out);
cout<<"naniesiony zostanie kwadrat w pliku: "<<plik<<endl;

if( st.good() == true )
{
    cout << "Pomyslnie otwarto plik: " << plik<<endl;



int x = wymiar_x;
int y_max = srodek_y+1;//srodek x i srodek y wskazuja na lewy gorny rog kwadratu(jego poczatek)
int x_max = srodek_x+1;

for(int x=0;x<lines.size();x++){
if(x!=y_max){
st<<lines[x]<<endl;
}
else{

for(int i=0;i<wymiar_x;i++){
st<<"|";
for(int z = 0;z<srodek_x;z++){
    st<<c.wypelniacz;
}
for(int j=0;j<wymiar_x;j++){
st<<symbol;
}

int h=0;
while(h!=(c.width-srodek_x-wymiar_x)){
st<<c.wypelniacz;
h++;
}
st<<"|";
st<<endl;
}
}
}
}
else {cout<<"blad otwierania  pliku"<<endl;};

st.close();
}};

class Prostokat:public Figure{
public:
Prostokat(int x,int y){
wymiar_x=x;
wymiar_y=y;
}
void draw(Canvas &c){
for(int i=0;i<wymiar_y;i++){
for(int j=0;j<wymiar_x;j++){
cout<<"#";
}
cout<<endl;
}}};

class Trojkat:public Figure{
public:
Trojkat(int x,int y){
wymiar_x=x;
wymiar_y=y;

}
void draw(Canvas &c){
cout<<"narysowany zostanie trojkat"<<endl;
int y = wymiar_y;
for(int i = y;i>0;i--){
int temp = wymiar_y-i;
for(int j=0;j<temp;j++){
cout<<" ";}
for(int m=0;m<i;m++){
    cout<<"#";
}
cout<<endl;
}}


};







int main(){
 



  Canvas * pt1 = new ASCIICanvas("zadanie2.txt","*",20,10);
Figure * pt2 = new Kwadrat(2,"#",2,1);
ASCIICanvas tablica("zadanie2.txt"," ",20,10);
Figure * pt3 = new Kwadrat(3,"*",14,8);
  tablica.narysuj(20,10);
pt2->draw(tablica);
 pt3->draw(tablica);




    return 0;
}