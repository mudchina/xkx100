// Room: /binghuo/northboat2.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "帆船");
	set("long", @LONG
这是一艘三桅海船，不知船主是谁。船上前后两桅挂了白帆，准
备出海。船中舱中备有粮水，足够支用半年。船上水手个个都是哑巴。
主桅上白帆飘动，猎猎作响。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

