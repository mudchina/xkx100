// Room: /d/lingxiao/sroad3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
山行崎岖，这里已是雪山之上，朔风飞扬，黄云盖天。愈上愈高，
山势也愈来愈险，俯览群山，片片浮白，在云气弥漫之下，恍如云海中
星罗棋布的岛屿。这时已是正午时分，但寒气却愈来愈浓。四周白茫茫
的一片，惟有无边飞雪，纷纷扬扬从空中撒将下来。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"sroad2",
		"eastup"    : __DIR__"shiya",
	]));
	set("objects", ([
		__DIR__"npc/huyan" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8980);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}

