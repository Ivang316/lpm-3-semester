#pragma once

class Array {
	static const long maxLen = 1000000;
	long len;
public: 
	Array(long length = 1);
	const long gLen();
	const long gMaxLen();
	void sLen(long);
};


