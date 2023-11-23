#include "revolution.h"
extern "C" {
    s32 IOS_Ioctl(s32, s32, void *, u32, void *, u32);
	s32 IOS_Open(const char *, u32);
	s32 IOS_Close(s32);
}
#include "Libusbkbd/kbd.h"

int libkbdver = 1.0;

struct kbdmessage
{
	int type[4];
	int unknown[4];
	int modifiers[1];
	int unknown2[1];
	int pressed[6];
};

struct messagetype
{
	int option;
	char* typechar;
}
message_types[] = 
{
	{0,"Keyboard connected"},
	{1,"Keyboard disconnected"},
	{2,"Event"},
	{999,NULL}
};

struct messagemodifiers 
{
	int option;
	char* typechar;
}
message_mods[] =
{
	{0,"No modifier"},
	{1,"Left control"},
	{2,"Left shift"},
	{4,"Left alt"},
	{8,"Left windows key"},
	{10,"Right control"},
	{20,"Right shift"},
	{40,"Right alt"},
	{80,"Right windows key"},
	{999,"No modifier"}
};

struct messagepressed
{
	int option;
	char* typechar;
}
message_keys[] =
{
	{4,"a"},
	{5,"b"},
	{6,"c"},
	{7,"d"},
	{8,"e"},
	{9,"f"},
	{10,"g"},
	{11,"h"},
	{12,"i"},
	{13,"j"},
	{14,"k"},
	{15,"l"},
	{16,"m"},
	{17,"n"},
	{18,"o"},
	{19,"p"},
	{20,"q"},
	{21,"r"},
	{22,"s"},
	{23,"t"},
	{24,"u"},
	{25,"v"},
	{26,"w"},
	{27,"x"},
	{28,"y"},
	{29,"z"},
	{30,"1"},
	{31,"2"},
	{32,"3"},
	{33,"4"},
	{34,"5"},
	{35,"6"},
	{36,"7"},
	{37,"8"},
	{38,"9"},
	{39,"0"},
	{40,"enter"},
	{41,"escape"},
	{42,"backspace"},
	{43,"tab"},
	{44," "},
	{45,"-"},
	{46,"="},
	{47,"["},
	{48,"]"},
	{51,";"},
	{52,"'"},
	{53,"#"},
	{54,","},
	{55,"."},
	{56,"/"},
	{57,"capslock"},
	{58,"F1"},
	{59,"F2"},
	{60,"F3"},
	{61,"F4"},
	{62,"F5"},
	{63,"F6"},
	{64,"F7"},
	{65,"F8"},
	{66,"F9"},
	{67,"F10"},
	{68,"F11"},
	{69,"F12"},
	{70,"printscreen"},
	{71,"scrollolck"},
	{72,"pause"},
	{73,"insert"},
	{74,"home"},
	{75,"pageup"},
	{76,"delete"},
	{77,"end"},
	{78,"pagedown"},
	{79,"right"},
	{80,"left"},
	{81,"down"},
	{82,"up"},
	{83,"numlock"},
	{84,"num/"},
	{85,"num*"},
	{86,"num-"},
	{87,"num+"},
	{88,"numenter"},
	{89,"num1"},
	{90,"num2"},
	{91,"num3"},
	{92,"num4"},
	{93,"num5"},
	{94,"num6"},
	{95,"num7"},
	{96,"num8"},
	{97,"num9"},
	{98,"num0"},
	{99,"num."},
	{100,"|"},
	{999,NULL}
};

struct messagetype msgtype;
struct messagemodifiers msgmods;
struct messagepressed msgkeys;
struct kbdmessage kbdm;

char* kbdhandle(int fd, char message[15], bool output)
{
	char* ret="";
	kbdm.type[0]=message[0];
	kbdm.type[1]=message[1];
	kbdm.type[2]=message[2];
	kbdm.type[3]=message[3];
	kbdm.unknown[0]=message[4];
	kbdm.unknown[1]=message[5];
	kbdm.unknown[2]=message[6];
	kbdm.unknown[3]=message[7];
	kbdm.modifiers[0]=message[8];
	kbdm.unknown2[0]=message[9];
	kbdm.pressed[0]=message[10];
	kbdm.pressed[1]=message[11];
	kbdm.pressed[2]=message[12];
	kbdm.pressed[3]=message[13];
	kbdm.pressed[4]=message[14];
	kbdm.pressed[5]=message[15];
	if(output==true)
	{
		OSReport("\n");
		OSReport("Message breakdown = \n");
		OSReport("  Type      = %x %x %x %x\n",kbdm.type[0],kbdm.type[1],kbdm.type[2],kbdm.type[3]);
		OSReport("  Unknown   = %x %x %x %x\n",kbdm.unknown[0],kbdm.unknown[1],kbdm.unknown[2],kbdm.unknown[3]);
		OSReport("  Modifiers = %x\n",kbdm.modifiers[0]);
		OSReport("  Unknown2  = %x\n",kbdm.unknown2[0]);
		OSReport("  Pressed   = %x %x %x %x %x %x\n",kbdm.pressed[0],kbdm.pressed[1],kbdm.pressed[2],kbdm.pressed[3],kbdm.pressed[4],kbdm.pressed[5]);
		OSReport("\n");
		OSReport("  Type      = ");
		int i;
		for (i = 0; message_types[i].option != 999; i++) 
		{
			if (kbdm.type[3]==message_types[i].option)
			{
				OSReport("%s",message_types[i].typechar);
			}
		}
		OSReport("\n");
		OSReport("  Modifiers = ");
		int j;
		for (j = 0; message_mods[j].option != 999; j++) 
		{
			if (kbdm.modifiers[0]==message_mods[j].option)
			{
				OSReport("%s",message_mods[j].typechar);
			}
		}
		OSReport("\n");
		OSReport("  Pressed   = ");
	}
	int f;
	for (f = 0; message_keys[f].option != 999; f++) 
	{
		if (kbdm.pressed[0]==message_keys[f].option)
		{
			if(output==true)
			{
				OSReport("%s",message_keys[f].typechar);
			}
			ret=message_keys[f].typechar;
		}
	}
	if(output==true)
	{
		OSReport("\n\n");
	}
	return ret;
}

char* kbdscan(int kbdfd)
{
	char* kbdmo="";
	char* test=" ";
	IOS_Ioctl(kbdfd,0x00,(void*)test,1,(void*)kbdmo,16);
	return kbdmo;
}

void kbddeinit(int kbdfd)
{
	IOS_Close(kbdfd);
}

int kbdinit()
{
	return IOS_Open("/dev/usb/kbd",1);
}

int kbdver()
{
	return libkbdver;
}

