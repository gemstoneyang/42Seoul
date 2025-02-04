#!/bin/bash
 echo -e "\033[32;1m"NORM"\033[m"
 read $a
 norminette ./*.c ./*.h

 echo -e "\033[32;1m"LIBFT TEST"\033[m"
 read $a
 cd ..
 git clone https://github.com/jtoty/Libftest
 cd Libftest/
 ./grademe.sh
 sed -i "" 's/~\//..\//' my_config.sh
 ./grademe.sh
 cd ..

 echo -e "\033[32;1m"WAR MACHINE"\033[m"
 read $a
 cd libft/
 git clone https://github.com/ska42/libft-war-machine
 cd libft-war-machine/
 bash grademe.sh
 bash grademe.sh
 cd ..

 echo -e "\033[32;1m"unit-test"\033[m"
 read $a
 cd ..
 git clone https://github.com/alelievr/libft-unit-test.git
 cd libft-unit-test/
 sed -i "" 's/LIBFTDIR    =    ..\/libft/LIBFTDIR    =    ..\//' Makefile
 make f
 cd ..
 rm -rf libft-unit-test/
 cd libft

 echo -e "\033[32;1m"libftTester"\033[m"
 read $a
 git clone https://github.com/Tripouille/libftTester.git
 cd libftTester/
 make a
 cd ..

 rm -rf ../Libftest/ libft-war-machine/ ../libft-unit-test/ libftTester/
 make fclean
 echo -e "\033[32;1m"DONE"\033[m"
