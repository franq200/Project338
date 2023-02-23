#include <gtest/gtest.h>
#include "../Project2137/StudentBase.h"
#include "../Project2137/Date.h"
#include <chrono>

TEST(StudentBaseTest, GivenStudentBase_WhenGetStudentsNumberIsCalled_ThenItShouldReturn0) {
	StudentBase studentBase;
	EXPECT_EQ(studentBase.GetStudentsNumber(), 0);
}

TEST(StudentBaseTest, GivenStudentBase_WhenAddStudentAndGetStudentsNumberIsCalled_ThenItShouldReturn1) {
	StudentBase studentBase;
	Date birthDate = { std::chrono::year(1998), std::chrono::month(12), std::chrono::day(31) };
	EXPECT_NO_THROW(studentBase.AddStudent(10, "Kacper", "Bak", birthDate, Gender::male, "10986432", "poland"));
	EXPECT_EQ(studentBase.GetStudentsNumber(), 1);
}

TEST(StudentBaseTest, GivenStudentBase_WhenAddStudentWithExistingId_ThenItShouldThrowException) {
	StudentBase studentBase;
	Date birthDate1 = { std::chrono::year(1998), std::chrono::month(12), std::chrono::day(31) };
	studentBase.AddStudent(10, "Kacper", "Bak", birthDate1, Gender::male, "10986432", "poland");
	Date birthDate2 = { std::chrono::year(1293), std::chrono::month(10), std::chrono::day(23) };
	EXPECT_THROW(studentBase.AddStudent(10, "Kacper", "Bak", birthDate2, Gender::male, "54345234", "poland"), std::exception);
}

TEST(StudentBaseTest, GivenStudentBase_WhenAddStudentIsCalledTwiceAndDeleteStuentAtFirstStudentAndGetStudentsNumberIsCalled_ThenItShouldReturn1) {
	StudentBase studentBase;
	Date birthDate1 = { std::chrono::year(1998), std::chrono::month(12), std::chrono::day(31) };
	studentBase.AddStudent(10, "Kacper", "Bak", birthDate1, Gender::male, "10986432", "poland");
	Date birthDate2 = { std::chrono::year(1293), std::chrono::month(10), std::chrono::day(23) };
	studentBase.AddStudent(12, "Kacper", "Bak", birthDate2, Gender::male, "54345234", "poland");
	studentBase.DeleteStudent(10);
	EXPECT_EQ(studentBase.GetStudentsNumber(), 1);
}

TEST(StudentBaseTest, GivenStudentBase_WhenDeleteStuentWithWrongId_ThenItShouldThrowException) {
	StudentBase studentBase;
	Date birthDate1 = { std::chrono::year(1998), std::chrono::month(12), std::chrono::day(31) };
	studentBase.AddStudent(10, "Kacper", "Bak", birthDate1, Gender::male, "10986432", "poland");
	Date birthDate2 = { std::chrono::year(1293), std::chrono::month(10), std::chrono::day(23) };
	studentBase.AddStudent(12, "Kacper", "Bak", birthDate2, Gender::male, "54345234", "poland");
	EXPECT_ANY_THROW(studentBase.DeleteStudent(11));
}