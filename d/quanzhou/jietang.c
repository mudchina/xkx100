// Room: /d/quanzhou/jietang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "甘露戒坛");
	set("long", @LONG
从大殿后门出来，便是重檐八角攒尖式的戒坛，是佛教徒受戒剃度
之处。坛分五级，最高层中奉木雕的卢舍那坐佛，所祀佛像还有释加牟
尼佛、阿弥陀佛、千手千眼观音佛等。坛座环列「护三皈」和「护五戒
」诸神神主牌位六十四座，气氛庄严。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south"   : __DIR__"yuetai",
		"northup" : __DIR__"cangjingge",
	]));
	set("coor/x", 1830);
	set("coor/y", -6480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
