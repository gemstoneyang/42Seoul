#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << "나는 7XL 더블 치즈 트리플 피클 스페셜 케찹 버거에 베이컨을 추가하는 걸 좋아해. 너무 맛있어!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "베이컨을 추가하는데 돈이 든다고? 거짓말하지마. 넌 내 버거에 베이컨을 충분히 넣지 않았어! 너가 진작에 베이컨을 많이 넣었으면, 내가 추가하지 않았겠지!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "솔직히 나한텐 베이컨 추가 무료로 해줘. 넌 지난 달부터 여기서 일했지? 난 몇 년동안 여기 단골이라고." << std::endl;
}

void	Harl::error(void) {
	std::cout << "아 진짜 말 안통하네! 당장 매니저 불러!" << std::endl;
}

void	Harl::complain(std::string level) {
	const std::string	strArr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	funcptr				funcArr[4];

	funcArr[0] = &Harl::debug;
	funcArr[1] = &Harl::info;
	funcArr[2] = &Harl::warning;
	funcArr[3] = &Harl::error;

	int	i = 0;

	while (i != 4) {
		if (level == strArr[i]) {
			(this->*funcArr[i])();
			break;
		}
		i++;
	}
	if (i >= 4)
		std::cout << "invalid input" << std::endl;
}
