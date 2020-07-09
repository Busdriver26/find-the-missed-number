// search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	cout << "***************Author:BU5DR1V3R***************" << endl;
	cout << "欢迎使用。 系统注意事项如下：" << endl;
	cout << "1.数据大小限制：18446744073709551615(64位机器)" << endl;
	ifstream infile;
	cout << "2.请确认文件置于根目录下并命名为src.txt" << endl;
	cout << "3.请确保数据没有负数、并且数据严格递增、没有重复。" << endl;
	cout << "确认请输入任意字符并回车以继续。" << endl;
	char t;
	cin >> t;
	int succeed = 1;
	infile.open("src.txt");
	if (!infile.is_open()) {
		cout << "打开失败，请检查文件" << endl;
		succeed -= 1;
	}
	ofstream ofile;
	ofile.open("out.txt");
	if (!ofile.is_open()) {
		cout << "out失败，请检查文件" << endl;
		succeed -= 1;
	}
	cout << "缺失数据：" << endl;
	//
	unsigned long long temp,ltemp=1,cnt=0;
	while (infile >> temp) {
		cnt++;
		if (temp < ltemp) {
			cout << "数据并非严格递增！" << endl;
			cout << "出错位置：第 " << cnt << "行" << endl;
			cout << "请排序后删除out.txt并重试" << endl;
			succeed = 0;
			break;
		}
		while (temp != ltemp) {
			cout << ltemp << endl;
			ofile << ltemp << endl;
			ltemp++;
		}
		ltemp++;
	}
	//
	if (succeed == 1) {
		cout << "成功录入，请检查" << endl;
	}
	ofile.close();
	infile.close();
	cout << "*********************V1.0*********************" << endl;
	cout << "输入任意键并回车退出" << endl;
	cin>>t;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
