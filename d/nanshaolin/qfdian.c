// Room: /d/nanshaolin/qfdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "千佛殿");
	set("long", @LONG
这是千佛殿。大殿入口是朱红格扇，七宝玲珑。内里供奉的西天诸
佛，计有八菩萨，四金刚，五百阿罗，三千揭谛，十一大曜，十八伽蓝，
以及众优婆塞，优婆夷等。直看得你眼花缭乱。佛像后边有道小木门直
通后山。
LONG );
	set("exits", ([
		"south" : __DIR__"kchang",
		"north" : __DIR__"shanroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

