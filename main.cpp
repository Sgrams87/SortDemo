#include <iostream>
#include <algorithm>
#include "sort.h"

using namespace std;
using namespace sorting;

int main()
{
	cout << "SORT DEMO\n\n";

	// start with sorting intevers
	vector<int> numbers {5, 12, 53, 33, 27};

	cout << "Original numbers: ";
	displayVector(numbers); // type independent

	//sort default
	sort(numbers.begin(), numbers.end());
	cout << "Sorted ASC: ";
	displayVector(numbers);

	//custom sorting behavior
	sort(numbers.begin(), numbers.end(), sortDescending);
	cout << "Sorted DESC: ";
	displayVector(numbers);

	//next sorting string
	vector<string> words {"apple", "pineapple", "kiwi", "banana", "pear", "grape", "apricot"};

	cout << "Original Words: ";
	displayVector(words);

	// default sort ASC 
	sort(words.begin(), words.end());
	cout << "Sorted Alphabetical: ";
	displayVector(words);

	// sort words by length using functor
	sort(words.begin(), words.end(), SortByLength());
	cout << "Sorted by length: ";
	displayVector(words);

	// sort DESC with lambda
	sort(words.begin(), words.end(),
		[](const string& a, const string& b){
			return a > b; // larger string alphabetically comes first
		}
	);
	cout << "DESC Sorted: ";
	displayVector(words);

	//vector of pairs 
	vector<pair<string, double>> fruits {
		{"apple", 1.29},
		{"banana", .99},
		{"pear", 1.49},
		{"pear", .99},
		{"kiwi", 2.00}
	};

	cout << "Original Fruit Pairs: ";
	for (auto& f : fruits){
		cout << "(" << f.first << ", " << f.second << ") ";
	}

	// sort by second value
	sort(fruits.begin(), fruits.end(),
		[](auto& a, auto& b){
			return a.second < b.second;
		}
	);

	cout << "\nSorted by second value: ";
	for (auto& f : fruits){
                 cout << "(" << f.first << ", " << f.second << ") ";
         }

	

	return 0;
}

