// Room: /d/nanshaolin/twdian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"天王殿"NOR);
	set("long", @LONG
这里是少林寺的中殿天王殿。殿内香烟燎绕，幔角叮咚。香火比前
殿要旺盛的多。正前方供着个大肚子，似乎永远都笑咪咪的弥勒佛。四
大天王分列两旁，分执“风调雨顺”。两侧香桌上摆满了四季果蔬，弥
勒的身后站立的是韦驮。只见他金盔金甲，年轻英俊，威风凛凛，双手
合十，金刚杵横放腕上。
LONG );

	set("exits", ([
		"south" : __DIR__"qdian",
		"north" : __DIR__"sblu-1",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangxian" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));

	set("coor/x", 1820);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

