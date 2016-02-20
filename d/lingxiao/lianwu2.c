// Room: /d/lingxiao/lianwu2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "练武厅");
	set("long", @LONG
这里是凌霄城的练武场。只见刀光剑影，目不暇接，一群凌霄弟子
练得大汗淋漓，彼此打得难解难分。凌霄城里派系不和，彼此间明争暗
斗，门下弟子也只得努力练功，以防不测。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"fudian2",
	]));
	set("objects", ([ 
		"/d/shaolin/npc/mu-ren" : 4,
	]));
	set("outdoors", "lingxiao" );
	set("coor/x", -30980);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

