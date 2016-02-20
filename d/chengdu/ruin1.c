// Room: /d/chengdu/ruyin1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "破旧大宅");
	set("long", @LONG
这里是一间破旧大宅的前院，大厅已经崩塌了一半，焦黑的梁柱挡
住了你的去路，庭院里杂草丛生，看来已经很久没有人住了，据说这里
晚上有鬼魂出现，但是倒也从没听说过有人被害，因此附近的居民仍然
照常生活。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([ /* sizeof() == 1 */
		"out"   : __DIR__"cai",
		"west"  : __DIR__"ruin2",
		"north" : "/d/npc/m_weapon/lianbangshi",
	]));
	set("objects", ([
		__DIR__"npc/qigai" : 3,
	]));
	set("coor/x", -8070);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

