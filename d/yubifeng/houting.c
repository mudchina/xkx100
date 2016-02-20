// /yubifeng/houting.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @long
这里是庄内人用饭休息的地方，四角各生着一盆大炭火，一张八仙
桌居中，周围打扫得甚是干净。管家正在和下人们吩咐着什么。
long );
	set("exits", ([
		"west"  : __DIR__"zoulang5",
		"east"  : __DIR__"zoulang6",
		"north" : __DIR__"houyuan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6120);
	set("coor/y", 5200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
