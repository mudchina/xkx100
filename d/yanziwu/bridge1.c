// Room: /d/yanziwu/bridge1.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "回望桥");
	set("long", @LONG
出了林中小路，就是莲韵塘。行人到此，每每回望来路，看青泥小
径在林中曲折隐没，别有一般韵味。看桥下莲韵塘中荷叶田田，蛙鸣鱼
跃，生机无限。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"path10",
		"north"  : __DIR__"path11",
	]));
	set("coor/x", 1240);
	set("coor/y", -1230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}