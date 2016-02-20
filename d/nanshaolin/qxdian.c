// Room: /d/nanshaolin/qxdian.c 清心殿
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"清心殿"NOR);
	set("long",@long
这里是一座空旷的大佛殿，里面供奉着几尊佛像，殿中摆放着几个
蒲团，殿的四周各装嵌着一排雕花木制长窗，阳光透过窗棂洒进大殿，
照的大殿一片金光。阵阵梵唱传来使你觉得清新寡欲，俗念全消。
long);
	set("exits",([
		"west" : __DIR__"dabeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


