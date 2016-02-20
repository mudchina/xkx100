// Room: /d/guiyun/shulin3.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long",@LONG
这是一片小树林。地面上绿草如荫，茂密地生长着。树叶的缝隙间
偶尔会有一只小鸟被惊起，四周十分静寂。
LONG
);
	set("objects",([
		__DIR__"obj/stick" : 1,
	]));  
	set("exits",([
		"west"  : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
		"south" : __DIR__"caodi3",
	]) );
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

