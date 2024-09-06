////#include <iostream>
////#include <fstream>
////using namespace std;
////
////void test()
////{
////	// Creating the output file stream
////	ofstream ofs;
////
////	// writing data to the file
////	ofs.open("test.txt", ios::out);
////	
////	ofs << "name: Alen" << endl;
////	ofs << "age: eighteen" << endl;
////	ofs << "height: one hundred and seventy" << endl;
////
////	// closing the file
////	ofs.close();
////}
////
////int main()
////{
////	test();
////	return 0;
////}
//
//
////#include <iostream>
////#include <fstream>
////
////
////void test()
////{
////	std::ofstream ofs;
////
////	ofs.open("test.txt", std::ios::out);
////
////	ofs << "bwxsz" << std::endl;
////	ofs << "mzrsz" << std::endl;
////
////	ofs.close();
////}
////
////int main()
////{
////	test();
////
////	return 0;
////}
//
//
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//
//void test()
//{
//	ifstream ifs;
//
//	ifs.open("test.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "mzr is not a pig actually!!!" << endl;
//		return;
//	}
//
//	char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}
//
//	//char buf[1024] = { 0 };
//	//while (ifs.getline(buf, sizeof(buf)))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//string buf;
//	//while (getline(ifs, buf))
//	//{
//	//	cout << buf << endl;
//	//}
//
//	//char c;
//	//while ((c = ifs.get()) != EOF)
//	//{
//	//	cout << c;
//	//}
//
//	ifs.close();
//}
//
//int main()
//{
//	test();
//	return 0;
//}