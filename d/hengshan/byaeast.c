// Last Modified by Sir on May. 22 2001
//Room: byaeast.c 白云庵东廊

inherit ROOM;
void create()
{
	set("short","白云庵东廊");
	set("long",@LONG
这里是恒山白云庵东廊。走廊往北通往练武房，东边通往藏经阁。
LONG);
	set("outdoors", "hengshan");
	set("exits",([ /* sizeof() == 1 */
		"north" : __DIR__"liangong", 
		"east"  : __DIR__"cangjingge", 
		"west"  : __DIR__"baiyunan",
	]));
	set("objects", ([
		__DIR__"npc/qin" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 50);
	set("coor/y", 3210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
