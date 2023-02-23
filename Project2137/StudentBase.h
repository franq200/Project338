#pragma once
#include <vector>
#include "Student.h"

class StudentBase
{
public:
	size_t GetStudentsNumber() const;
	void AddStudent(int id, std::string name, std::string surname, Date birthDate, Gender gender, std::string pesel, std::string nationality);
	void DeleteStudent(int id);
private:
	std::vector<Student> m_students;
};