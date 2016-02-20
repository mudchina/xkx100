// Room: /heizhao/pubu.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "瀑布");
	set("long", @LONG
你快步走近瀑布，只见柳树下那人头戴斗笠，身披蓑衣，坐在
一块石上，正自垂钓。这瀑布水势湍急异常，一泻如注，水中哪里
有鱼？纵然有鱼，又哪有余暇吞饵？看那人时，见他双目一动不动
的凝视水中。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("resource/water", 1);
	set("objects", ([
		CLASS_D("dali")+"/yideng/yu" : 1,
	]));
	set("exits", ([
		"southup" : __DIR__"shanlu9",
		"enter"   : __DIR__"xiaowu",
	]));
	set("coor/x", -5020);
	set("coor/y", -1280);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}