set GTEST_DIR=C:\csd_auth\2nd_semester\domes_dedomenwn\cpp\programming\googletest-master\googletest

g++ -g -std=c++11 -isystem %GTEST_DIR%/include -I..\code -pthread test.cpp -o test.exe -L%GTEST_DIR%/mybuild -lgtest  
rem test.exe