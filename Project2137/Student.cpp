#include "Student.h"

Student::Student(int id, std::string name, std::string surname, Date birthDate, Gender gender, std::string pesel, std::string nationality) :
	m_id(id), m_name(name), m_surname(surname), m_birthDate(birthDate), m_gender(gender), m_pesel(pesel), m_nationality(nationality)
{
}

int Student::GetId() const
{
	return m_id;
}

const std::string& Student::GetPesel() const
{
	return m_pesel;
}

bool Student::operator==(const Student& student) const
{
	return student.GetId() == m_id;
}
