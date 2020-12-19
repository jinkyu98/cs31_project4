#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

int main()
{
	string a[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(appendToAll(a, -1, " * **") == -1);
	assert(appendToAll(a, 3, "") == 3 && a[2] == "mike");
	assert(appendToAll(a, 5, " * **") == 5 && a[2] == "mike * **");
	string a1[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(appendToAll(a1, 2, " * **") == 2 && a1[1] == "joe * **");
	string b[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(lookup(b, -1, "joe") == -1);
	assert(lookup(b, 0, "joe") == -1);
	assert(lookup(b, 4, "joe") == 1);
	assert(lookup(b, 4, "Joe") == -1);
	assert(lookup(b, 1, "lindsey") == -1);
	assert(lookup(b, 1, "") == -1);
	string c[6] = { "jamie", "lindsey", "mark", "susan", "joe", "donald" };
	assert(positionOfMax(c, -1) == -1);
	assert(positionOfMax(c, 2) == 1);
	assert(positionOfMax(c, 6) == 3);

	string d1[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(rotateLeft(d1, -1, 5) == -1);
	string d2[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(rotateLeft(d2, 1, -5) == -1);
	string d3[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(rotateLeft(d3, 0, 0) == -1);
	string d4[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(rotateLeft(d4, 3, 5) == -1);
	string d5[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
	assert(rotateLeft(d5, 5, 1) == 1 && d5[1] == "mike" && d5[4] == "joe");

	string e[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
	assert(countRuns(e, -1));
	assert(countRuns(e, 9) == 5);
	assert(countRuns(e, 7) == 4);
	string e1[10] = { "susan", "donald", "mike", "mike", "joe", "", "joe", "joe", "mike", "mike"};
	assert(countRuns(e1, 7) == 6);

	string f[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
	assert(flip(f, -1) == -1);
	assert(flip(f, 4) == 4 && f[0] == "susan" && f[4] == "sara");
	assert(flip(f, 5) == 5 && f[0] == "sara" && f[5] == "jamie");

	string folks[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
	string group[5] = { "donald", "mike", "jamie", "", "susan" };
	assert(differ(folks, 6, group, 5) == 2);
	assert(differ(folks, 2, group, 1) == 1);
	assert(differ(folks, 3, group, -1) == -1);
	assert(differ(folks, -1, group, -1) == -1);
	assert(differ(folks, -1, group, 4) == -1);

	string names[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey", "kamala", "mark" };
	string names1[10] = { "kamala", "mark" };
	string names2[10] = { "mark", "sara" };
	string names4[3] = { "" };
	assert(subsequence(names, 8, names4, 1) == -1);
	assert(subsequence(names, 8, names1, 2) == 0);
	assert(subsequence(names, 8, names2, 2) == 1);
	assert(subsequence(names, 8, names2, 2) == 1);
	assert(subsequence(names, -1, names2, -2) == -1);
	assert(subsequence(names, 4, names2, -2) == -1);
	assert(subsequence(names, -2, names2, 3) == -1);
	string names3[10] = { "kamala", "martha" };
	assert(subsequence(names, 5, names3, 2) == -1);

	string namesk[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey" };
	string set1[10] = { "jamie", "donald", "martha", "mark" };
	assert(lookupAny(namesk, 6, set1, 0) == -1);
	assert(lookupAny(namesk, -6, set1, 4) == -1);
	assert(lookupAny(namesk, 6, set1, -4) == -1);
	assert(lookupAny(namesk, 6, set1, 4) == 1);
	string set[10] = { "jordan", "sara", "clair", "lindsey", "kamala" };
	assert(lookupAny(namesk, 6, set, 5) == 0);
	string set2[10] = { "susan", "joe" };
	assert(lookupAny(namesk, 6, set2, 2) == -1);

	string candidate[6] = { "jamie", "lindsey", "mark", "susan", "joe", "donald" };
	assert(divide(candidate, -3, "joe") == -1);
	assert(divide(candidate, 6, "zung") == 6);
	assert(divide(candidate, 6, "kamala") == 3 && candidate[3] == "lindsey");
	string candidate2[4] = { "mark", "sara", "lindsey", "mike" };
	assert(divide(candidate2, 4, "mike") == 2);

	
}

int appendToAll(string a[], int n, string value)
{
	// negative array size
	if (n < 0)
		return -1;

	// from position 0 to n-1, value will be added to each element
	for (int k = 0; k < n; k++)
	{
		a[k] += value;
	}
	return n;
}
int lookup(const string a[], int n, string target)
{
	// negative array size
	if (n < 0)
		return -1;

	// from position 0 to n-1, find an element that matches target.
	// If found, the loop will break and the position value will be returned.
	// If not found, this function will return -1
	for (int k = 0; k < n; k++)
	{
		if (a[k] == target)
		{
			return k;
		}
	}
	
	return -1;
}
int positionOfMax(const string a[], int n)
{
	// negative array size and 0 element
	if (n <= 0)
		return -1;

	string tester = a[n-1];
	int position = 0;
	
	// this loop starts from backward so that it will return the smallest position if there are multiple identical elements
	for (int k = n - 1; k >= 0; k--)
	{
		if (a[k] >= tester)
		{
			tester = a[k];
			position = k;
		}
	}
	return position;
	
}
int rotateLeft(string a[], int n, int pos)
{
	// negative array size or an attempt to access a position greater than the size of an array
	if (n < 0 || pos < 0 || pos > n - 1)
		return -1;
	
	// 0 size should do nothing to the array but return 0
	if (n == 0)
		return 0;

	// store an element at position pos 
	string storageForPos = a[pos];

	// starting from position pos, move an element to the left
	for (int k = pos; k < n - 1; k++)
	{
		a[k] = a[k + 1];
	}
	
	// move an element at position to the end
	a[n - 1] = storageForPos;

	return pos;
}
int countRuns(const string a[], int n)
{
	// negative array size
	if (n < 0)
		return -1;

	int sequence = 1;
	string firstElement = a[0];

	// if an element at position k is not equal to that at position k+1, the sequence will be increased by 1.
	for (int k = 0; k < n; k++)
	{
		if (a[k] != firstElement)
		{
			firstElement = a[k];
			sequence++;
		}
	}

	return sequence;
}
int flip(string a[], int n)
{
	// negative array size
	if (n < 0)
		return -1;

	string temporaryStroage;

	// this loop repeats n-1 times
	for (int k = 0; k < n; k++)
	{
		// this loop switches element at position 0 with that at position 1, position 1 with position 2, and keeps going until n-2 and n-1 are swithced.
		// The number of times this loop repeats will decrease by 1 everytime so that last element remains unswitched.
		for (int j = 0; j + k < n - 1; j++)
		{
			temporaryStroage = a[j];
			a[j] = a[j+1];
			a[j + 1] = temporaryStroage;
		}
	}
	return n;
}
int differ(const string a1[], int n1, const string a2[], int n2)
{
	// negative array size
	if (n1 < 0 || n2 < 0)
		return -1;

	int nTimes, equalPos = 0;

	// This determines the number of times a loop will run
	if (n1 > n2)
		nTimes = n2;
	else if (n1 < n2)
		nTimes = n1;
	else
		nTimes = n1;

	// If elements at the same position are the same, equalPos will be increased by 1.
	for (int k = 0; k < nTimes; k++)
	{
		if (a1[k] == a2[k])
			equalPos++;
	}

	return equalPos;
}
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	// negative array size
	if (n1 < 0 || n2 < 0)
		return -1;



	int startingPos, exist = 0;
	for (int k = 0; k < n1; k++)
	{
		int count = 0;

		// a2 always starts from position 0, while the starting position of a1 will be increased by 1 for each loop.
		// This loop tests if there is a matching seqeunce of a2 in a1.
		for (int j = 0; j < n2; j++)
		{
			if (a1[k+j] == a2[j])
				count++;
		}
		
		// count indicates the number of matching element. If count is equal to n2, then a1 has a sequence that matches a2.
		if (count == n2)
		{ 
			startingPos = k;
			exist++;
			break;
		}
	}

	if (exist > 0)
		return startingPos;
	else
		return -1;
}
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	// negative array size
	if (n1 < 0 || n2 < 0)
		return -1;

	// if an element at position k matches any element in a2, this function will return a position of an element of a1, which also exists in a2.
	for (int k = 0; k < n1; k++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[k] == a2[j])
			{
				return k;
			}
		}
	}

	// if there is no matching element, this function will return -1.
	return -1;
}
int divide(string a[], int n, string divider)
{
	// negaitve array size
	if (n < 0)
		return -1;

	string temporaryStroage;
	// first align the elements in an increasing order
	for (int k = 0; k < n; k++)
	{
		// for every loop, the last element is excluded from comparing since its value is the greatest
		for (int j = 0; j < n - 1 - k; j++)
		{
			if (a[j] > a[j+1])
			{ 
				temporaryStroage = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temporaryStroage;
			}
		}
	}

	// now the sequence is in an increasing order, and this fill find a position of the first element that is greater or equal to divider.
	for (int k = 0; k < n; k++)
	{
			if (a[k] >= divider)
				return k;
	}

		return n;
}