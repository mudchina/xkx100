// Room: /d/suzhou/lixuetang.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "立雪堂");
	set("long", @LONG
立雪堂名自“程门立雪”和“断臂立雪”之典。堂前小院中的湖石、
形似牛、蟹、狮、蛙，谓“狮子静观牛吃蟹”，颇生动有趣。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"wenmeige",
	]));
	set("coor/x", 890);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

