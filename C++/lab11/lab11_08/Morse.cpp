bool Morse::convert( string& str1, int col,	string& str2)
{
		string encDec[27][2] = 
		{
			{ "A", ".-#" },
			{ "B", "-...#" },
			{ "C", "-.-.#" },
			{ "D", "-..#" },
			{ "E", ".#" },
			{ "F", "..-.#" },
			{ "G", "--.#" },
			{ "H", "....#" },
			{ "I", "..#" },
			{ "J", ".---#" },
			{ "K", "-.-#" },
			{ "L", ".-..#" },
			{ "M", "--#" },
			{ "N", "-.#" },
			{ "O", "---#" },
			{ "P", ".--.#" },
			{ "Q", "--.-#" },
			{ "R", ".-.#" },
			{ "S", "...#" },
			{ "T", "-#" },
			{ "U", "..-#" },
			{ "V", "...-" },
			{ "W", ".--#" },
			{ "X", "-..-#" },
			{ "Y", "-.--#" },
			{ "Z", "--..#" },
			{ " ", "$$#" }
		};
		bool found = false;
		int row;
		//입력된 str1이 encDec에서 같은 문자열이 존재 할 때까지만 탐색
		//입력 된 col에 따라서 영문에서 탐색 할 수도 있고,
		//모르스 부호에서 탐색 될 수 도 있다.
		//col이 0이면 영문에서 탐색, 1이면 모르스 부호에서 탐색.
		//encDec[row][col]의 이차원 문자열 배열에서,
		//배열에서 검색된 결과는 (row-1)에 위치
		//col이 0이면 1의 위치 문자열을 1이면 0의 위치의 문자열을 저장.
		return found;
}
string Morse::encode( string& inStr ){
	string s1;
	string s2;
	string outStr = "";
	bool error = false;
	size_t curr = 0;
	//입력된 모든 문자열을 탐색하여 모르스 부호로 변환
	// inStr 탐색
	{
		//inStr에서 cur번째 문자를 대문자로 변환하여 s1에 대입
		//convert함수 호출, (s1, 0, s2 );
		//outStr에 s2를 추가
		//cur을 1 증가
	}
	if( !error ) return outStr;
	else return ("Invalid character in Code\n");
}
string Morse::decode( string& inStr ){
	//모르스 부호의 끝은 #로 구분되어 있으므로,
	//입력 문자열 inStr에서 #를 찾아 단위 모르스 부호 탐색.
	//탐색 된 단위 모르스 부호를 영문으로 변환.
}