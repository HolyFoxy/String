#include <iostream>

class String
{
private:
	size_t size;
	char* m_string;
public:
	String()
	{
		size = 0;
		m_string = new char[1];
		m_string[0] = '\0';
	}
	String(size_t size_)
	{
		m_string = new char[size_];
		size = size_;
	}
	String(const String& string)
	{
		size = string.size;
		if (m_string != nullptr)
			delete[]m_string;
		m_string = new char[string.size];
		for (size_t i = 0; i < string.size; i++) {
			m_string[i] = string.m_string[i];
		}
	}
	size_t getSize()
	{
		return size;
	}

	void operator=(const String& str) {
		if (m_string!=nullptr)
			delete[]m_string;
		size = str.size;
		m_string = new char[size];
		for (size_t t = 0; t < size; t++)
			m_string[t] = str.m_string[t];
	}
	friend String operator+ (const String& string1, const String& string2);
	friend std::ostream& operator<<(std::ostream& os, const String& string);
	friend std::istream& operator>>(std::istream& is, const String& string);
};

String operator+ (const String& string1, const String& string2)
{
	size_t size_ = string1.size + string2.size;
	String newString(size_);
	for (size_t i = 0; i < string1.size; i++)
	{
		newString.m_string[i] = string1.m_string[i];
	}
	for (size_t i = 0; i < string2.size; i++)
	{
		newString.m_string[string1.size+i] = string2.m_string[i];
	}
	return newString;
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	for (size_t t = 0; t < string.size; t++)
		os << string.m_string[t];
	os << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, const String& string) 
{
	for (size_t t = 0; t < string.size; t++)
		is >> string.m_string[t];
	return is;
}



int main() {
	String str(5);
	std::cin >> str;
	String str2(5);
	std::cin >> str2;
	String stro;
	stro = str + str2;
	std::cout << stro;
}
