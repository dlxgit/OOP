#include <iostream>
#include <memory>
#include <vector>

#include "CPupil.h"
#include "CPersonImpl.h"
#include "IPupil.h"

#include "CTeacher.h"
#include "CAdvancedStudent.h"
#include "CStudent.h"
#include "IStudent.h"
#include "IAdvancedStudent.h"
#include "CStudentImpl.h"
#include "CWorker.h"


int main()
{
 	std::vector<std::unique_ptr<IPerson>> people;
	CStudent st("andrey", "vasiliev", "anatolyevich", "yo", "VOLGATECH", 123);
	people.push_back(std::make_unique<CStudent>("andrey", "vasiliev", "anatolyevich", "yo", "VOLGATECH", 123));
	people.push_back(std::make_unique<CAdvancedStudent>("andrey", "vasiliev", "anatolyevich", "yo", "VOLGATECH", 123, "programmirovanie_igr_na_assemblere"));
	people.push_back(std::make_unique<CTeacher>("andrey", "vasiliev", "anatolyevich", "yo", "Zaboro-Stroenie"));
	people.push_back(std::make_unique<CPupil>("andrey", "vasiliev", "anatolyevich", "yo", "gimnaziya_4", "1B"));
	people.push_back(std::make_unique<CWorker>("andrey", "vasiliev", "anatolyevich", "yo", "president"));
 	//people.push_back(std::make_unique<CAdvancedStudent>());
	//CAdvancedStudent student;
	return 0;
}