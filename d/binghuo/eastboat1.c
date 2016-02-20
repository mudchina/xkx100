// Room: /binghuo/eastboat1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "东海海面");
	set("long", @LONG
东海海面波平如镜，大船在海鸥游鱼中穿行，风带风帆，你也不
知道船往哪里去。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

