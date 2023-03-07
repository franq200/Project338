#pragma once
#include <string>
#include "Date.h"

enum class Gender : std::uint8_t
{
	male = 0,
	female
};

class Student
{
public:
	Student(int id, std::string name, std::string surname, Date birthDate, Gender gender, std::string pesel, std::string nationality);
	Student() = default;
	int GetId() const;
	const std::string& GetPesel() const;
	bool operator==(const Student& student) const;
private:
	int m_id = 0;
	std::string m_name;
	std::string m_surname;
	Date m_birthDate;
	Gender m_gender;
	std::string m_pesel;
	std::string m_nationality;
};

