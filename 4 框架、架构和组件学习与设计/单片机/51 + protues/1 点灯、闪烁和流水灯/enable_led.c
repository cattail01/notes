// 开启led灯
// 学习重点：设置端口0或1

#include "../code_base/test_control.h"
#include <REGX51.H>

void settings(){
	P2 = 0xfe ;	// 1111 1110
}

void loop(){
	
}

#if ENABLE_LED
int main(){
	settings();
	while (1) loop();
	return 0;
}
#endif
