
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


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
private:
string plik;
public:
Prostokat(int x,int y,string s,int srodek1,int srodek2){
wymiar_x=x;
wymiar_y=y;
srodek_x = srodek1;
srodek_y = srodek2;
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

for(int i=0;i<wymiar_y;i++){
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
}


};

class Trojkat:public Figure{
public:
Trojkat(string s,int x,int y,int srodek1,int srodek2){
wymiar_x=x;
wymiar_y=y;
srodek_x=srodek1;
srodek_y=srodek2;
symbol = s;
}
void draw(Canvas &c){
cout<<"narysowany zostanie trojkat"<<endl;





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

for(int i = wymiar_y;i>0;i--){
int temp = wymiar_y-i;
for(int j=0;j<temp;j++){
st<<c.wypelniacz;}
for(int m=0;m<i;m++){
   st<<symbol;
}
cout<<endl;
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

else {cout<<"blad otwierania  pliku"<<endl;};

st.close();

}
};







int main(){
 



  Canvas * pt1 = new ASCIICanvas("zestaw5.txt","*",20,10);
Figure * pt2 = new Kwadrat(2,"#",2,1);
ASCIICanvas tablica("zestaw5.txt"," ",20,10);
  Figure*prostokat = new Prostokat(3,4,"#",7,6);
  tablica.narysuj(20,10);
pt2->draw(tablica);
prostokat->draw(tablica);



    return 0;
}
