#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <string>


using namespace std;

vector<double> ReadNumbers();

vector<double> ComputeMultipiedVector(const vector<double> & numbers); //multiply all elements of vector by the minimal element

void SortVector(vector<double> & numbers);

void PrintVector(const vector<double> & resultVector);