// Room: /d/wuyi/yinpingfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "隐屏峰");
	set("long", @LONG
这里是隐屏峰北侧。岩壁上三个苍劲大字“仙凡界”，标示了天界
与人间的界定。由“步虚”二字处攀铁梯，饶“鸡胸”，便是“仙凡界”
了。沿石梯向上，过清代汪痴颐坐化的“痴颐窝”，盘上“龙脊”，直
达峰顶。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"westdown" : __DIR__"yunwo",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1370);
	set("coor/y", -5010);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

