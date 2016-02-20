// Room: /d/heimuya/guang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "山谷");
	set("long", @LONG
这里是一处山谷，上面种植着草坪。南面是『日月神教』的青龙堂。
向西有一条上山的石道。
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
		"east"    : __DIR__"linjxd1",
		"west"    : __DIR__"shidao1",
		"southup" : __DIR__"dating3",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}