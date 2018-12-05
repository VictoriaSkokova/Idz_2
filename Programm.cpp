//Тема 6.Нет симметричных единиц.
//Последовательности из четного числа 0 и 1 разделяются звездочкой ровно пополам.В этих последовательностях нет двух 1, стоящих на одинаковых расстояниях от звездочки.
//Примеры: 0 * 1, 0110 * 0001, 1010000 * 0101000.

//Грамматика:
//<exp> -> * | 0<exp>1 | 1<exp>0 | 0<exp>1 

//или 
//
//1) < exp > :: = *;
//2) < exp > :: = 0 < exp > 1;
//3) < exp > :: = 1 < exp > 0;
//4) < exp > :: = 0 < exp > 0;
//
//
//Программа проверки


#include <string>
#include <iostream>
#include <exception>


using namespace std;


void error() {
	throw exception();
}

string NewSequence(string oldsequence)
{
	string newsequence;
	int i = 1;
	while (i < oldsequence.length() - 1)
	{
		newsequence += oldsequence[i];
		i++;
	}
	return newsequence;
}


bool Check (string &sequence)
{
	switch (sequence[0])
	{
	case '1':
	{
		string newsequence = NewSequence(sequence);
		if (sequence[sequence.length() - 1] != '0')
			return false;
		if (Check(newsequence) == false)
			return false;
		break;
	}
	case '0':
	{
		string newsequence = NewSequence(sequence);
		if ((sequence[sequence.length() - 1] != '0') & (sequence[sequence.length() - 1] != '1'))
			return false;
		if (Check(newsequence) == false)
			return false;
		break;
	}
	case '*':
	{if (sequence[sequence.length() - 1] != '*')
		return false;
	break;
	}
	default:
	{
		return false;
	}
	}
	return true;
}



int main()
{
	string sequence;
	cout << "Enter your sequence \n";
	cin >> sequence;
	try 
	{
		if ((sequence.length() - 1) % 2 == 1)
			error();
		if (Check(sequence) == false)
			error();
		cout << "The sequence is based on grammar \n";
	}
	catch (exception)
	{
		cout << "The sequence is not grammar based \n";
	}
	system ("pause");
	return 0;
}


