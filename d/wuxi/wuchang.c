// Room: /d/wuxi/wuguan.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
走进来是一个很大的练武场，四下里铺着细沙、黄土、煤渣的混合
土，踩在上面显得十分地踏实。几个新进来的弟子正在秦教头的指点下
一招一式地练习。两边的兵器架上放着各种木制的兵器。向里去就是秦
教头的卧室了。虽然秦教头为人比较随和，但是你要是非得进去乱看的
话也是很不礼貌的。
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"west" : __DIR__"wuguan",
		"east" : __DIR__"wuguanwoshi",
	]));
	set("objects", ([
		__DIR__"npc/qin" : 1,
	]));
	set("coor/x", 390);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}