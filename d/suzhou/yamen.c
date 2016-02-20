// Room: /d/suzhou/yamen.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "正堂");
	set("long", @LONG
这里就是苏州府衙。堂上东西有两根楹柱，挂着一幅对联，但是你
根本无心细看。正墙上悬挂一个横匾，上面横书“正大光明”四个金光
闪闪的大字。一长溜“肃静”“回避”的牌子分列两侧。知府正坐在文
案后批阅文书，师爷随侍在后。
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"neizhai",
		"south"  : __DIR__"yamengate",
		"east"   : __DIR__"dongting",
		"west"   : __DIR__"xiting",
	]));
	set("objects", ([
		__DIR__"npc/feng": 1,
		__DIR__"npc/shiye": 1,
		__DIR__"npc/yayi": 4,
	]));
	set("coor/x", 840);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
