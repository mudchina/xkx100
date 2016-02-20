// Room: /d/quanzhou/xita.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西塔");
	set("long", @LONG
西塔又名仁寿塔，它与东塔除局部略有区别外，建筑规则基本相同，
恰似一对挛生姊妹。西塔须弥座束腰部分则雕刻着各种花、鸟、虫、兽
和装饰图案，也都线条清晰，形态逼真，给人一种欣悦、舒畅的美感。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"yuetai",
	]));
	set("coor/x", 1820);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
