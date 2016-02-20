// Room: /binghuo/jiangmian2.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "钱塘江面");
	set("long", @LONG
江船穿波越浪下驶。半个多时辰之后，上涌的潮水反退出海，顺
风顺水，舟行更远。远远望见钱塘江口的东海之中，有个荒凉小岛，
山石嶙峋，向无人居。那就是王盘山岛。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

