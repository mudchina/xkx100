// Room: /d/lingxiao/bridge.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","小桥");
	set("long",@LONG 
这是一座江南园林似的小桥，桥下莲叶田田，清波荡漾，水滑栏碧，
池鱼自得。城外虽有雪花飞舞之姿，朔风呼号之势，此处却得地气温暖
之润，得天独厚，有如江南之景，现于雪域大地。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"houyuan2",  
		"north"  : __DIR__"book", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31000);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);

}

