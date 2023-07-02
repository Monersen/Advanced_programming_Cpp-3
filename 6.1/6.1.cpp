#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

template<typename A, typename B>
pair<B, A> flip_pair(const pair<A, B>& p)
{
	return pair<B, A>(p.second, p.first);
}

template<typename A, typename B>
multimap<B, A> flip_map(const map<A, B>& src)
{
	multimap<B, A> dst;
	transform(src.rbegin(), src.rend(), inserter(dst, dst.begin()),
		flip_pair<A, B>);
	return dst;
}

int main()
{
	const char* str = "Hello world!!";
	map<char, int> frequency;

	for (int i = 0; i < strlen(str); i++)
	{
		const char value = str[i];
		int count = 0;
		for (int j = 0; j < strlen(str); j++)
		{
			if (value == str[j])
			{
				count += 1;
			}
		}
		frequency[value] = count;
	}
	multimap<int, char> dst = flip_map(frequency);
	for (multimap<int, char>::reverse_iterator itr = dst.rbegin(); itr != dst.rend(); itr++)
	{
		cout << itr->first << ": " << itr->second << endl;
	}
}