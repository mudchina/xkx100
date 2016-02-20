// Room: /d/yanziwu/yunjin2.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "云锦二楼");
	set("long", @LONG
云锦楼上陈设富丽，一幅中堂绘的是孔雀开屏，两旁一副木联，写
的是：“漆叶云差密，茶花雪妒妍”。往楼外望去，湖天一线，烟波浩
渺，穷极目外。近处柳条摇曳，就在眼前。
LONG );
	set("exits", ([
		"down"     : __DIR__"yunjin1",
	]));
	set("objects", ([
		"/d/dali/obj/chahua12" :1,
	]));
	set("coor/x", 1230);
	set("coor/y", -1260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}