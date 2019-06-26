#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<iostream>

using namespace std;


class number_t_exception_t: public exception
{
};

class overflow_set_exception: public number_t_exception_t
{
public:
	virtual const char* what(void) const throw ()
	{
		return "Overflow in representation";
	}
};

class divide_exception: public number_t_exception_t
{
public:
	virtual const char* what(void) const throw ()
	{
		return "Can not divide by 0";
	}
};

class wrong_number_exception: public number_t_exception_t
{
public:
	virtual const char* what(void) const throw ()
	{
		return "Can not use this base.";
	}
};

#endif