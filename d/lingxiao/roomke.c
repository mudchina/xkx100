// Room: /d/lingxiao/roomke.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG
这里是柯万仞的房间。柯万仞喜欢收集武器，房间四壁都挂满了形
形色色的刀剑，从倭刀到西洋剑，应有尽有。床边还挂了一柄奇怪的东
西，听说是前年从西域来的番人送给他的火枪。据说老爷子想试试这家
伙的威力，结果在床上躺了一个月。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang2", 
	]));
	set("objects", ([  
		CLASS_D("lingxiao")+"/ke" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

