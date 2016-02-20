// Room: /d/guiyun/shulin6.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "树林深处");
	set("long",@LONG
这是一片小树林。地面上绿草如荫，茂密地生长着。树叶的缝隙间
偶尔会有一只小鸟被惊起，四周十分静寂。
LONG
);
	set("objects",([
		__DIR__"obj/shizi" : 1,
	]));  
	set("exits",([
		"west" : __DIR__"shulin4",
	]) );
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

