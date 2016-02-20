// Room: /d/kunlun/liangong.c 练功房
// Last Modified by Winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团，摆满了大刀长剑、沙袋
绑腿等，是昆仑弟子日常练功的地方。
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"jiuqulang4",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -119970);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}