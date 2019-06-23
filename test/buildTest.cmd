del test.exe
set GTEST_DIR=C:\csd_auth\2nd_semester\domes_dedomenwn\cpp\programming\googletest-master\googletest

g++ -g -std=c++11 -isystem %GTEST_DIR%/include -I..\code -pthread test.cpp ..\code\heap.cpp ..\code\minheap.cpp ..\code\driver.cpp ..\code\maxheap.cpp ..\code\avl.cpp ..\code\hashtable.cpp ..\code\graph.cpp  ..\code\priorityQueue.cpp ..\code\sortedLinkedList.cpp ..\code\linkedList.cpp -o test.exe -L%GTEST_DIR%/mybuild -lgtest  
test.exe