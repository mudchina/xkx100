// Room: /d/quanzhou/laojunyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "老君岩");
	set("long", @LONG
这里山不高而云雾缭绕，周围开旷辽阔，碧草如茵，风景宜人。因
有道教教主老君石像，故称老君岩。它是一天然巨石雕琢而成。天下老
君石像无大过斯者，故又号称“老子天下第一”。石像左手依膝，右手
凭几，两眼平视，双耳垂肩，脸含笑容，苍髯飞动，一幅老人慈祥，安
乐的神态。民俗云：「摸到老君鼻，吃到一百二」。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"qianshouyan",
		"eastup"    : __DIR__"nantaiyan",
	]));
	set("coor/x", 1820);
	set("coor/y", -6380);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
