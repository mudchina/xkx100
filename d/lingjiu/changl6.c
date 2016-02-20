//room: changl6.c
inherit ROOM;

void create()
{
	set("short","画廊");
	set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上
面雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做
的，走在上面毫无声息，你只感到脚下软软的，非常舒服。
LONG );
	set("exits",([
		"north" : __DIR__"changl5",
		"west" : __DIR__"chufang",
		"east" : __DIR__"changl7",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51020);
	set("coor/y", 30140);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}