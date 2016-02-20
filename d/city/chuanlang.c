// Room: /yangzhou/chuanlang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "穿廊");
	set("long", @LONG
左右院内略略有几点山石，山下为洞室，山前有池水。隔水望去，
有一种无限幽深的感觉。池水深莫可测，偶然有鱼来游，倏忽而没。穿
廊上吊着一些个笼子，笼着各色禽鸟。穿廊的西壁，嵌有《颜鲁公三表
》，随读随行，碑尽而身转，只见尽头有厅，颜以额「梅船轩」。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"south" : __DIR__"menting",
		"north" : __DIR__"meichuanxuan",
	]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -11);
	set("coor/y", -49);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}