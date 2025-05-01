#pragma once

class Data
{
	private:
		int num;

	public:
		Data();
		~Data();
		Data(const Data &copy);
		Data &operator=(const Data &ref);
		Data(const int _num);

		int	getNum() const;
};