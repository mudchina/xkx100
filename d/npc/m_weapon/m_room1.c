// ROOM m_room1.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "沙漠绿洲");
	set("long", @LONG
这里是沙漠中不多的一块绿洲，向南不远隐约可以看见一座黑黑的
山洞。随风传来一些叮叮当当的打铁的声音。也不知是谁在打造什么。
LONG );
	set("exits", ([
		"east"  : "/d/xingxiu/nanjiang2",
		"south" : __DIR__"xuanbing",
	]));
	set("no_clean_up", 0);
	set("coor/x", -41200);
	set("coor/y", 8990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
