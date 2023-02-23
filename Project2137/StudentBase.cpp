#include "StudentBase.h"
#include <algorithm>

size_t StudentBase::GetStudentsNumber() const
{
	return m_students.size();
}

void StudentBase::AddStudent(int id, std::string name, std::string surname, Date birthDate, Gender gender, std::string pesel, std::string nationality)
{
	if (std::any_of(m_students.begin(), m_students.end(), [id](const auto& el) {return id == el.GetId(); }))
	{
		throw std::exception("dwie osoby nie mog¹ mieæ takiego samego id");
	}

	m_students.push_back(Student(id, name, surname, birthDate, gender, pesel, nationality));
}

void StudentBase::DeleteStudent(int id)
{
	if (std::erase_if(m_students, [id](const auto& el) {return id == el.GetId(); }) == 0)
	{
		throw std::exception("nie ma studenta z takim id");
	}
}