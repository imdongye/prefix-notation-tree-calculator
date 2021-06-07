// 201820189 ÀÓµ¿¿¹
#include "calculation_tree.h"

int main() {
	// (3*3)+2*(2+1)-3 = 12
	std::string formula = "- + * 3 3 * 2 + 2 1 3";
	std::cout << CalcurationTree().eval(std::cin);
	return 0;
}