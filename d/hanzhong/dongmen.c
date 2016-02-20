// dongmen.c 东门
// Winder Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
这里是汉中镇的东门，眼前城墙高耸，墙上的箭垛里好象还有
人走来走去。阳光照来，城墙上闪过几道白光，似乎是兵器反射出
的光。城门上题着‘东门’两个大字，门口站着一些官兵，正手持
兵刃盘问着来往的行人们。
LONG
	);
	set("outdoors", "hanzhong");
	set("exits", ([
		"east" : __DIR__"guandao2",
		"west" : __DIR__"dongjie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -3120);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
