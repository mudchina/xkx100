// Room: /d/huangshan/shanmen.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "黄山山门");
	set("long", @LONG
这是一座石雕门坊，过了山门后，便是黄山，这里地属丘陵，古代
称为黔山，因山色黝黑，远望如黛得名，后因唐明皇听信“黄帝在此飞
升”，所以改为黄山。连绵百里，群峰无数，引来无数游人。过山门后，
便是温泉。
LONG
	);
	set("exits", ([ 
		"northup"   : __DIR__"wenquan", 
		"southwest" : "/d/henshan/hsroad2",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
