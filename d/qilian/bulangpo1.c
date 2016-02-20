// Room: /d/qilian/bulangpo1.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "不狼坡");
	set("long", @LONG
这里是祁连山脉的开始，地势复杂。山中多为人迹罕至之处，矿藏
颇丰，且山中有众多野生动物，是巡猎、访宝的好去处。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"northup" : __DIR__"bulangpo2",
		"south"   : __DIR__"bonanshan",
	]));
	set("objects", ([
		__DIR__"npc/mulang": 1,
	]));
	set("coor/x", -9900);
	set("coor/y", 2800);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}