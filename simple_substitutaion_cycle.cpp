#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
string encrypt(string P_text, int k)
{
    char c;
    string c_text;
    for (int i = 0; i < P_text.length(); i++)
    {

        c = P_text.at(i);
        c = c + (char)k;
        c_text += c;
    }
    return c_text;
}

string decrpt(string Rc_text, int k)
{
    char r;
    string R_plain;
    for (int i = 0; i < Rc_text.size(); i++)
    {
        r = Rc_text.at(i);
        r = r - (char)k;

        R_plain += r;
    }
    return R_plain;
}

int main()
{
    int choice;
    int k;

    string P_text;
    string Rc_text;

    string R_plain;

    cout << "Press 1. For Only Encrypt your data" << endl;
    cout << "Press 2. For Only Decrypt your data" << endl;
    cout << "Press 3. For Both" << endl;
    cout << "Press 4. For retirve any encrpted message" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:

        cout << "Enter plain text" << endl;
        cin.ignore();
        getline(cin, P_text);

        cout << "Enter your key" << endl;
        cin >> k;
        cout << " Let's encrypt your Messgae";

        P_text.erase(remove(P_text.begin(), P_text.end(), ' '), P_text.end());

        cout << "Your transfer text: " << encrypt(P_text, k) << endl;

        cout << endl;
        break;

    case 2:

        cout << "Enter encrypted  text" << endl;
        cin.ignore();
        getline(cin, Rc_text);
        cout << "Enter your key" << endl;
        cin >> k;
        cout << "Reciver plain text is :" << decrpt(Rc_text, k) << endl;

        break;

    case 3:
        cout << "Enter your plain text" << endl;
        cin.ignore();

        getline(cin, P_text);
        // cin>>P_text;

        cout << "Enter key" << endl;
        cin >> k;
        P_text.erase(remove(P_text.begin(), P_text.end(), ' '), P_text.end());

        cout << "Your transfer text: " << encrypt(P_text, k) << endl;
        cout << "Your decrypt text is : " << decrpt(encrypt(P_text, k), k) << endl;
        break;

    case 4: 
         cout << "Enter your plain text" << endl;
        cin.ignore();

        getline(cin, P_text);

         P_text.erase(remove(P_text.begin(), P_text.end(), ' '), P_text.end());
         for (int  i = 0; i < 26; i++)
         {
        cout << "Your decrypt text is : " << decrpt(P_text, i) << endl;
             
         }
         
            break;

    default:
        break;
    }
}