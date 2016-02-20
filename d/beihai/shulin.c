// /d/beihai/shulin.c
// Last Modified by winder on May. 22 2002
inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是湖边一片小松树林，面积并不大。林中有一条小径蜿蜒曲折向
西延伸开去。穿过这片松林就可以看见北海的前大门了。
LONG
	);
	set("exits", ([
		"west"  : __DIR__"qianmen",
		"north" : __DIR__"dongmen",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -170);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
