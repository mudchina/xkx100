// /guanwai/songhuajiang.c

inherit ROOM;

void create()
{
	set("short", "松花江面");
	set("long", @LONG
这里是松花江的江面，冰面早已解冻，清澈的江水涛涛北去，两岸
是如烟如雾松支，柳条。船夫悠闲地在船尾把着舵。
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6090);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}