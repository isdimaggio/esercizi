/*
Copyright 2021 Lo Mele Vittorio

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

ESERCIZIO n.13 -  Integrazione esercizi su if-else. Programma a scelta
multipla. Le tracce sono documentate dopo.
05/11/2021 (Esercitazione a casa / in laoratorio)
*/

#include <iostream>
#include <math.h>

using namespace std;

void stampaTracce();
void esercizio1();
void esercizio2();
void esercizio3();
void esercizio4();
void esercizio5();
void esercizio6();
void esercizio7();
void esercizio8();

int main()
{
    // dichiarazione delle variabili
    char comando;
    bool ciclo = true;
    // stampa delle tracce
    cout << "Esercizio integrativo. Raccolta di esercitazioni su if-else." << endl;
    while(ciclo)
    {

        cout << "1 - 8: Esegui il numero esercizio." << endl;
        cout << "S: Stampa le tracce." << endl;
        cout << "Qualsiasi altro tasto: esci dal programma" << endl;
        cout << "> ";
        cin >> comando;

        switch(comando)
        {

            case 'S':
            stampaTracce();
            break;

            case 's':
            stampaTracce();
            break;

            case '1':
            esercizio1();
            break;

            case '2':
            esercizio2();
            break;

            case '3':
            esercizio3();
            break;

            case '4':
            esercizio4();
            break;

            case '5':
            esercizio5();
            break;

            case '6':
            esercizio6();
            break;

            case '7':
            esercizio7();
            break;

            case '8':
            esercizio8();
            break;

            default:
            ciclo = false;
            break;

        }
    }
}

void stampaTracce()
{
    // stampa delle tracce
    cout << endl << "----------------------" << endl;
    cout << "ESERCIZIO 1: Il programma legge due numeri e controlla se il primo è maggiore del secondo. " << endl;
    cout << "ESERCIZIO 2: L’utente inserisce il proprio peso e il programma dice se è in sovrappeso o normopeso (ovvero con peso maggiore uguale a 70 kg si è in sovrappeso). " << endl;
    cout << "ESERCIZIO 3: Il programma legge due numeri e controlla se il primo è multiplo del secondo (usare il resto della divisione %). " << endl;
    cout << "ESERCIZIO 4: Dati 3 numeri interi visualizzare il maggiore. " << endl;
    cout << "ESERCIZIO 5: Il programma legge tre numeri e li mette in ordine crescente (usare gli operatori logici). " << endl;
    cout << "ESERCIZIO 6: Fare un programma che legge i coefficienti a,b,c di un’equazione di secondo grado e ne calcola le soluzioni,quando possibile (fare gli opportuni controlli)." << endl;
    cout << "ESERCIZIO 7: Scrivere un programma che legge un voto e dice se insufficiente o sufficiente e se è insufficiente distinguetra gravemente insufficiente (minore o uguale a 4) o insufficiente ovvero compreso tra 4 (escluso) e 6(escluso). " << endl;
    cout << "ESERCIZIO 8: Scrivere un programma che legge i lati di un triangolo e dice se questo è un triangolo rettangolo. " << endl;
    cout << "----------------------" << endl << endl;
}

void esercizio1()
{
    // Esercizio 1
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 1" << endl;
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    if(a == b)
    {
        cout << "I due numeri sono uguali" << endl;
    }
    else
    {
        if(a > b)
        {
            cout << "Il numero maggiore è il primo, ovvero " << a << endl;
        }
        else
        {
            cout << "Il numero maggiore è il secondo, ovvero " << b << endl;
        }
    }
    cout << "----------------------" << endl << endl;
}

void esercizio2()
{
    // Esercizio 2
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 2" << endl;
    // dichiarazione variabili
    int p;

	cout << "Inserisci il tuo peso in kg: " << endl;
	cin >> p;

	if (p >= 70)
	{
		cout << "Sovrappeso" << endl;
	}
	else
	{
		cout << "Normopeso" << endl;
	}
    cout << "----------------------" << endl << endl;
}

void esercizio3()
{
    // Esercizio 3
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 3" << endl;
    // dichiarazione variabili
    int a, b;
    // programma
    cout << "Inserisci il primo numero: ";
    cin >> a;
    cout << "Inserisci il secondo numero: ";
    cin >> b;
    if((a % b) == 0)
    {
        cout << "Il secondo numero è multiplo del primo :)" << endl;
    }
    else
    {
        cout << "Il secondo numero non è multiplo del primo :(" << endl;
    }
    cout << "----------------------" << endl << endl;
}

void esercizio4()
{
    // Esercizio 4
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 4" << endl;
    // dichiarazione variabili
    int primo, secondo, terzo, max = 0;

    // programma
	cout << "Inserisci il primo valore: ";
	cin >> primo;
	cout << "Inserisci il secondo valore: ";
	cin >> secondo;
	cout << "Inserisci il terzo valore: ";
	cin >> terzo;

    if(primo > max){
        max = primo;
    }

    if(secondo > max){
        max = secondo;
    }

    if(terzo > max){
        max = terzo;
    }

    cout << "Il numero più grande è " << max << endl;

    cout << "----------------------" << endl << endl;
}

void esercizio5()
{
    // Esercizio 5
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 5" << endl;
    int primo, secondo, terzo;

	cout << "Inserisci il primo valore: ";
	cin >> primo;
	cout << "Inserisci il secondo valore: ";
	cin >> secondo;
	cout << "Inserisci il terzo valore: ";
	cin >> terzo;

	if ((primo <= secondo) && (primo <= terzo))
	{
		if (secondo <= terzo)
		{
			cout << "I numeri in ordine sono: " << primo << ", " << secondo << ", " << terzo << endl;
		}
		else
		{
            cout << "I numeri in ordine sono: " << primo << ", " << terzo << ", " << secondo << endl;
		}
	}
	else
	{
		if ((secondo <= terzo) && (secondo <= primo))
		{
			if (terzo <= primo)
			{
				cout << "I numeri in ordine sono: " << secondo << ", " << terzo << ", " << primo << endl;
			}
			else
			{
				cout << "I numeri in ordine sono: " << secondo << ", " << primo << ", " << terzo << endl;
			}
		}
		else
		{
			if ((terzo <= primo) && (terzo <= secondo)) 
			{
				if (secondo <= primo)
				{
					cout << "I numeri in ordine sono: " << terzo << ", " << secondo << ", " << primo << endl;
				}
				else
				{
					cout << "I numeri in ordine sono: " << terzo << ", " << primo << ", " << secondo << endl;
				}
			}
		}
	}
    cout << "----------------------" << endl << endl;
}

void esercizio6()
{
    // Esercizio 6
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 6" << endl;
    // dichiarazione variabili
    double a, b, tn, x1, x2, delta;
    
    cout << "Inserisci il coefficiente di a: ";
    cin >> a;
    cout << "Inserisci il coefficiente di b: ";
    cin >> b;
    cout << "Inserisci il termine noto: ";
    cin >> tn;

    // calcolo delta
    delta = ((b * b) - (4 * a * tn));
    cout << "Il delta è " << delta << endl;

    // calcolo soluzioni
    x1 = (-(b) - (sqrt(delta))) / (2 * a);
    x2 = (-(b) + (sqrt(delta))) / (2 * a);
    
    if (delta == 0)
    {
        cout << "Le soluzioni sono coincidenti, x=" << x1 << endl;
    }
    else if (delta < 0)
    {
        cout << "Non ci sono soluzioni reali" << endl;
    }
    else
    {
        cout << "Le soluzioni sono: x1=" << x1 << " x2=" << x2 <<endl;
    }
    cout << "----------------------" << endl << endl;
}

void esercizio7()
{
    // Esercizio 7
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 7" << endl;
    // dichiarazione variabili
    float voto;
    // programma
    if(voto >= 6){
        cout << "Il voto è sufficiente" << endl;
    }else{
        if(voto <= 4){
            cout << "Il voto gravemente insufficiente" << endl;
        }else{
            cout << "Il voto è lievemente insufficiente" << endl;
        }
    }
    cout << "----------------------" << endl << endl;
}

void esercizio8()
{
    // Esercizio 8
    cout << endl << "----------------------" << endl;
    cout << "Esercizio 8: Work In progress" << endl;
    cout << "----------------------" << endl << endl;
}