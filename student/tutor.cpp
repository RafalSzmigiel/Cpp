#include "tutor.h"

Tutor::Tutor(string ty ,int li, string im , string na , int wi , char pl) : Czlowiek(im,na,wi,pl)
{
    tytul_naukowy = ty;
    liczba_publikacji = li;
}
Tutor::~Tutor()
{

}
.
.
...
