// Room: /d/taohua/woshi2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "清音居");
	set("long", @LONG
这间布置得很整齐的卧室是桃花岛主黄药师的居所。屋子正中放着
一座古琴，样式很是古老。东边的书架上密密层层的线装古籍，一尘不
染。朝南窗外露着两枝桃花，给屋子添了几许韵味。窗下小竹几上摆着
一副棋局，黑白分明。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"neishi2",
	]));
	set("coor/x", 9010);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}