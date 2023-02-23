#include "StudentBase.h"

int main()
{
	return 0;
}

/*
Stworzyæ nowy projekt zgodnie z zasadami TDD. (musz¹ byæ testy, ka¿da funkcjonalnoœæ musi byæ otestowana) (failuj¹cy test->dzia³aj¹cy test->refactor)
Projekt powinien byæ wersjonowany(GITHUB)
StudentBase
Baza danych studentów

1. Dodanie nowego studenta
---------------------------------------------------------------------------------------------------------------------------------------------------
2. Wyszukanie studenta(po peselu lub id lub nazwisku)->result->mo¿na wypisaæ(studenta mo¿na wyœwietliæ)
3. Usuniêcie studenta
4. Edycja danych studenta
5. Export do Excela
6. Wydruk do PDF
Student
{
	id;
	imie
	nazwisko
	data urodzenia
	p³eæ
	pesel; // co z obcokrajowcami?? (nie musisz mieæ ¿adnego zastêpczego pola)
	narodowoœæ
}

Zad.dom

1. AddStudent powinien mieæ argumenty wype³niaj¹ce dane studenta.
2. Zapewni³, ¿e ka¿dy student ma unikalne ID (nie powtarza siê ID).
3. Doda³ usuwanie studenta (nie po indeksie (pozycji w wektorze)). (zawsze tylko jeden konkretny student)

*/