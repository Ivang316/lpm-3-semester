#include "Decimal.h" 


void Decimal::init_with_string(const string& str) {
	resize(str.length());
	for (int i = 0, k = str.length() - 1; i < gLen(); i++, k--)
		arr[i] = str[k];
}


void Decimal::remove_leading_zeros() {
	int zeroCnt = 0;
	for (int i = gLen() - 1; i >= 0, arr[i] == '0'; i--)
		if (arr[i] == '0')
			zeroCnt++;
	resize(gLen() - zeroCnt);
}


void Decimal::resize(int count) {
	if (count > gMaxLen())
		return;

	unsigned char* newArr = new unsigned char[count];
	for (int i = 0; i < count; i++)
		newArr[i] = '0';

	if (arr) {
		int minLen = gLen() < count ? gLen() : count;
		for (int i = 0; i < minLen; i++)
			newArr[i] = arr[i];
	}

	sLen(count);
	delete[] arr;
	arr = newArr;
}


void Decimal::fill(unsigned char val) {
	if (gLen())
		for (int i = 0; i < gLen(); i++)
			arr[i] = val;
}


Decimal::Decimal() {}


Decimal::Decimal(int number) {
	int digitCnt = [](int n) {
		if (!n)
			return 1;
		int count = 0;
		while (n) {
			n /= 10;
			count++;
		}
		return count;
	}(number);

	resize(digitCnt);
	for (int i = 0; i < gLen(); i++) {
		arr[i] = number % 10 + '0';
		number /= 10;
	}
}


Decimal::Decimal(const string& str) {
	init_with_string(str);
}


Decimal::Decimal(Decimal& num) {
	if (arr)
		delete[] arr;

	sLen(num.gLen());
	arr = new unsigned char[gLen()];

	for (int i = 0; i < gLen(); i++)
		arr[i] = num.arr[i];
}



Decimal* Decimal::operator+(Decimal& num) {
	Decimal* res = new Decimal;
	int remainder = 0;

	if (*this > num) {
		res->resize(gLen());
		int i = 0;
		for (int sum; i < num.gLen(); i++) {
			sum = (arr[i] - '0') + (num.arr[i] - '0') + remainder;
			res->arr[i] = sum % 10 + '0';
			remainder = sum >= 10 ? 1 : 0;
		}
		for (int sum; i < gLen(); i++) {
			sum = (arr[i] - '0') + remainder;
			res->arr[i] = sum % 10 + '0';
			remainder = sum >= 10 ? 1 : 0;
		}
	}
	else {
		res->resize(num.gLen());
		int i = 0;
		for (int sum; i < gLen(); i++) {
			sum = (arr[i] - '0') + (num.arr[i] - '0') + remainder;
			res->arr[i] = sum % 10 + '0';
			remainder = sum >= 10 ? 1 : 0;
		}
		for (int sum; i < num.gLen(); i++) {
			sum = (num.arr[i] - '0') + remainder;
			res->arr[i] = sum % 10 + '0';
			remainder = sum >= 10 ? 1 : 0;
		}
	}

	if (remainder) {
		res->resize(res->gLen() + 1);
		res->arr[res->gLen() - 1] = 1 + '0';
	}
	return res;
}


Decimal* Decimal::operator-(Decimal& num) {
	if (*this == num) {
		Decimal* res = new Decimal(0);
		return res;
	}
	if (*this < num)
		cout << "cannot subtract a larger number from a smaller number\n";
	else {
		Decimal* res = new Decimal;
		res->resize(gLen());

		int carry = 0, i = 0;
		//цикл по цифрам меньшего числа
		for (; i < num.gLen(); i++) {
			int sub = (arr[i] - '0') - (num.arr[i] - '0') - carry;

			if (sub < 0) {
				sub = sub + 10;
				carry = 1;
			}
			else
				carry = 0;

			res->arr[i] = sub + '0';
		}

		//цикл по оставшимся цифрам
		for (; i < gLen(); i++) {
			int sub = (arr[i] - '0') - carry;

			if (sub < 0) {
				sub = sub + 10;
				carry = 1;
			}
			else
				carry = 0;

			res->arr[i] = sub + '0';
		}

		res->remove_leading_zeros();
		return res;
	}
}


const bool Decimal::operator==(Decimal& num) {
	if (gLen() != num.gLen())
		return false;

	for (int i = 0; i < gLen(); i++)
		if (arr[i] != num.arr[i])
			return false;

	return true;
}


const bool Decimal::operator!=(Decimal& num) {
	return !(*this == num);
}


const bool Decimal::operator>(Decimal& num) {
	if (gLen() > num.gLen())
		return true;
	else
		if (gLen() < num.gLen() || *this == num)
			return false;

	//len == num.len
	for (int i = gLen() - 1; i >= 0; i--)
		if (arr[i] < num.arr[i])
			return false;

	return true;
}


const bool Decimal::operator<(Decimal& num) {
	return !(*this >= num);
}


const bool Decimal::operator<=(Decimal& num) {
	return (*this < num) || (*this == num);
}


const bool Decimal::operator>=(Decimal& num) {
	return (*this > num) || (*this == num);
}


const unsigned char& Decimal::operator[](const unsigned long index) {
	if (index >= 0 && index < gLen())
		return arr[index];
}


istream& operator>>(istream& in, Decimal& num) {
	string str;
	in >> str;
	num.init_with_string(str);
	return in;
}


ostream& operator<<(ostream& out, Decimal& num) {
	for (int i = num.gLen() - 1; i >= 0; i--)
		out << num.arr[i];
	return out;
}
