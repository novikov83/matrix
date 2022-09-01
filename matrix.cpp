#include <iostream>
//#include <list>
#include <map>

template <typename T, T default_value>
class TLine
{
public:
	TLine() {};

	T& operator[](int index) {
		try {
			mLine.at(index);
		}
		catch (const std::out_of_range&) {
			mLine[index] = default_value;
		}
		return mLine[index];
	};
	size_t size() {
		size_t	size{0};
		for (auto& [index, value] : mLine) {
			if (value != default_value) {
				size++;
			}			
		}
		return size;
	};
	void print(int index_x) {
		for (auto& [index_y, value] : mLine) {
			if (value != default_value) {
				std::cout << "[" << index_x << "][" << index_y << "]=" << value << std::endl;
			}			
		}
	}
private:
	std::map<int, T>	mLine;
};

template <typename T, T default_value>
class Matrix
{
public:

	TLine<T, default_value>& operator[](int index) {
		return mLines[index];
	};
	size_t size() {
		size_t	size{0};
		for (auto& [index, line] : mLines) {
			size += line.size();
		}
		return size;
	};
	void print() {
		for (auto& [index, line] : mLines) {
			line.print(index);
		}
		return;
	};

private:
	std::map<int, TLine<T, default_value>> mLines;
};

int main(int, char**)
{
	Matrix<int, 0>	matrix;
	for (int i = 0; i < 10; i++) {
		matrix[i][i] = i;
		matrix[9-i][i] = i;
	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "size=" << matrix.size() << std::endl;

	matrix.print();

	return 0;
}
