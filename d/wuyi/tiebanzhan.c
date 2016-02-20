// Room: /d/wuyi/tiebanzhang.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "铁板嶂");
	set("long", @LONG
铁板嶂因石崖峻峭、色如铁板而得名。所有三十六峰，惟独此峰因
身处大王峰和玉女峰之间，由大王和玉女传说而身背骂名。人们都把它
看做是破坏大王玉女婚姻的罪人。此峰崖峭层叠、曲水倒映、沟壑纵横、
石径曲折、修竹繁茂、意境幽雅。其下有儒巾石和“千崖万壑”题刻。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"2qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

