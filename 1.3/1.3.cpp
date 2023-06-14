#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <functional>

const double Pi = 3.1415926;

void printAngles(const std::vector<int>& angles) {
	for (const auto& angle : angles) {
		if (angle != angles.back()) {
			std::cout << angle << " deg (" << (angle * Pi / 180) << " rad), ";
		}
		else {
			std::cout << angle << " deg (" << (angle * Pi / 180) << " rad). ";
		}
	}
}

void printOutput(const std::vector<int>& angles, std::vector<std::function<void(int)>> functions) {
	for (const auto& angle : angles) {
		std::cout << angle << " deg : ";
		for (const auto& function : functions) {
			function(angle);
		}
		std::cout << std::endl;
	}
};


int main(int argc, char** argv) {

	std::vector<int> angles = { 30, 60, 90 };

	std::cout << "GIVEN ANGLES: ";
	printAngles(angles);

	std::cout << std::endl << std::endl;

	std::function<void(int)> cosine = [](const int& angle) -> void {
		std::cout << std::setprecision(6) << "cos = " << std::cos(angle * Pi / 180) << '\t';
	};
	std::function<void(int)> sine = [](const int& angle) -> void {
		std::cout << std::setprecision(6) << "sin = " << std::sin(angle * Pi / 180) << '\t';
	};

	auto functions = { sine, cosine };

	std::cout << "OUTPUT:\n";
	printOutput(angles, functions);

	return EXIT_SUCCESS;
}