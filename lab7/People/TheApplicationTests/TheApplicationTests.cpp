#include <iostream>
#include <memory>
#include <vector>
#include "../People/CPupil.h"
#include "../People/CTeacher.h"
#include "../People/CAdvancedStudent.h"
#include "../People/CStudent.h"
#include "../People/CWorker.h"
#include "stdafx.h"

const std::vector<std::string> personInfo = { "andrey", "vasiliev", "anatolyevich", "yo" };

BOOST_AUTO_TEST_SUITE(Testing_classes)
	BOOST_AUTO_TEST_SUITE(CPupil_)
		BOOST_AUTO_TEST_CASE(initializes_correctly)
		{
			CPupil pupil(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "someSchool", "someClass");
			BOOST_CHECK_EQUAL(pupil.GetName(), personInfo[0]);
			BOOST_CHECK_EQUAL(pupil.GetSurName(), personInfo[1]);
			BOOST_CHECK_EQUAL(pupil.GetFatherName(), personInfo[2]);
			BOOST_CHECK_EQUAL(pupil.GetAddress(), personInfo[3]);
			BOOST_CHECK_EQUAL(pupil.GetSchool(), "someSchool");
			BOOST_CHECK_EQUAL(pupil.GetClass(), "someClass");
		}
		BOOST_AUTO_TEST_CASE(does_not_cause_memory_leaks)
		{
			std::unique_ptr<IPerson> person = std::make_unique<CPupil>(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "someSchool", "someClass");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(CStudent_)
		BOOST_AUTO_TEST_CASE(initializes_correctly)
		{
			CStudent student(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "volgatech", 122);
			BOOST_CHECK_EQUAL(student.GetName(), personInfo[0]);
			BOOST_CHECK_EQUAL(student.GetSurName(), personInfo[1]);
			BOOST_CHECK_EQUAL(student.GetFatherName(), personInfo[2]);
			BOOST_CHECK_EQUAL(student.GetAddress(), personInfo[3]);
			BOOST_CHECK_EQUAL(student.GetUniversity(), "volgatech");
			BOOST_CHECK_EQUAL(student.GetId(), 122);
		}
		BOOST_AUTO_TEST_CASE(does_not_cause_memory_leaks)
		{
			std::unique_ptr<IPerson> person = std::make_unique<CStudent>(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "volgatech", 122);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(CAdvancedStudent_)
		BOOST_AUTO_TEST_CASE(initializes_correctly)
		{
			CAdvancedStudent advancedStudent(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "volgatech", 122, "someTopic");
			BOOST_CHECK_EQUAL(advancedStudent.GetName(), personInfo[0]);
			BOOST_CHECK_EQUAL(advancedStudent.GetSurName(), personInfo[1]);
			BOOST_CHECK_EQUAL(advancedStudent.GetFatherName(), personInfo[2]);
			BOOST_CHECK_EQUAL(advancedStudent.GetAddress(), personInfo[3]);
			BOOST_CHECK_EQUAL(advancedStudent.GetUniversity(), "volgatech");
			BOOST_CHECK_EQUAL(advancedStudent.GetId(), 122);
			BOOST_CHECK_EQUAL(advancedStudent.GetDissertationTopic(), "someTopic");
		}
		BOOST_AUTO_TEST_CASE(does_not_cause_memory_leaks)
		{
			std::unique_ptr<IPerson> person = std::make_unique<CAdvancedStudent>(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "volgatech", 122, "someTopic");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(CTeacher_)
		BOOST_AUTO_TEST_CASE(initializes_correctly)
		{
			CTeacher teacher(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "someSubject");
			BOOST_CHECK_EQUAL(teacher.GetName(), personInfo[0]);
			BOOST_CHECK_EQUAL(teacher.GetSurName(), personInfo[1]);
			BOOST_CHECK_EQUAL(teacher.GetFatherName(), personInfo[2]);
			BOOST_CHECK_EQUAL(teacher.GetAddress(), personInfo[3]);
			BOOST_CHECK_EQUAL(teacher.GetSubject(), "someSubject");
		}
		BOOST_AUTO_TEST_CASE(does_not_cause_memory_leaks)
		{
			std::unique_ptr<IPerson> person = std::make_unique<CTeacher>(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "someSubject");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(CWorker_)
		BOOST_AUTO_TEST_CASE(initializes_correctly)
		{
			CWorker worker(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "someSpeciality");
			BOOST_CHECK_EQUAL(worker.GetName(), personInfo[0]);
			BOOST_CHECK_EQUAL(worker.GetSurName(), personInfo[1]);
			BOOST_CHECK_EQUAL(worker.GetFatherName(), personInfo[2]);
			BOOST_CHECK_EQUAL(worker.GetAddress(), personInfo[3]);
			BOOST_CHECK_EQUAL(worker.GetSpeciality(), "someSpeciality");
		}
		BOOST_AUTO_TEST_CASE(does_not_cause_memory_leaks)
		{
			std::unique_ptr<IPerson> person = std::make_unique<CWorker>(personInfo[0], personInfo[1], personInfo[2], personInfo[3], "someSpeciality");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()