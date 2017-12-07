#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <sstream>

using namespace std;

string konwersjaWektoraDoOdpowiedniegoFormatu (vector<string>wektorDoKonwersji) {
    string wektorPoKonwersji;
    stringstream ss;
    for(int i=0; i<wektorDoKonwersji.size(); i++) {
        ss<<wektorDoKonwersji[i]+"|";
    }
    wektorPoKonwersji=ss.str();
    return wektorPoKonwersji;
}
void zapisDanychDoPliku(vector<string>daneDoZapisu, string nazwaPliku) {
    nazwaPliku+="_nowy_format.txt";
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out|ios::app);
    if (plik.good()) {
        for(int i=0; i<daneDoZapisu.size(); i++){
            plik<<daneDoZapisu[i]<<endl;
        }

        plik.close();

        cout<<"Dane zostaly zapisane."<<endl;
        Sleep(1000);
    } else {
        cout<<"Nie mozna otworzyc pliku: AdressBook.txt"<<endl;
        system("pause");
    }
}
void pobranieDanychZPliku(vector<string>&danePoKonwersji, string nazwaPliku) {
    int nrLini=1;
    string linia;
    nazwaPliku+=".txt";
    vector<string>daneJednegoZnajomego;
    fstream plik;
    plik.open(nazwaPliku.c_str(),ios::in|ios::out);

    if (plik.good()==false) {
        exit(0);
    }

    while(getline(plik,linia)) {
        switch(nrLini) {
        case 1:
            daneJednegoZnajomego.push_back(linia);
            break;
        case 2:
            daneJednegoZnajomego.push_back(linia);
            break;
        case 3:
            daneJednegoZnajomego.push_back(linia);
            break;
        case 4:
            daneJednegoZnajomego.push_back(linia);
            break;
        case 5:
            daneJednegoZnajomego.push_back(linia);
            break;
        case 6:
            daneJednegoZnajomego.push_back(linia);
            break;
        }
        if (nrLini==6) {
            nrLini=0;
            danePoKonwersji.push_back(konwersjaWektoraDoOdpowiedniegoFormatu(daneJednegoZnajomego));
            daneJednegoZnajomego.clear();
        }
        nrLini++;
    }
    plik.close();
}
int main() {
    vector<string>danePoKonwersji;
    string nazwaPliku;
    cout<<"Podaj nazwe pliku tekstowego: ";
    cin>>nazwaPliku;
    pobranieDanychZPliku(danePoKonwersji,nazwaPliku);
    zapisDanychDoPliku(danePoKonwersji, nazwaPliku);
    return 0;
}
