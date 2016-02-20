// /guanwai/tianchi2.c

inherit ROOM;

void create()
{
	set("short", "长白天池");
	set("long", @LONG
天池十天九雾，云蒸雾绕，变幻无穷。瞬息万变的雾霭风雨，使天
池时而清亮如蓝天明镜，时而缥缈如轻莹薄纱，时而腾跃如大海波涛，
景色大观令人神往。
LONG );
	set("exits", ([
		"north"    : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}