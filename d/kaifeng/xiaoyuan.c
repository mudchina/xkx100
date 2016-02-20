// /kaifeng/xiaoyuan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
你一脚踏进来，不由得喊了声好，只见修篁一片，间中是两棵佛祖
曾在其下悟道的菩提树。小路沿着修竹而弯，北面路的尽头就是方丈大
师傅的住所，也是他平常接待贵客的地方。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"fangzhang",
		"west" : __DIR__"cangjing1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
