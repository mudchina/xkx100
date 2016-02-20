// Room: /yangzhou/toujinpu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","孔家头巾铺");
	set("long",@LONG
孔家做的头巾帽子，花样繁多，式样也漂亮，扬州城的年轻人多到
此挑选一条自己喜欢的头巾。店内东边放置一张胡床，上面放满了各式
的头巾帽子，客人可以随便试着穿戴各式头巾帽子；西边放着几面铜镜，
几个小伙子正在边试戴各式头巾，边照镜子。
LONG );
	set("exits", ([
		"north" : __DIR__"caiyixijie",
	]));
	set("objects", ([
		__DIR__"npc/kongjinjin" : 1,
	]));
	set("coor/x", 50);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}