// Room: /yangzhou/dashidongji.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","达士东街");
	set("long",@LONG
扬州的手工艺天下闻名，玉器的雕琢，铜镜的磨制，雕板印刷术，
以及漆器、竹器的制作，无不是名冠天下。达士街上集中扬州大部分的
手工作坊和一些手工艺品的店铺。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"dashixijie",
		"east"  : __DIR__"dongmen",
		"north" : __DIR__"caiyidongjie",
		"south" : __DIR__"xiangfenpu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}