// /guanwai/xiaoxiang.c

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
这是一个僻静幽深的小巷，四周寂静无声，一个人影也没有。长长
的石板路上落了一层厚厚的积雪，踩在脚下发出“咯吱”的响声。小巷
的尽头有一座土屋。
LONG );
	set("exits", ([
		"south" : __DIR__"tuwu",
		"east"  : __DIR__"beicheng",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6030);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}