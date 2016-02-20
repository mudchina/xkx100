//Room: /d/foshan/yingxionglou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","英雄楼");
	set("long",@LONG
酒楼里桌椅洁净。座中客人衣饰豪奢，十九是富商大贾。佛山
地处交通要地，来这吃饭的人还真不少。
LONG);
	set("objects", ([
	    __DIR__"npc/fengqi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street4",
	    "south"  : __DIR__"majiu",
	    "up"     : __DIR__"yingxionglou2",
	]));
	set("coor/x", -1300);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
