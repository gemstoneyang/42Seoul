#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]\n"
			  << "나는 7XL 더블 치즈 트리플 피클 스페셜 케찹 버거에 베이컨을 추가하는 걸 좋아해.\n"
			  << "너무 맛있어!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]\n"
			  << "베이컨을 추가하는데 돈이 든다고? 거짓말하지마.\n"
			  << "넌 내 버거에 베이컨을 충분히 넣지 않았어!\n"
			  << "너가 진작에 베이컨을 많이 넣었으면, 내가 추가하지 않았겠지!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]\n"
			  << "솔직히 나한텐 베이컨 추가 무료로 해줘.\n"
			  << "넌 지난 달부터 여기서 일했지? 난 몇 년동안 여기 단골이라고." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]\n"
			  << "아 진짜 말 안통하네! 당장 매니저 불러!" << std::endl;
}

void	Harl::complain(std::string level) {
	const std::string	strArr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					i = 0;

	while (i != 4) {
		if (level == strArr[i])
			break;
		i++;
	}

	switch (i) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "invalid input" << std::endl;
			break;
	}
}
