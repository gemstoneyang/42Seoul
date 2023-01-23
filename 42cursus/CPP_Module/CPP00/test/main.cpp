#include <iostream>

int	main(void)
{
	char	*pBuffer = new char[128];
	std::cout << "pBuffer 입력 : ";
	std::cin.getline(pBuffer, sizeof(char) * 128);
	std::cout << "result : " << pBuffer << std::endl;
	delete[] pBuffer;
	return 0;
}
