// Room: /d/quanzhou/caoan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "草庵");
	set("long", @LONG
寺内有著名的摩尼石像。它面庞圆阔，眉弯隆起，散发披肩，身着
宽袍僧衣，双手掌心向上置于膝上，神态庄严，别具风采。庵前约四米
处，巨石鹘立，中刻明教咒语，劝念：『清净光明，大力智慧，无上至
真，摩尼光佛』。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"out"   : __DIR__"shangu",
	]));
	set("coor/x", 1820);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
