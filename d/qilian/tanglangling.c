// Room: /d/qilian/tanglangling.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "螳螂岭");
	set("long", @LONG
这里是祈连山区边缘。出了螳螂岭往西就是西北平原，北望玉门，
西北到嘉峪关。螳螂岭山形漫长，山势低矮，再加上通山翠绿，四季不
变，故而得名。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"eastup"    : __DIR__"qitianfeng",
		"northdown" : "/d/xingxiu/jiayuguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -18000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
