#include <gtest/gtest.h>
#include "../Project2137/StudentBase.h"
#include "../Project2137/Student.h"
#include "../Project2137/Date.h"
#include <chrono>

const int firstStudentId = 10;
const int secondStudentId = 12;
const std::string firstStudentPesel = "10986432";
const Date birthDate = { std::chrono::year(1998), std::chrono::month(12), std::chrono::day(31) };
const Date birthDate2 = { std::chrono::year(1293), std::chrono::month(10), std::chrono::day(23) };

void AddFirstStudent(StudentBase& studentBase)
{
	studentBase.AddStudent(firstStudentId, "Kacper", "Bak", birthDate, Gender::male, firstStudentPesel, "poland");
}

void AddSecondStudent(StudentBase& studentBase)
{
	studentBase.AddStudent(secondStudentId, "Kacper", "Bak", birthDate2, Gender::male, "54345234", "poland");
}

struct StudentBaseTest : public ::testing::Test
{
	void AddTwoStudents()
	{
		AddFirstStudent(studentBase);
		AddSecondStudent(studentBase);
	}

	StudentBase studentBase;
};

struct StudentBaseWithTwoStudentsTests : public StudentBaseTest
{
	StudentBaseWithTwoStudentsTests()
	{
		AddTwoStudents();
	}
};

TEST_F(StudentBaseTest, GivenStudentBase_WhenGetStudentsNumberIsCalled_ThenItShouldReturn0) {
	EXPECT_EQ(studentBase.GetStudentsNumber(), 0);
}

TEST_F(StudentBaseTest, GivenStudentBase_WhenAddStudentAndGetStudentsNumberIsCalled_ThenItShouldReturn1) {
	EXPECT_NO_THROW(AddFirstStudent(studentBase));
	EXPECT_EQ(studentBase.GetStudentsNumber(), 1);
}

TEST_F(StudentBaseTest, GivenStudentBase_WhenAddStudentWithExistingId_ThenItShouldThrowException) {
	AddFirstStudent(studentBase);
	EXPECT_THROW(AddFirstStudent(studentBase), std::exception);
}

TEST_F(StudentBaseWithTwoStudentsTests, GivenStudentBase_WhenAddStudentIsCalledTwiceAndDeleteStuentAtFirstStudentAndGetStudentsNumberIsCalled_ThenItShouldReturn1) {
	studentBase.DeleteStudent(firstStudentId);
	EXPECT_EQ(studentBase.GetStudentsNumber(), 1);
}

TEST_F(StudentBaseWithTwoStudentsTests, GivenStudentBase_WhenDeleteStuentWithWrongId_ThenItShouldThrowException) {
	const int wrongId = 11;
	EXPECT_ANY_THROW(studentBase.DeleteStudent(wrongId));
}

// Stworzyæ test parametryzowany dla funkcji search student (jako input przekazujesz pesel, jako output - konkretnego znalezionego studenta

struct TestSearchStudent
{
	std::string pesel;
	int id;
};

struct StudentSearchPeselTests : public ::testing::TestWithParam<TestSearchStudent>
{

};

TEST_P(StudentSearchPeselTests, Given_StudentBaseWithTwoStudents_WhenSearchStudentIsCalled_ThenReturnStudentWithCorrectId)
{
	const TestSearchStudent& parameters = GetParam();
	StudentBase studentBase;
	AddFirstStudent(studentBase);
	EXPECT_EQ(parameters.id, studentBase.SearchStudent(parameters.pesel).GetId());
}


INSTANTIATE_TEST_CASE_P(Given_StudentBaseWithTwoStudents_WhenSearchStudentIsCalled_ThenReturnStudentWithCorrectId, StudentSearchPeselTests, ::testing::Values(
	TestSearchStudent{ firstStudentPesel, firstStudentId }
));

struct StudentSearchWithWrongPesel : public ::testing::TestWithParam<TestSearchStudent>
{

};

TEST_P(StudentSearchWithWrongPesel, MyTestName)
{
	const TestSearchStudent& parameters = GetParam();
	StudentBase studentBase;
	AddFirstStudent(studentBase);
	EXPECT_THROW(studentBase.SearchStudent(parameters.pesel), std::exception);
}

INSTANTIATE_TEST_CASE_P(MyTestName, StudentSearchWithWrongPesel, ::testing::Values(
	TestSearchStudent{"5432626532"}
));
