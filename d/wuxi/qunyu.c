// Room: /d/wuxi/qunyu.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "群玉院");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下
子就明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得
妖里妖气的女人分站两旁对你发出媚笑。老鸨上上下下、前前后后招呼
着客人。
LONG );
	set("exits", ([
		"west" : __DIR__"southroad2",
	]));
	set("item_desc", ([
		"tu" : "",
	]));
	set("objects", ([
		__DIR__"npc/laobao" : 1,
	]));
	set("coor/x", 380);
	set("coor/y", -830);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}