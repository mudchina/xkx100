// Room: /d/qilian/niaojutai.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "鸟居台");
	set("long", @LONG
沿着大通岭往上走，道路愈显艰难。沿途荆棘丛生，怪石嶙嶙，眼
见已是兽迹罕至了，却有百鸟群飞，两耳只闻啾啾之声。仰头望天，一
片碧蓝之下，耳畔鸟鸣，苍苍大地，尽在脚下，不禁豪情顿生。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"eastdown" : __DIR__"datongling",
		"northup"  : __DIR__"mazongshan",
		"northwest": __DIR__"qilianshan",
	]));
	set("objects", ([
		"/d/hangzhou/npc/wuya"  : random(3),
		"/d/hangzhou/npc/maque" : random(3),
	]));
	set("coor/x", -11000);
	set("coor/y", 3000);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}