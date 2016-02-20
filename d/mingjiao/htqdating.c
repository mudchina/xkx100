//htqdating.c
inherit ROOM;

void create()
{
	set("short", "厚土旗大厅");
	set("long", @LONG
这里是厚土旗的大厅，厅中刀枪如林，黄旗招展，教众穿着铁甲钢
盔，腰间别着锹铲锤钻，一个个精神抖擞。正中端坐着个矮墩汉子，就
是厚土旗掌旗使颜垣。
LONG);
	set("exits", ([
		"out" : __DIR__"htqmen",
	]));
	set("objects", ([
		__DIR__"npc/yanyuan": 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 930);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}