// Room: /d/nanshaolin/gulou4.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓楼四层");
	set("long", @LONG
到这里楼梯大概只能容一人上下，墙身也略薄了些。视线越过窗棂，
北边的练武场，罗汉堂，般若堂历历在目，不少僧人正汇集在练武场上
习武，吆喝声一阵阵传进耳鼓。东边的天王殿，山门殿也尽露全貌。
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou5",
		"down" : __DIR__"gulou3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
