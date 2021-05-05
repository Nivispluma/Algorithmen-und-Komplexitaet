// GGT.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
using namespace std;

//-------------Collatz Problem----------------

void collatz(int b)
{
    int a,i;
    a = b;
    i = 0;

    if (a % 2 == 0)
    {
        a = a / 2;
    }

    else
    {
        a = 3 * a + 1;
    }
    cout << endl << a;
    collatz(a);
    return;
}

//-----------------------------
//-----------------------------

int GGTStein(int zahl1, int zahl2) //https://en.wikipedia.org/wiki/Binary_GCD_algorithm
{

    // % ist der Modulo Operator
    // & ist für Bitmaskierung
    // & -> wir maskieren mit eins, weil wenn die erste stelle gleich eins ist,
    // dann ist die Zahl ungerade

    if (zahl1 == zahl2) //Bedingung 1
    {
        return zahl1;
    }

    if (zahl1 == 0) //Bedingung 2 (Nullprüfung)
    {
        return zahl2;
    }
    if (zahl2 == 0) //Bedingung 3 (Nullprüfung)
    {
        return zahl1;
    }

    //---------------------------

    if ((zahl1 % 2) == 0) 
    {
        if ((zahl2 % 2) == 0) //Bedingung 4 (zahl 1 und Zahl 2 sind gerade)
        {
            return 2 * GGTStein(zahl1 / 2, zahl2 / 2);
        }

        if(zahl2 & 1) //Bedingung 5 (zahl 1 ist gerade und zahl 2 ist ungerade)
        {
            return GGTStein(zahl1 / 2, zahl2);
        }
    }

    if ((zahl2 % 2) == 0)
    {

        if (zahl1 & 1) //Bedingung 6 (zahl 1 ist ungerade und zahl 2 ist gerade)
        {
            return GGTStein(zahl1, zahl2 / 2);
        }
    }

    if(zahl1 & 1)
    {
        if(zahl2 & 1) //Bedingung 7 (beide sind ungerade)
        {
            return GGTStein(abs(zahl1 - zahl2), min(zahl1, zahl2)); //abs() gibt den Betrag zurück
        }                                                           //min() gibt die kleinere Zahl zurück
    }

}

//-----------------------------
//-----------------------------

int FibbItera(int index)
{
    int zahl1 = 0;
    int zahl2 = 1;
    int temp = 0;
    int i = index;
    do
    {
        temp = zahl2;
        zahl2 = zahl2 + zahl1;
        zahl1 = temp;
        i--;
        cout << i << endl;
    } while (i != 0);
    return zahl2;
}

//-----------------------------------

int main()
{
    /*
    int a = 0;
    do {
        cout << "Bitte eine Ganzzahl angeben: ";
        cin >> a;
        cout << endl;


    } while (a <= 0);

    collatz(a);
    */

    //cout << GGTStein(1168, 4450);

    cout << "Ergebniss: " << FibbItera(20);

    return 0;
}

