// Room: /d/lingxiao/lianwu1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "练武厅");
	set("long", @LONG
这里是凌霄城的练武场。场上放着几个木人，是供凌霄弟子练功之
用。几个凌霄弟子手持长剑，你来我往，正在场上练的起劲。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"fudian1",
	]));
	set("objects", ([ 
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "lingxiao" );
	set("coor/x", -31020);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

