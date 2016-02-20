// Room: /yangzhou/pingshanwu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","平山堂坞");
	set("long",@LONG
这里是平山堂坞。游西湖者，从天宁寺侧御码头下水，到此也得下
船了。当年乾隆，南巡也取此道。由此坞后山道拾阶而上，共得九十九
级，便到蜀冈山中峰的大明寺了。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"northup" : __DIR__"pailou",
		"south"   : __DIR__"changdi3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}