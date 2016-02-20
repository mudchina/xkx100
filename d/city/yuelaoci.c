// Room: /yangzhou/yuelaoci.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","月老祠");
	set("long",@LONG
小小的祠庙，香火稀少，坐落在扬州城的北面的角落上。少有人员
来往。偶然有些年轻男女匆匆的进入，喜忧参半的离开。进得庙中，中
间供着和蔼可亲的月老。月老面前一张供桌，两块跪石，简简单单的陈
设。
LONG );
	set("exits", ([
		"southwest"  : __DIR__"tianningxiang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 50);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}