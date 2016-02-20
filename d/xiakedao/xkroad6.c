// Room: /d/xiakedao/xkroad6.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "渔村小屋");
	set("long", @LONG
小村的渔民小屋十分简陋，几乎没什么家当，壁上挂满了早用旧
了的渔具。大概大人都出海了，只有一个小孩在屋里，看到你进来一
脸惊惶。
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"south"   : __DIR__"xkroad5",
	]));
	set("objects", ([
		__DIR__"npc/kid": 1,
	]));
	set("coor/x", -1390);
	set("coor/y", -8990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}