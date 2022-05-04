while(cin >> value , !cin.eof())  // 检查eof状态
{
	if (cin.bad())  // 检查bad状态
		throw std::runtime_error("IO stream corrupted");
	if (cin.fail())  // 检查fail状态
	{
		cerr << "bad data" << endl;
		cin.clear(); // 恢复流到正常
		cin.ignore(200, '\n'); // 把流里面的数据清除到换行 或者清除200个字符
		continue;
	} 
}
	
————————————————
版权声明：本文为CSDN博主「I,Pencil」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_41684393/article/details/110431763