// Room: /d/taishan/tianjie.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "天街");
	set("long", @LONG
此地在南天门东北，这里有数十户小贩聚而成市。道路平整，殿宇
毗连，似天上街市。天街坊东路北，为乾隆行宫及唐代文学家苏源明读
书处遗址。从这里往东南走便是莲花峰，东北是围屏山，西南便回到南
天门。
LONG );
	set("exits", ([
		"south"    : __DIR__"xiangshan",
		"eastup"   : __DIR__"weiping",
		"eastdown" : __DIR__"lianhua",
		"westdown" : __DIR__"nantian",
		"northup"  : __DIR__"kongziya",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 2,
		__DIR__"npc/tiao-fu" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 770);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
