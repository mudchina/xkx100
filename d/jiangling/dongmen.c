//Edited by fandog, 02/18/2000
inherit ROOM;
void create()
{
	set("short", "东门");
	set("long", @LONG
这是荆州城的东门。城门不大，也无人看守。往南走出城，是一条
蜿蜒曲折的山道。
LONG );
	set("outdoors", "jiangling");
	set("exits", ([
               "south" : __DIR__"shandao5",
               "north" : __DIR__"dongjie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1470);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}