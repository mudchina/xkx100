// Room: /d/huangshan/mengbi.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "梦笔生花");
	set("long", @LONG
远远见松海中耸立着一根独特的石柱，下部直如笔杆，上端酷似笔
尖，笔杆和笔尖之间夹一石缝，更显得象一只自然毛笔，笔尖之上更有
一株古松，盘旋曲折，生机盎然，这就是石笔所生之花。相传当年太白
曾在此吟诗，于是怪石也就因“李太白少时，梦所用之笔头上生花，后
天才瞻逸，名闻天下”而被称作“梦笔生花”。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"sanhua",
	]));
	set("objects", ([
		__DIR__"obj/meng" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
