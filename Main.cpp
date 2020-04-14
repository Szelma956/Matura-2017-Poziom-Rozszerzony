#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int szer = 320;
const int wys = 200;

int obraz[szer][wys];

int main() {

    ifstream plik("dane.txt");
    ofstream wynik("wynik.txt");
    int max = 0;
    int min = 255;
    for (int pion = 0; !plik.eof() && pion < wys; pion++) {

        for (int poziom = 0; !plik.eof() && poziom < szer; poziom++) {
            plik >> obraz[poziom][pion];
        }
    }
    for (int i = 0; i < szer; i++) {

        for (int j = 0; j < wys; j++) {
            
            if (max < obraz[i][j])
                max = obraz[i][j];
            if (min > obraz[i][j])
                min = obraz[i][j];

        }
    }
         
    wynik << "a)" << '\n' << max << '\n' << min << '\n';

    int do_usu = 0;
    
    for (int j = 0; j < wys; j++) {

        for (int i = 0; i < szer; i++) {

            int k = szer - 1 - i;
            if (obraz[i][j] != obraz[k][j]) {
                do_usu++;
                break;
            }


        }
    }
    wynik << "b)" << '\n' << do_usu << '\n';

    int kontrast = 0;

    for (int j = 0; j < wys; j++) {

        for (int i = 0; i < szer; i++) {

            if (i > 0 && abs(obraz[i][j] - obraz[i - 1][j]) > 128) {
                kontrast++;
                continue;
            }
            if (i < szer - 1 && abs(obraz[i][j] - obraz[i + 1][j]) > 128) {
                kontrast++;
                continue;
            }
            if (j > 0 && abs(obraz[i][j] - obraz[i][j - 1]) > 128) {
                kontrast++;
                continue;
            }
            if (j < wys -1  && abs(obraz[i][j] - obraz[i][j + 1]) > 128) {
                kontrast++;
                continue;
            }


        }
    }
    wynik << "c)" << '\n' << kontrast << '\n';

    int ciag_max = 0;

    for (int i = 0; i < szer; i++) {
        int ciag_bierz = 1;
        for (int j = 0; j < wys; j++) {

            if (j > 0 && obraz[i][j] == obraz[i][j - 1])
                ciag_bierz++;
            else {
                if (ciag_bierz > ciag_max)
                    ciag_max = ciag_bierz;
                ciag_bierz = 1;
            }
                
        }
    }
    wynik << "d)" << '\n' << ciag_max << '\n';
    return 0;
}