// Room: /d/lingxiao/zoulang4.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","走廊");
	set("long",@LONG 
这是一条安静的走廊，北面是齐自勉的居室，南面是成自学的房间。
长老们向来除了授徒传艺，少有外出，这里一向少有人来，只有凌霄弟
子每日前来打扫。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"     : __DIR__"cheng",  
		"south"     : __DIR__"qi", 
		"southwest" : __DIR__"houyuan2", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

