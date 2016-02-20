//Room: /d/foshan/dangpu.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","英雄典当");
	set("long",@LONG
当铺里一张高高的柜台，柜台后面坐着当铺的朝奉。这家当铺
是凤老爷所开，十多年来从没人来闹过事，朝奉也就很放心。柜台
上挂着一个木牌子(paizi)。
LONG);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "公平交易\n
	sell        卖 
	buy         买
	value       估价
",
	]));
	set("objects", ([
	   __DIR__"npc/chaofeng": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street5",
	]));
	set("coor/x", -1290);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
