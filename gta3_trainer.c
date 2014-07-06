#include <windows.h>
#include <strings.h>
#include <stdio.h>
#include <time.h>

char i,key[]={VK_F5,VK_F6,VK_F7,VK_F8,VK_F9,VK_F10,VK_F11};
HWND activeWin;
MSG msg={0};

void pushText(const char* text){
	char vk;
	Sleep(100);
	for(i=0; i<strlen(text); i++){
		vk=LOBYTE(VkKeyScan(text[i]));
		keybd_event(vk,0,0,0);
		Sleep(5);
		keybd_event(vk,0,KEYEVENTF_KEYUP,0);
	}
}

int main(int argc, char* argv[]){
	for(i=0;i<strlen(key);i++){
		RegisterHotKey(NULL,i,0,key[i]);
	}
	while(GetMessage(&msg,NULL,0,0)!=0){
		if(msg.message==WM_HOTKEY){
			activeWin=GetForegroundWindow();
			switch(msg.wParam){
				case 0:
					pushText("gesundheit"); break;
				case 1:
					pushText("turtoisetortoise"); break;
				case 2:
					pushText("gunsgunsguns"); break;
				case 3:
					pushText("ifiwerearichman"); break;
				case 4:
					pushText("nopoliceplease"); break;
				case 5:
					pushText("giveusatank"); break;
				case 6:
					pushText("bangbangbang"); break;
			}
		}
	}
	for(i=0;i<strlen(key);i++){
		UnregisterHotKey(NULL,i);
	}
	return EXIT_SUCCESS;
}
