#include <iostream>
using namespace std;

class SmartArray {
private:
	int* arr = nullptr;
	size_t size = 0;
	int index = 0;
public:
	SmartArray(int num) : size(num) {
		arr = new int[size];
	}

	SmartArray(const SmartArray&) = delete;
	SmartArray& operator=(const SmartArray&) = delete;

	void addElement(int num) {
		if (index < size) {
			arr[index++] = num;
		}
		else {
			throw exception("The array is full.");
		}
		return;
	}

	void deleteBackElement() {
		if (index > 0) {
			arr[--index] = 0;
		}
		else {
			throw exception("The array is empty.");
		}
		return;
	}

	int getElement(int index) const {
		if ((index >= 0) && (index < this->index)) {
			return arr[index];
		}
		else {
			throw exception("Requested index is out of range.");
		}
	}

	int operator[](int index) const {
		return getElement(index);
	}

	virtual ~SmartArray() {
		delete[] arr;
	}
};

int main(int argc, char** argv) {

	try {
		SmartArray smart_array(5);
		smart_array.addElement(1);
		smart_array.addElement(4);
		smart_array.addElement(155);
		smart_array.addElement(14);
		smart_array.addElement(28);


		for (int i = 0; i < 5; ++i) {
			cout.width(3);
			cout << smart_array[i] << ' ';
		}

		cout << endl;
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();

		for (int i = 0; i < 5; ++i) {
			cout.width(3);
			cout << smart_array[i] << ' ';
		}
	}
	catch (const exception& ex) {
		cerr << "\nError: " << ex.what() << endl;
	}

	return 0;
}