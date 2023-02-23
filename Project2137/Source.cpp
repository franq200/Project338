#include "StudentBase.h"

int main()
{
	return 0;
}

/*
Stworzy� nowy projekt zgodnie z zasadami TDD. (musz� by� testy, ka�da funkcjonalno�� musi by� otestowana) (failuj�cy test->dzia�aj�cy test->refactor)
Projekt powinien by� wersjonowany(GITHUB)
StudentBase
Baza danych student�w

1. Dodanie nowego studenta
---------------------------------------------------------------------------------------------------------------------------------------------------
2. Wyszukanie studenta(po peselu lub id lub nazwisku)->result->mo�na wypisa�(studenta mo�na wy�wietli�)
3. Usuni�cie studenta
4. Edycja danych studenta
5. Export do Excela
6. Wydruk do PDF
Student
{
	id;
	imie
	nazwisko
	data urodzenia
	p�e�
	pesel; // co z obcokrajowcami?? (nie musisz mie� �adnego zast�pczego pola)
	narodowo��
}

Zad.dom

1. AddStudent powinien mie� argumenty wype�niaj�ce dane studenta.
2. Zapewni�, �e ka�dy student ma unikalne ID (nie powtarza si� ID).
3. Doda� usuwanie studenta (nie po indeksie (pozycji w wektorze)). (zawsze tylko jeden konkretny student)

*/