#include <iostream>
#include <algorithm>
#include <iterator>
//#include <functional>
#include <vector>
#include <numeric>
using namespace std;

template < class T > void
print(T start, T end)
{
	for (; start != end; ++start)
	{
		std::cout << *start << " ";
	}
	cout << " \n";
}
bool equal(int fvalue, int svalue)
{
	return fvalue == svalue;
}
bool smaller(int fvalue, int svalue)
{
	return fvalue < svalue;
}
bool bigger(int fvalue, int svalue)
{
	return fvalue > svalue;
}

int main()
{
	vector<double> student1Grades = { 3, 4, 5, 4, 12, 5, 11, 4 };
	vector<double> student2Grades = { 5, 9, 5, 8,  3, 3, 10, 5 };
	
	
	vector<bool>equalvalue(student1Grades.size());
	vector<bool>smallvalue(student1Grades.size());
	vector<bool>biggervalue(student1Grades.size());
	bool(*ptr_equal)(int, int) = &equal;
	bool(*ptr_smaller)(int, int) = &smaller;
	bool(*ptr_bigger)(int, int) = &bigger;
	//ваш код
	
	cout << "Smaller than second vector\n";
	transform(student1Grades.begin(), student1Grades.end(), student2Grades.begin(), smallvalue.begin(), ptr_smaller);
	print(smallvalue.begin(), smallvalue.end());

	cout << "Equal to second vector\n";
	transform(student1Grades.begin(), student1Grades.end(), student2Grades.begin(), equalvalue.begin(), ptr_equal);
	print(equalvalue.begin(), equalvalue.end());
	
	cout << "Biger than second vector\n";
	transform(student1Grades.begin(), student1Grades.end(), student2Grades.begin(), biggervalue.begin(), ptr_bigger);
	print(biggervalue.begin(), biggervalue.end());
	return 0;
}


/*
Приклад відповіді:
1 1 0 1 0 0 0 1
0 0 1 0 0 0 0 0
0 0 0 0 1 1 1 0
*/