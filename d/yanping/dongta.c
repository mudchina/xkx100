// Room: /d/yanping/dongta.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "东塔");
	set("long", @LONG
东塔竣于明万历三十五年六月，矗立于鲤鱼山顶，高九丈，同西塔
式样装饰完全一样，是七层八角实心青石塔。相传当时有妖作怪，毁宝
山，污灵水，有人便以妖怪怕火，正好建、西二溪在此交会如“人”字，
便建此双塔构筑成“火”字形，以火驱邪镇妖。
LONG );
	set("exits", ([
		"northdown" : __DIR__"liyuding",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
