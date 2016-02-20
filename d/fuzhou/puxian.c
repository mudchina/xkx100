// Last Modified by Winder on May. 21 2001
// Room: /d/fuzhou/puxian.c

inherit ROOM;

void create()
{
	set("short", "莆仙平原");
	set("long", @LONG
你走在莆仙平原上。这里物产丰饶，人烟稠密，望北就是福州府城
了。往南就进入闽南。往西望去，是一带丘陵。闽中丘陵苦不在高，连
绵起伏不断。密密层层的树丛中，一条山路蜿蜒前伸。
LONG );
	set("exits", ([
		"north" : __DIR__"zhongzhou",
		"south" : "/d/quanzhou/anpingqiao",
		"west"  : "/d/nanshaolin/shanlu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1840);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
