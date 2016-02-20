// Room: /d/huanggong/bukufang.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "布库房");
	set("long", @LONG
屋中空空洞洞，墙壁边倚着几个牛皮的人形，梁上垂下来几只大布
袋，里面似乎装作米麦或是沙土，此外便只有一张桌子，桌前挂着块桌
帷。
LONG
	);
	set("exits", ([
		"north"    : __DIR__"ciningmen",
	]));
	set("objects", ([
		__DIR__"obj/table" :1,
	]));
	set("coor/x", -220);
	set("coor/y", 5269);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}