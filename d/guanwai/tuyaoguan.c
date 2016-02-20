// /guanwai/tuyaoguan.c

inherit ROOM;

void create()
{
	set("short", "土窑馆");
	set("long", @LONG
一迈进这间小房，一股脂粉混合着大蒜的味道扑鼻而来，差点把你
呛了一个跟头。屋内点着很多蜡烛和灯笼，把四壁照得通红。很多穿着
破烂的汉子，一手搂着姑娘，一个握着酒壶，正在高谈阔论。一个肥胖
的老鸦一遍招待着客人，一遍大声催促的这里的伴当和姑娘们。
LONG );
	set("exits", ([
		"north" : __DIR__"dongcheng",
	]));
	set("objects", ([
		__DIR__"npc/jiaowenqi" : 1,
	]));
	set("coor/x", 6050);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}