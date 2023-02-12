// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
	while (true)
	{
		std::cout << "\n\nplease input a words : \n";
		char* input = new char[1024];
		int number = 0;
		std::cin >> input;
		std::cout << "word is :" << input << std::endl;
		std::cout << "please input a number : \n";
		std::cin >> number;
		std::cout << "number is :" << number << std::endl;
		char* output = new char[1024];
		for (int i = 0; i < 1024; i++)
		{
		
			int v = input[i];
			int code = 0;
			if (v < 65 || (v > 90 && v < 97) || v>122)
				output[i] = v;
			else
			{

				if (v >= 65 && v <= 90) // 大写字母输入
				{
					code = v + number;
					if (code > 90) // Z+1 = A
						code = 65;
					if (code < 65)// A-1 = Z
						code = 90;
				}
				else if (v >= 97 && v <= 122) // 小写字母输入
				{
					code = v + number;
					if (code > 122) // z+1 = a
						code = 97;
					if (code < 97)// a-1 = z
						code = 122;
				}
				else
				{
					code = v;
				}
				output[i] = code;
			}
			
			
		}
		std::cout << "word converted : "<<output<<std::endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
