// Room: /d/guiyun/shulin7.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short", "树林深处");
	set("long",@LONG
这是一片小树林的深处。地面上绿草如荫，茂密地生长着。树叶的
缝隙间偶尔会有一只小鸟被惊起，四周十分静寂。这里时常有毒蛇出没，
最好不要在此久留。
LONG
);
	set("exits",([
		"south" : __DIR__"shulin5",
	]) );
	set("objects",([
		__DIR__"npc/snake" : 2,
	]));  
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}

