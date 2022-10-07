// #include "tests.hpp"

// template <typename T>
// static void print_vector(T vec, std::string type)
// {
// 	typename T::iterator it;

// 	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
// 	it = vec.begin();
// 	while (it != vec.end())
// 	{
// 		std::cout << *it;
// 		if (it + 1 != vec.end())
// 			std::cout << " - ";
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

// template <typename T>
// static void print_vector_reverse(T vec, std::string type)
// {
// 	typename T::iterator it;

// 	std::cout << BOLD << type << ", size: " << vec.size() << ", empty: " << vec.empty() << ", capacity: " << vec.capacity() << RESET << std::endl;
// 	it = vec.rbegin();
// 	while (it != vec.rend())
// 	{
// 		std::cout << *it;
// 		if (it + 1 != vec.rend())
// 			std::cout << " - ";
// 		++it;
// 	}
// 	std::cout << std::endl;
// }

// static void default_constructor(void)
// {
// 	print_header("Default constructor");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	check("v1 == v2", v1 == v2);
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	check("v1 == v2", v1 == v2);
// }

// static void copy_constructor(void)
// {
// 	print_header("Copy");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	ft::vector<int> v3(v1);
// 	std::vector<int> v4(v2);
//     std::cout << "|\n";
// 	v1.push_back(42);
// 	v2.push_back(42);
// 	check("v1 == v2", (v1 == v2));
// 	check("v3 == v4", (v3 == v4));
// 	check("v1 != v3", (v1 != v3));
// 	check("v2 != v4", (v2 != v4));
// }

// static void max_size(void)
// {
// 	print_header("Max size");
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
// 	v1.push_back("test");
// 	v2.push_back("test");
// 	check("v1.max_size() == v2.max_size()", v1.max_size(), v2.max_size());
// }

// static void resize(void)
// {
// 	print_header("Resize");
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	v1.resize(10, "test");
// 	v2.resize(10, "test");
// 	check("v1 == v2", (v1 == v2));
// 	v1.resize(2, "42");
// 	v2.resize(2, "42");
// 	check("v1 == v2", (v1 == v2));
// }

// static void access_operator(void)
// {
// 	print_header("[] operator, at()");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	check("v1[0] == v2[0]", v1[0], v2[0]);
// 	check("v1[1] == v2[1]", v1[1], v2[1]);
// 	check("v1[2] == v2[2]", v1[2], v2[2]);
// 	try
// 	{
// 		std::cout << "v1.at(100): " << v1.at(100) << ": " << FAIL << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << ": " << std::string(7, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
// 	}
// 	try
// 	{
// 		std::cout << "v2.at(100): " << v2.at(100) << ": " << FAIL  << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << ": " << std::string(20, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
// 	}
// 	try
// 	{
// 		std::cout << "v1.at(-1): " << v1.at(-1) << ": " << FAIL  << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << ": " << std::string(8, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
// 	}
// 	try
// 	{
// 		std::cout << "v2.at(-1): " << v2.at(-1) << ": " << FAIL  << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << e.what() << ": " << std::string(21, ' ') << BOLD << GREEN << GOOD << RESET << std::endl;
// 	}
// }

// static void front_back(void)
// {
// 	print_header("Front / Back");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	check("v1.front() == v2.front()", v1.front(), v2.front());
// 	check("v1.back() == v2.back()", v1.front(), v2.front());
// }

// static void assign(void)
// {
// 	print_header("Assign");
// 	std::string test[] = {"Hey", "what's", "up", "?"};
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	v1.assign(test, test + 4);
// 	v2.assign(test, test + 4);
// 	check("v1 == v2", v1 == v2);
// 	v1.assign(10, "?");
// 	v2.assign(10, "?");
// 	check("v1 == v2", v1 == v2);
// }

// static void insert(void)
// {
// 	print_header("Insert");
// 	int test[] = {1, 2, 3};
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	v1.insert(v1.begin(), 42);
// 	v1.insert(v1.end(), 21);
// 	v1.insert(v1.begin(), 10);
// 	v1.insert(v1.begin() + 1, 11);
// 	v1.insert(v1.begin() + 2, (size_t)3, 0);
// 	v1.insert(v1.begin() + 1, test, test + 3);
// 	v2.insert(v2.begin(), 42);
// 	v2.insert(v2.end(), 21);
// 	v2.insert(v2.begin(), 10);
// 	v2.insert(v2.begin() + 1, 11);
// 	v2.insert(v2.begin() + 2, (size_t)3, 0);
// 	v2.insert(v2.begin() + 1, test, test + 3);
// 	check("v1 == v2", v1 == v2);
// }

// static void erase(void)
// {
// 	print_header("Erase / Clear");
// 	std::string test[] = {"Hey", "what's", "up", "?"};
// 	ft::vector<std::string> v1;
// 	std::vector<std::string> v2;
// 	v1.assign(test, test + 4);
// 	v2.assign(test, test + 4);
// 	v1.erase(v1.begin() + 2);
// 	v2.erase(v2.begin() + 2);
// 	check("v1 == v2", v1 == v2);
// 	v1.clear();
// 	v2.clear();
// 	check("v1 == v2", v1 == v2);
// }

// static void swap(void)
// {
// 	print_header("Swap");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	ft::vector<int> v3;
// 	std::vector<int> v4;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	v3.push_back(42);
// 	v3.push_back(43);
// 	v4.push_back(42);
// 	v4.push_back(43);
// 	v1.swap(v3);
// 	v2.swap(v4);
// 	check("v1 == v2", v1 == v2);
// 	check("v3 == v4", v3 == v4);
// }

// static void operators(void)
// {
// 	print_header("Operators");
// 	ft::vector<int> v1;
// 	std::vector<int> v2;
// 	ft::vector<int> v3;
// 	std::vector<int> v4;
// 	v1.push_back(1);
// 	v1.push_back(2);
// 	v1.push_back(3);
// 	v2.push_back(1);
// 	v2.push_back(2);
// 	v2.push_back(3);
// 	v3 = v1;
// 	v4 = v2;
// 	check("v1 == v2", (v1 == v3), (v2 == v4));
// 	check("v1 != v2", (v1 != v3), (v2 != v4));
// 	check("v1 > v2", (v1 > v3), (v2 > v4));
// 	check("v1 < v2", (v1 < v3), (v2 < v4));
// 	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
// 	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
// 	v1.push_back(42);
// 	v2.push_back(42);
// 	check("v1 == v2", (v1 == v3), (v2 == v4));
// 	check("v1 != v2", (v1 != v3), (v2 != v4));
// 	check("v1 > v2", (v1 > v3), (v2 > v4));
// 	check("v1 < v2", (v1 < v3), (v2 < v4));
// 	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
// 	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
// 	v3.push_back(43);
// 	v4.push_back(43);
// 	check("v1 == v2", (v1 == v3), (v2 == v4));
// 	check("v1 != v2", (v1 != v3), (v2 != v4));
// 	check("v1 > v2", (v1 > v3), (v2 > v4));
// 	check("v1 < v2", (v1 < v3), (v2 < v4));
// 	check("v1 >= v2", (v1 >= v3), (v2 >= v4));
// 	check("v1 <= v2", (v1 <= v3), (v2 <= v4));
// }

// int	main(void)
// {
// 	print_header("vector");

// 	default_constructor();
// 	copy_constructor();
// 	max_size();
// 	resize();
// 	access_operator();
// 	front_back();
// 	assign();
// 	insert();
// 	erase();
// 	swap();
// 	operators();
// }

#include "debug.hpp"
#include "map.hpp"

// int main (void)
// {
// 	ft::map<int, int> mapped;

// 	ft::node<int, int>	nnode(nullptr, nullptr, nullptr, ft::make_pair(15,2));

// 	for(int i = 0; i < 10; i++)
// 	{
// 		mapped.insert(ft::make_pair(i, i));
// 		nnode.content.first = i;
// 	}
// 	ft::debug_tree(mapped.getmom(), 20);

// 	ft::map<int,int>::iterator it = mapped.begin();
// 	while (it != mapped.end())
// 	{
// 		std::cout << "IT = "<<it->second << std::endl;
// 		++it;
// 	}
	
// 	for(int i = 0; i < 10; i++)
// 	{
// 		mapped.erase(i);
// 		std::cout << "\n------------------------------\n";
// 		ft::debug_tree(mapped.getmom(), 20);
// 	}
// 	mapped.erase(15);
// 	std::cout << "\n------------------------------\n";
// }

// bool fncomp (char lhs, char rhs) {return lhs<rhs;}

// struct classcomp {
//   bool operator() (const char& lhs, const char& rhs) const
//   {return lhs<rhs;}
// };

// int main ()
// {
//     ft::map<char,int> first;

//     first['a']=10;
//     first['b']=30;
//     first['c']=50;
//     first['d']=70;

//     ft::map<char,int> second (first.begin(),first.end());

//     ft::map<char,int> third (second);

//     ft::map<char,int,classcomp> fourth;                 // class as Compare

//     bool(*fn_pt)(char,char) = fncomp;
//     ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

//     return 0;
// }

#include <map>
#include <utility>
#include "tests.hpp"
#include "debug.hpp"

template <class T>
static void print_map(T &map)
{
	typename T::iterator it = map.begin();
	std::cout << " --- map of size " << map.size() << " ---" << std::endl;
	while (it != map.end())
	{
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}
	std::cout << " --- " << std::endl;
}

static void constructors(void)
{
	print_header("Constructors / Copy");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("(default) m1 == m2", (m1 == m2));
	ft::map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	check("(range) m3 == m4", (m3 == m4));
	ft::map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	check("(copy) m5 == m6", (m3 == m4));
	ft::map<int, int> m7;
	std::map<int, int> m8;
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	check("(copy) m7 == m8", (m7 == m8));
	ft::map<int, int> m9;
	std::map<int, int> m10;
	m9 = m7;
	m10 = m8;
	check("(copy) m9 == m10", (m9 == m10));
}

static void max_size(void)
{
	print_header("Size");
	ft::map<int, int> m1;
	std::map<int, int> m2;
	check("m1.max_size() == m2.max_size()", m1.max_size(), m2.max_size());
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	check("m3.max_size() == m4.max_size()", m3.max_size(), m4.max_size());
}

static void access_operator(void)
{
	print_header("[] operator");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m1["d"] = 11;
	m1["test"] = 100;
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	check("m1 == m2", m1 == m2);
	check("m1['a'] == m2['a']", m1["a"], m2["a"]);
	check("m1['d'] == m2['d']", m1["d"], m2["d"]);
	check("m1['test'] == m2['test']", m1["test"], m2["test"]);
	check("m1['z'] == m2['z']", m1["z"], m2["z"]);
}

static void insert(void)
{
	print_header("Insert");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);
	m1.insert(++m1.begin(), ft::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));
	check("m1 == m2", m1 == m2);
	m1.insert(ft::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(ft::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));
	check("m1 == m2", m1 == m2);
}

static void erase(void)
{
  print_header("Erase");
  ft::map<std::string, int> m1;
  std::map<std::string, int> m2;
  m1["test"] = 1;
  m1["a"] = 2;
  m1["b"] = 3;
  m1["c"] = 4;
  m1["d"] = 6;
  m1["e"] = 8;
  m2["test"] = 1;
  m2["a"] = 2;
  m2["b"] = 3;
  m2["c"] = 4;
  m2["d"] = 6;
  m2["e"] = 8;
  check("m1 == m2", m1 == m2);
  m1.erase(++m1.begin());
  m2.erase(++m2.begin());
  check("m1 == m2", m1 == m2);
  m1.erase(m1.begin(), --m1.end());
  m2.erase(m2.begin(), --m2.end());
  check("m1 == m2", m1 == m2);
  check("m1 == m2", m1 == m2);
}

static void swap(void)
{
	print_header("Swap");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;
	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;
	m3["a"] = 42;
	m3["b"] = 21;
	m4["a"] = 42;
	m4["b"] = 21;
	m1.swap(m3);
	m2.swap(m4);
	check("m1 == m2", m1 == m2);
	check("m3 == m4", m3 == m4);
}

static void clear(void)
{
	print_header("Clear");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m1.clear();
	m2.clear();
	check("m1 == m2", m1 == m2);
}

static void find(void)
{
	print_header("Find");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	check("m1.find('a') == m2.find('a')", m1.find("a")->second, m2.find("a")->second);
	check("m1.find('z') == m2.find('z')", m1.find("a")->second, m2.find("a")->second);
}

static void count(void)
{
	print_header("Count");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	check("m1.count('a') == m2.count('a')", m1.count("a"), m2.count("a"));
	check("m1.count('b') == m2.count('b')", m1.count("b"), m2.count("b"));
	check("m1.count('z') == m2.count('z')", m1.count("z"), m2.count("z"));
}

static void bounds()
{
	print_header("Bounds");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("a")->first, m2.lower_bound("a")->first);
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("c")->first, m2.lower_bound("c")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("a")->first, m2.upper_bound("a")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("c")->first, m2.upper_bound("c")->first);
}

static void range(void)
{
	print_header("Equal range");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	ft::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	check("a.first->first == b.first->first", a.first->first, b.first->first);
	check("a.first->second == b.first->second", a.first->second, b.first->second);
	check("a.second->first == b.second->first", a.second->first, b.second->first);
	check("a.second->second == b.second->second", a.second->second, b.second->second);
}

static void operators_comp(void)
{
	print_header("Operators");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m3 = m1;
	m4 = m2;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m1["e"] = 1;
	m2["e"] = 1;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m3["e"] = 3;
	m4["e"] = 3;
	check("m1 == m2", (m1 == m3), (m2 == m4));
	check("m1 != m2", (m1 != m3), (m2 != m4));
	check("m1 > m2", (m1 > m3), (m2 > m4));
	check("m1 < m2", (m1 < m3), (m2 < m4));
	check("m1 >= m2", (m1 >= m3), (m2 >= m4));
	check("m1 <= m2", (m1 <= m3), (m2 <= m4));
}

int main(void)
{
	print_header("map");
	constructors();
	max_size();
	access_operator();
	insert();
	erase();
	swap();
	clear();
	find();
	count();
	bounds();
	range();
	operators_comp();
  return (0);
}

// int main ()
// {
//   ft::map<char,int> mymap;
//   auto it = mymap.end();

//   it = mymap.emplace_hint(it,'b',10);
//   mymap.emplace_hint(it,'a',12);
//   mymap.emplace_hint(mymap.end(),'c',14);

//   std::cout << "mymap contains:";
//   for (auto& x: mymap)
//     std::cout << " [" << x.first << ':' << x.second << ']';
//   std::cout << '\n';

//   return 0;
// }