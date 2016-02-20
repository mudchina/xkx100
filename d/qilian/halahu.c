// Room: /d/qilian/hamahu.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "哈拉湖");
	set("long", @LONG
郁水过玉门关向东，北去二百里，汇之为泽，名哈拉。传说有恶蛟
藏在里面，每年春秋两季，以肥牛羊十头祭典才能平安，不然会淫雨连
绵达月余。这里是方圆八百里唯一的水源。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"yumen",
		"west"   : __DIR__"yumenguan",
	]));
	set("coor/x", -17000);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}