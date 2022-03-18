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

ESERCIZIO n.14 (Verifica, es.1)
Data in input l'età di uno studente, visualizzare a video 
"sei maggiorenne" o "sei minorenne"
15/11/2021 (Verifica in laboratorio)
*/

#include <iostream>

using namespace std;

int main()
{
    // dichiarazione variabili
    int eta;
    // programma
    cout << "Quanti anni hai?" << endl;
    cin >> eta;
    if(eta < 18)
    {
        cout << "Sei minorenne" << endl;
    }
    else
    {
        cout << "Sei maggiorenne" << endl;
    }
    return 0;
}