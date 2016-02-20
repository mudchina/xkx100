// Room: /heizhao/shanlu9.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
又行了一阵，正觉唇干口渴，忽听远处传来隐隐水声，你当即
加快脚步。空山寂寂，那水声在山谷间激荡回响，轰轰汹汹，愈走
水声愈大，待得走上岭顶，只见一道白龙似的大瀑布从对面双峰之
间奔腾而下，声势甚是惊人。从岭上望下去，瀑布旁有一间草屋。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"pubu",
		"eastdown"  : __DIR__"shanlu8",
	]));
	set("coor/x", -5020);
	set("coor/y", -1290);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}