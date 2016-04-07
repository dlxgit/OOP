#include "stdafx.h"
#include "calculator.h"


using namespace std;

//print id - а если такой id есть и у функции и у переменной

bool IsOperationSymbol(const string & str)
{
	if (OPERATION_SYMBOLS.find(str) != OPERATION_SYMBOLS.end())
	{
		return true;
	}
	return false;
}


double Calculator::ComputeFuncValue(const string & funcName)
{
	double funcValue;
	map<string, vector<string>>::iterator it = funcMap.find(funcName);
	if (it->second.size() == 1)
	{
		map<string, double>::iterator itResult = varMap.find(it->second[0]);
		funcValue = itResult->second;
	}
	else
	{
		map<string, double>::iterator itLeftOperand = varMap.find(it->second[0]);
		map<string, double>::iterator itRightOperand = varMap.find(it->second[0]);
		if (it->second[1] == "+")
		{
			funcValue = itLeftOperand->second + itRightOperand->second;
		}
		else if (it->second[1] == "-")
		{
			funcValue = itLeftOperand->second - itRightOperand->second;
		}
		else if (it->second[1] == "*")
		{
			funcValue = itLeftOperand->second * itRightOperand->second;
		}
		else if (it->second[1] == "/")
		{
			funcValue = itLeftOperand->second / itRightOperand->second;
		}
	}
	return funcValue;
}

void Calculator::Var()
{
	varMap.insert(std::pair<string, double>(operationParts[1], NAN));
}

void Calculator::Let(const bool & isNumber)
{
	std::map<string, double>::iterator it = varMap.find(operationParts[1]);

// 	if (!isNumber && it == varMap.end())
// 	{
// 		cout << "err(Let it == varMap.end())" << endl;
// 	}

	if (isNumber)
	{
		double numValue = stod(operationParts[3]);

		std::map<string, double>::iterator it = varMap.find(operationParts[1]);
		if (it != varMap.end())
		{
			it->second = numValue;
		}
		else
		{
			varMap.insert(std::pair<string, double>(operationParts[1], numValue));
		}
	}
	else
	{
		std::map<string, double>::iterator newValueIterator = varMap.find(operationParts[3]);
		if (newValueIterator != varMap.end())
		{
			if (it == varMap.end())
			{
				varMap.insert(std::pair<string, double>(operationParts[1], newValueIterator->second));
				//cout << "err(Let it == varMap.end())" << endl;
			}
			else it->second = newValueIterator->second;
		}
		else
		{
			//err: second variable is is not assigned
		}
	}
}

void Calculator::Fn()
{
	//doesnow: add in map, not check if its in it
	map<string, vector<string>>::iterator it = funcMap.find(operationParts[0]);
	if (it == funcMap.end())
	{
		vector<string> functionParts; //create vec of function relations
		for (size_t i = 3; i < operationParts.size(); i++)
		{
			functionParts.push_back(operationParts[i]); //fill vec
		}
		funcMap.insert(std::pair<string, vector<string>>(operationParts[1], functionParts)); //add new funcMap element
	}
	else
	{

	}


	//1 необьявлен обяз, 2и3 - обьявлены.
	//TODO: что если будут не в том порядке, или будет чего-то нехватать
}

void Calculator::Print()
{
	//TODO: what if id is in both??
	map<string, double>::iterator itVar = varMap.find(operationParts[1]);
	if (itVar != varMap.end())
	{	
		cout << std::fixed << std::setprecision(2) << itVar->second << endl;
	}
	else
	{
		map<string, vector<string>>::iterator itFunc = funcMap.find(operationParts[1]);
		if (itFunc != funcMap.end())
		{
			cout << std::fixed << std::setprecision(2) << ComputeFuncValue(itFunc->first) << endl;
		}
		else
		{
			//notFoundCase
		}
	}
}

void Calculator::PrintVars()
{
	for (map<string, double>::iterator it = varMap.begin(); it != varMap.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
}

void Calculator::PrintFns()
{
	for (map<string, vector<string>>::iterator it = funcMap.begin(); it != funcMap.end(); it++)
	{
		std::cout << it->first << " : " << std::fixed << std::setprecision(2) << ComputeFuncValue(it->first) << std::endl;
	}
}

bool Calculator::IsCommandCorrect()
{
	switch (operationParts.size())
	{
	case 0:
		//isError = true;   ???
		break;
	case 1:
		//printvars
		//printfns
		if (operationParts[0] == "printvars" || "printfns")
		{
			return true;
		}
		break;
	case 2:
		//var
		//print		
		if ((operationParts[0] == "var") && varMap.count(operationParts[1]) == 0)
		{
			return true;
		}
		if ((operationParts[0] == "print") && varMap.count(operationParts[1]) == 1)
		{
			return true;
		}
		if ((operationParts[0] == "print") && funcMap.count(operationParts[1]) == 1)
		{
			return true;
		}
		break;
	case 4:
		//let
		//fn
		if (operationParts[0] == "let" && operationParts[2] == "=" && (IsNumber(operationParts[3]) || (varMap.count(operationParts[3]) == 1 && !IsNumber(operationParts[3]))))    //not justt varMap? "В качестве <идентификатора1>не может выступать имя функции."   (проверять count из обоих мап?  --> доп условия?)
		{
			return true;
		}
		if ((operationParts[0] == "fn" && varMap.count(operationParts[1]) == 0 && operationParts[2] == "=" && varMap.count(operationParts[3]) == 1))
		{
			return true;
		}
		break;
	case 6:
		//fn
		if ((operationParts[0] == "fn" && varMap.count(operationParts[1]) == 0 && operationParts[2] == "=" && varMap.count(operationParts[3]) == 1 && IsOperationSymbol(operationParts[4]) && varMap.count(operationParts[5]) == 1))
		{
			return true;
		}
		break;
	default:
		break;
	} 
	return false;
}

void Calculator::ReadCommand(const string & line)
{
	std::istringstream ist(line);
	string word;

	operationParts.clear();

	bool isErr = false;

	while (ist >> word)
	{
		isErr = false;
		size_t operandVecSize = operationParts.size();

		operationParts.push_back(word);
		/*
		if (operandVecSize == 0)
		{
			if (word == "var" || word == "let" || word == "fn" || word == "print" || word == "printvars" || word == "printfns")
			{
				operationParts.push_back(word);
			}
			else
			{
				isErr = true;
			}
		}
		else
		{

			if (operationParts[0] == "var")
			{
				if (operandVecSize > 2 || IsNumber(word))
				{
					cout << "err" << endl;
				}
				if (varMap.count(operationParts[1]) != 0)
				{
					cout << "err" << endl;
				}
			}
			else if (operationParts[0] == "let")
			{
				if (operandVecSize > 3 || (!IsNumber(word) && varMap.count(word) == 0))
				{
					cout << "err" << endl;
				}
			}
			else if (operationParts[0] == "fn")
			{
				if (operandVecSize > 3 || funcMap.count(word) != 0)
				{

				}
				if (operationParts.size() == 3)
				{

				}
				else if (operationParts.size() == 5)
				{
					if (varMap.count(operationParts[2]) == 0 || varMap.count(operationParts[4]) == 0) //МОЖЕТ ЛИ БЫТЬ ID2 и ID3 ФУНКЦИЕЙ? ИЛИ ТОЛЬКО ПЕРЕМЕННОЙ
					{

					}
					if (!(operationParts[3] != "+" && operationParts[3] != "-" && operationParts[3] != "*" && operationParts[3] != "/"))
					{

					}
				}
			}
			else if (operationParts[0] == "print")
			{
				if (operandVecSize > )
				{

				}
			}
			else if (operationParts[0] == "printvars")
			{
				if (operandVecSize > )
				{

				}
			}
			else if (operationParts[0] == "printfns")
			{
				if (operandVecSize > )
				{
				}
			}

		}
		*/
	}
};

void Calculator::ProcessCommand()
{
	if (operationParts[0] == "var")
	{
		Var();
		return;
	}
	if (operationParts[0] == "let")
	{
		Let(IsNumber(operationParts[3]));
		return;
	}
	if (operationParts[0] == "fn")
	{
		Fn();
		return;
	}
	if (operationParts[0] == "print")
	{
		Print();
		return;
	}
	if (operationParts[0] == "printvars")
	{
		PrintVars();
		return;
	}
	if (operationParts[0] == "printfns")
	{
		PrintFns();
		return;
	}
}


bool Calculator::IsNumber(const std::string & str)
{
	if (str.size() == 0 || str[0] == '.' || str[str.size() - 1] == '.')  //if string is empty or it has '.' on first/last position 
	{
		return false;
	}
	if (!(str[0] < 58 && str[0] > 47) && str[0] != '-') //if first element is not correct (not between 0 and 9)
	{
		return false;
	}

	bool isPointAlready = false;  // flag if we already met '.' (to check if we meet it once again)

	for (size_t i = 1; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			if (true == isPointAlready)
			{
				return false;
			}
			isPointAlready = true;
		}
		else if (str[i] > 57 || str[i] < 48)
		{
			std::cout << "number <" << str << "> is not correct" << std::endl;
			return false;
		}
	}
	return true;
}